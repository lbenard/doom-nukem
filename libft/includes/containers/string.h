/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:17:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/20 20:11:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "containers/module.h"

typedef struct	s_string
{
	char	*str;
	size_t	len;
}				t_string;

typedef struct	s_string_ref
{
	const char	*str;
	size_t		len;
}				t_string_ref;

typedef struct	s_string_args
{
	const char		*str;
	t_string_ref	string_ref;
}				t_string_args;

t_constructor	string(const char *const str);
t_constructor	string_clone(const t_string_ref ref);

t_result		init_string(t_string *const self,
					const t_string_args *const args);
t_result		init_string_clone(t_string *const self,
					const t_string_args *const args);

t_result		string_set(t_string *const self, const char *const str);
t_result		string_dup(t_string *const self, const t_string_ref str);
t_string_ref	string_as_ref(t_string *const self);

void			destroy_string(t_string *const self);

typedef struct	s_static_string
{
	const char	*str;
	size_t		len;
}				t_static_string;

typedef struct	s_static_string_args
{
	const char *str;
}				t_static_string_args;

t_static_string	ft_static_string(const char *const str);
t_string_ref	static_string_as_ref(t_static_string self);

#endif