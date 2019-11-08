/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:07:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:38:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "containers/module.h"

typedef struct	s_string
{
	char		*str;
}				t_string;

typedef struct	s_string_args
{
	const char	*str;
}				t_string_args;

t_constructor	string(const char *const str);

t_result		init_string(t_string *const self,
					const t_string_args *const args);
t_result		string_set(t_string *const self, const char *const str);
void			destroy_string(t_string *const self);

#endif