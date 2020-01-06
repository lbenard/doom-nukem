/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:00:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 22:25:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

#include "libft.h"

typedef	enum	e_dnon_value_type
{
	LIST,
	STRING,
	NUMBER, 
	UNKNOW
}				t_dnon_value_type;

typedef struct	s_dnon_object
{
	t_list_head					node;
	char						*key;
	t_dnon_value_type			type;
	void						*value;
}				t_dnon_object;

/*
**	parsing
*/
t_result		parse_map_file(char *path);
t_result		to_object(char *data, t_dnon_object *parent);

/*
**	read file
*/
char			*get_file_datas(char *path);

/*
**	check data
*/
t_result		check_data_format(char *data);
t_result		check_curly_braces(char *data);
t_result		check_open_curly_brace_left_side(char *data, size_t index);
t_result		check_open_curly_brace_right_side(char *data, size_t index);
t_result		check_close_curly_brace_left_side(char *data, size_t index);
t_result		check_close_curly_brace_right_side(char *data, size_t index);
t_bool			is_index_match_to_object_key(char *data, size_t index);

/*
**	split data
*/
char			**split_by_entry(char *data);
char			**new_string_array(size_t size);
void			free_string_array(char **datas);

/*
**	get data
*/
char			*get_key_offset(char *data);
char			*get_object_key(char *data);
char			*get_value_offset(char *data);
void			*get_object_value(char *data, t_dnon_value_type type);
int				get_object_value_type(char *data);

/*
**	object creation
*/
t_dnon_object	*new_dnon_object();
t_dnon_object	*create_dnon_object(char *key, t_dnon_value_type type);
t_dnon_object	*create_dnon_object_with_data(char *data);

/*
**	object free
*/
void			free_object(t_dnon_object *obj);

/*
**	getters
*/
int				get_int_value_by_key(t_dnon_object *tree,
					char *key,
					int by_default);
float			get_float_value_by_key(t_dnon_object *tree,
					char *key,
					float by_default);
char			*get_string_value_by_key(t_dnon_object *tree,
					char *key,
					char *by_default);
t_dnon_object	*get_child_list_object_by_key(t_dnon_object *tree, char *key);
t_dnon_object	*get_child_object_by_key(t_dnon_object *tree, char *key);


/*
**	debug
*/
void			debug_object(t_dnon_object *obj);
void			debug_split(char **datas);

#endif