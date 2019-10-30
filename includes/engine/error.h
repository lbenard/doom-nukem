/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:30:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 11:59:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "types.h"

# define PROGRAM_NAME "Doom Nukem"

/*
** Error handling and stack trace
*/
void		*throw_error(const char *const fn);
void		*throw_error_str(const char *const fn, const char *const cause);
t_result	throw_result(const char *const fn);
t_result	throw_result_str(const char *const fn, const char *const cause);
void		*throw_error_errno(const char *const fn, const int err);

#endif
