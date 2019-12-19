/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:04:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/09 13:38:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"

t_result	text_set(t_text *const self, const t_string string)
{
	destroy_string(&self->text);
	self->text = string;
	return (OK);
}