/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:18:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:03:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>
# include "types.h"

/*
** Doom Nukem data file parsing utilities
*/
char		*dn_read_file(const char *path);

t_result	dn_is_flag_correct(char *line);
t_result	dn_is_kv_correct(char *line, char end);
t_result	dn_is_line_correct(char *line);

char		*dn_new_flag(char *flag_name);
char		*dn_select_flag(char *map_str, char *flag_name);

char		*dn_get_key(char *dn_data_line);

char		*dn_get_value(char *dn_data_line);
char		**dn_get_values(char *dn_data_line, char split);
void		dn_free_values(char **values);

size_t		dn_strsplit_length(char **strings);

#endif
