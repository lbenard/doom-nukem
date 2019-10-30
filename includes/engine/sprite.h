/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:58:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <SFML/Graphics.h>
# include "engine/module.h"

typedef sfSprite		t_sprite;

t_hmodule_factory	sprite(void);

#endif
