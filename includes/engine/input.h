/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:39:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 00:43:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# ifndef __APPLE__
#  define STICK_COMPATIBILITY 1
# else
#  define STICK_COMPATIBILITY 0
# endif

# include "containers/module.h"
# include "engine/event_handler.h"
# include "containers/vector.h"

typedef enum		e_input_type
{
	KEY,
	MOUSE,
	BUTTON,
	STICK
}					t_input_type;

# define INPUT_NO_FLAG 0x00000
# define INVERT_INPUT 0x00001
# define KEY_HOLD 0x00010
# define MOUSE_HOLD 0x00100
# define STICK_NEGATIVE 0x01000
# define STICK_POSITIVE 0x10000

typedef size_t		t_input_id;
# define INPUT_NULL_ID 0

typedef struct		s_input_event
{
	t_input_id		id;
	int				code;
	t_input_type	type;
	t_bool			invert;
	struct			s_key
	{
		t_bool	hold;
	}				key;
	struct			s_mouse
	{
		t_bool	hold;
	}				mouse;
	struct			s_button
	{
		int	joystick;
	}				button;
	struct			s_stick
	{
		int		joystick;
		float	dead_zone;
		t_bool	negative;
		t_bool	positive;
	}				stick;
}					t_input_event;

t_input_event		ft_key_event(int input, int flags);
t_input_event		ft_mouse_event(int input, int flags);
t_input_event		ft_stick_event(int joystick,
						int stick,
						float dead_zone,
						int flags);
t_input_event		ft_button_event(int joystick,
						int button,
						int flags);

typedef struct		s_input_set
{
	const char	*key;
	t_input_id	id;
	float		value;
}					t_input_set;

t_input_set			ft_input_set(const char *const key, const t_input_id id);
t_input_id			input_set_get_uid(void);

typedef struct		s_input
{
	t_module		module;
	t_event_handler	handler;
	t_vector		table;
	t_vector		events;
}					t_input;

t_constructor		input(void);

t_result			init_input(t_input *const self);

t_input_id			input_register(t_input *const self, const char *const key);
t_input_id			input_get_id(t_input *const self, const char *const key);
void				input_attach(t_input *const self,
						const t_input_id id,
						t_input_event type);
float				input_get(t_input *const self, const t_input_id id);
void				input_update(t_input *const self);

void				destroy_input(t_input *const self);

#endif
