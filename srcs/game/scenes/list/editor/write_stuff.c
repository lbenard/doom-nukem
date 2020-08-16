/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 00:07:51 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/17 00:13:22 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "game/scenes/editor_scene.h"
#include "game/entities/editor/entity_component_entity.h"
#include "ft/io.h"
#include "engine/error.h"

t_result	write_map_size(const int fd, const t_usize size)
{
	errno = 0;
	ft_putstr_fd("-size\n", fd);
	ft_putstr_fd("height: ", fd);
	ft_putnbr_fd((int)size.y, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("width: ", fd);
	ft_putnbr_fd((int)size.x, fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_size()"));
	return (OK);
}

t_result	write_player_spawn(const int fd,
					const t_player_component_entity *const player,
					const t_isize origin)
{
	errno = 0;
	ft_putstr_fd("-player\n", fd);
	ft_putstr_fd("spawn: ", fd);
	ft_putfloat_fd(player->super.super.transform.position.x - origin.x, fd);
	ft_putchar_fd(' ', fd);
	ft_putfloat_fd(player->super.super.transform.position.y - origin.y, fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_size()"));
	return (OK);
}

t_result	write_entities(t_editor_scene *const self,
					const int fd,
					const t_isize origin)
{
	t_list_head					*pos;
	t_entity_component_entity	*entity;

	errno = 0;
	pos = &self->entities.list;
	ft_putstr_fd("-entities\n", fd);
	while ((pos = pos->next) != &self->entities.list)
	{
		entity = (t_entity_component_entity*)((t_entity_node*)pos)->entity;
		ft_putstr_fd(entity->entity->name, fd);
		ft_putstr_fd(": ", fd);
		ft_putfloat_fd(entity->super.super.transform.position.x
			- (float)origin.x, fd);
		ft_putchar_fd(' ', fd);
		ft_putfloat_fd(entity->super.super.transform.position.y
			- (float)origin.y, fd);
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_size()"));
	return (OK);
}
