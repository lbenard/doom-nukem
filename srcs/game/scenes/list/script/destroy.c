/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:37:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/05 23:54:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/script_scene.h"
#include "game/game.h"

void	destroy_script_scene(t_script_scene *const self)
{
	cursor_set_visibility(&self->window->cursor, TRUE);
	free(self->writing_paragraph1);
	free(self->writing_paragraph2);
	destroy_scene(&self->super);
}
