/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:53:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/04 22:55:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLER_H
# define EVENT_HANDLER_H

# include "containers/module.h"
# include "containers/list.h"
# include <SFML/Window.h>

/*
** Event node
*/
typedef struct	s_callback_node
{
	t_list_head	node;
	void		(*callback)();
	void		*params;
}				t_callback_node;

t_callback_node	*new_callback_node(void (*callback)(), void *params);
void			free_callback_node(t_callback_node *self);

/*
** Callbacks list for each event handler
*/
typedef struct	s_event_handler
{
	t_module	module;
	t_list_head	node;
	t_list_head	childs;
	void*const	object;
	t_list_head	callbacks;
}				t_event_handler;

typedef struct	s_event_handler_args
{
	void	*object;
}				t_event_handler_args;

t_constructor	event_handler(void *const object);

t_result		init_event_handler(t_event_handler *const self,
					const t_event_handler_args *const args);

t_result		event_handler_add_callback(t_event_handler *const self,
					t_callback_node *const callback);
void			event_handler_add_sub_handler(
					t_event_handler *const self,
					t_event_handler *const sub_handler);
void			event_handler_remove_sub_handler(
					t_event_handler *const self,
					t_event_handler *const sub_handler);
void			event_handler_call(t_event_handler *const self,
					sfEvent *const event);

void			destroy_event_handler(t_event_handler *const self);

#endif
