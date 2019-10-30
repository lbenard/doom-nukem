/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:39:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/28 17:01:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "engine/module.h"
# include "engine/event_handler.h"
# include "containers/vector.h"

typedef enum		e_input
{
	KEY,
	MOUSE,
	BUTTON,
	STICK
}					t_input;

# define INVERT_INPUT (1 << 0)
# define KEY_HOLD (1 << 1)
# define MOUSE_HOLD (1 << 2)
# define STICK_NEGATIVE (1 << 3)
# define STICK_POSITIVE (1 << 4)

typedef struct		s_input_type
{
	size_t				id;
	int					code;
	t_input				type;
	t_bool				invert;
	struct s_key
	{
		t_bool	hold;
	}					key;
	struct s_mouse
	{
		t_bool	hold;
	}					mouse;
	struct s_button
	{
		int	joystick;
	}					button;
	struct s_stick
	{
		int		joystick;
		float	dead_zone;
		t_bool	negative;
		t_bool	positive
	}					stick;
}					t_input_type;

t_input_type		ft_key_input(int input, int flags);
t_input_type		ft_mouse_input(int input, int flags);
t_input_type		ft_stick_input(int joystick,
						int stick,
						float dead_zone,
						int flags);
t_input_type		ft_button_input(int joystick,
						int button,
						int flags);

typedef struct		s_input_set
{
	const char	*key;
	size_t		id;
	float		value;
}					t_input_set;

t_input_set			ft_input_set(const char *const key, const size_t id);
size_t				input_set_get_uid(void);

typedef struct		s_input
{
	t_module		module;
	t_event_handler	handler;
	t_vector		table;
	t_vector		events;
}					t_input;

t_smodule_factory	input(void);

t_result			init_input(t_input *const self);

size_t				input_register(t_input *const self, const char *const name);
size_t				input_get_id(t_input *const self, const char *const name);
void				input_attach(t_input *const self,
						size_t id,
						t_input_type type);
float				input_get(t_input *const self, size_t id);
void				input_update(t_input *const self);

void				destroy_input(t_input *const self);

#endif