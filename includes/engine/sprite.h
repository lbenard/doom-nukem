/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:58:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:12:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <SFML/Graphics.h>
# include "containers/module.h"

typedef struct	s_sprite
{
	sfSprite	*sprite;
}				t_sprite;

t_constructor	sprite(void);

t_result		init_sprite(t_sprite *const self);
void			destroy_sprite(t_sprite *const self);

#endif
