/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 22:13:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 19:36:56 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "maths/maths.h"

static void	sort(t_raycasting_scene *const self)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_sprite_entity	*next_sprite;

	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		if (pos == self->sprite_entities.list.next)
			printf("FIRST\n\n");
		printf("debut boucle\n");
		if (pos->next == &self->sprite_entities.list)
			break ;
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		next_sprite = (t_sprite_entity*)((t_entity_node*)pos->next)->entity;
		printf("avant le if\n");
		printf("perpd sprite = %f, perpd nextsprite = %f\n", sprite->perpendicular_distance, next_sprite->perpendicular_distance);
		if (sprite->perpendicular_distance
			< next_sprite->perpendicular_distance)
		{
			printf("avant le move\n");
			list_move(pos, pos->prev);
			printf("apres le move\n");
			pos = &self->sprite_entities.list;
			continue ;
		}
	}
}

static void	render_sprites(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_usize			i;
	t_ray			*zbuffer;
	t_usize			sprite_px;
	t_frame			*sprite_texture;

	zbuffer = (t_ray*)self->zbuffer.array;
	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		sprite_texture = &sprite->texture;
		if (!sprite->is_visible)
			continue ;
		i.x = (size_t)ft_ssmax(sprite->start_x, 0);
		while ((ssize_t)i.x < sprite->end_x && i.x < fb->size.x)
		{
			if (sprite->perpendicular_distance
				>= zbuffer[i.x].perpendicular_distance)
			{
				i.x++;
				continue ;
			}
			sprite_px.x = inverse_lerp(sprite->start_x, sprite->end_x, i.x)
				* sprite_texture->size.x;
			i.y = (size_t)ft_ssmax(sprite->start_y, 0);
			while ((ssize_t)i.y < sprite->end_y && i.y < fb->size.y)
			{
				sprite_px.y = inverse_lerp(sprite->start_y, sprite->end_y, i.y)
					* sprite_texture->size.y;
				t_rgba	sprite_color = sprite_texture->pixels[sprite_px.y
					* sprite_texture->size.x + sprite_px.x];
				if (!(sprite_color.c.r == 255
					&& sprite_color.c.g == 255
					&& sprite_color.c.b == 255))
				{
					sprite_color.c.r /= (sprite->perpendicular_distance / 3.0f) + 1;
					sprite_color.c.g /= (sprite->perpendicular_distance / 3.0f) + 1;
					sprite_color.c.b /= (sprite->perpendicular_distance / 3.0f) + 1;
					fb->pixels[i.y * fb->size.x + i.x] =
						blend_add(fb->pixels[i.y * fb->size.x + i.x],
						sprite_color);
				}
				i.y++;
			}
			i.x++;
		}
	}
}

static void	monsters_health(const t_monster_entity *const monster,
				t_frame *const fb)
{
	float	health_percentage;
	t_usize	health_bar_size;
	t_usize	i;

	health_percentage = monster->health / monster->full_health;
	health_bar_size.x = monster->super.end_x - monster->super.start_x;
	health_bar_size.y = health_bar_size.x / 20;
	i.y = 0;
	while (i.y < health_bar_size.y)
	{
		i.x = 0;
		while (i.x < health_bar_size.x)
		{
			if (!(monster->super.start_y + (ssize_t)i.y < 0
				|| monster->super.start_y + i.y >= fb->size.y
				|| monster->super.start_x + (ssize_t)i.x < 0
				|| monster->super.start_x + i.x >= fb->size.x))
			{
				if ((float)(i.x + i.y) / (float)health_bar_size.x > health_percentage)
					fb->pixels[(monster->super.start_y + i.y) * fb->size.x
						+ monster->super.start_x + i.x] = ft_rgba(0, 31, 0, 255);
				else
					fb->pixels[(monster->super.start_y + i.y) * fb->size.x
						+ monster->super.start_x + i.x] = ft_rgba(0, 255, 0, 255);
			}
			i.x++;
		}
		i.y++;
	}
}

static void	monsters(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_list_head			*pos;
	t_monster_entity	*monster;
	t_u8				distance_opacity;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (monster->super.perpendicular_distance > 10.0f
			|| !monster->super.is_visible)
			continue ;
		distance_opacity = inverse_lerp(10.0f, 0.0f,
			monster->super.perpendicular_distance) * 255;
		frame_layer_transform_add(fb,
			&monster->name_text.target,
			ft_frame_transform(ft_vec2f(0.5f, 1.0f),
				ft_isize((monster->super.start_x + monster->super.end_x) / 2,
					monster->super.start_y),
				ft_vec2f(10.0f / monster->super.perpendicular_distance,
					10.0f / monster->super.perpendicular_distance),
				distance_opacity));
		if (monster->health < monster->full_health)
			monsters_health(monster, fb);
	}
}

void		raycasting_scene_render_sprites(t_raycasting_scene *const self,
				t_frame *const fb)
{
	printf("avant sort\n");
	sort(self);
	printf("avant render\n");
	render_sprites(self, fb);	
	printf("avant monster\n");
	monsters(self, fb);
	printf("apres monster\n");
}
