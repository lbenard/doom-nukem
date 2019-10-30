/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:07:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:41:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "engine/module.h"

typedef struct		s_string
{
	t_module	module;
	char		*str;
}					t_string;

typedef struct		s_string_args
{
	const char	*str;
}					t_string_args;

t_smodule_factory	string(const char *const str);

t_result			init_string(t_string *const self,
						const t_string_args *const args);
t_result			string_set(t_string *const self, const char *const str);
void				destroy_string(t_string *const self);

#endif