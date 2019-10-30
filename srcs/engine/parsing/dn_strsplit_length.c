/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_strsplit_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:35:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:03:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"

size_t	dn_strsplit_length(char **strings)
{
	size_t	length;

	length = 0;
	while (strings && strings[length])
		length++;
	return (length);
}
