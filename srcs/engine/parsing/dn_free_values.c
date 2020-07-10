/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_free_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:18:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/09 01:13:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "engine/parsing.h"

void	dn_free_values(char **values)
{
	size_t	i;

	i = 0;
	while (values && values[i])
		free(values[i++]);
	free(values);
}
