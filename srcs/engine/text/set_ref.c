/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ref.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:05:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/12 13:31:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"
#include "engine/error.h"

t_result	text_set_ref(t_text *const self, const t_string_ref ref)
{
	if (string_dup(&self->text, ref) == ERROR)
	{
		self->module.has_error = TRUE;
		return (throw_result_str("text_set_ref()",
			"failed to duplicate reference string"));
	}
	return (OK);
}