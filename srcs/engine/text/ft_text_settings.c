/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/12 13:15:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"

t_text_settings	ft_text_settings(const t_isize position,
					const size_t height,
					const t_usize spacing)
{
	t_text_settings	settings;

	settings.position = position;
	settings.height = height;
	settings.spacing = spacing;
	return (settings);
}