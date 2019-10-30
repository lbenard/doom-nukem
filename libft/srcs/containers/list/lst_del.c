/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:50:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:06:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/list.h"

void	lst_del(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst && del)
	{
		if ((*alst)->next)
			lst_del(&(*alst)->next, del);
		lst_del_one(alst, del);
	}
}
