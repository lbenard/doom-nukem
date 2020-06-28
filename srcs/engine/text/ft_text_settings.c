/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:27:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"

t_text_settings	ft_text_settings(const t_isize position,
					const size_t height)
{
	t_text_settings	settings;

	settings.position = position;
	settings.height = height;
	return (settings);
}
