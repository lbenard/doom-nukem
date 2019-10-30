/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:29:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/07 17:28:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <string.h>
# include "types.h"

/*
** Linux-like doubly linked list
*/
typedef struct	s_list_head
{
	struct s_list_head	*prev;
	struct s_list_head	*next;
}				t_list_head;

/*
** Constructors
*/
t_result		init_list_head(t_list_head *list);

/*
** Iterators
*/
void			list_foreach(t_list_head *list, size_t offset, void (*fn)());

/*
** Capacity
*/
t_bool			list_is_last(const t_list_head *list, const t_list_head *head);
t_bool			list_is_empty(const t_list_head *head);
size_t			list_size(const t_list_head *head);

/*
** Modifiers
*/
void			list_add(t_list_head *new, t_list_head *prev,
	t_list_head *next);
void			list_add_entry(t_list_head *new, t_list_head *head);
void			list_add_tail(t_list_head *new, t_list_head *head);
void			list_del(t_list_head *prev, t_list_head *next);
void			list_del_entry(t_list_head *entry);
void			list_move(t_list_head *list, t_list_head *head);
void			list_move_tail(t_list_head *list, t_list_head *head);

/*
** libft linked lists
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Constructors
*/
t_list			*new_lst(void *content, size_t content_size);
t_list			*new_lstcpy(const void *content, size_t content_size);
t_list			*new_lstmap(t_list *lst, t_list *(*f)(t_list*));

/*
** Iterators
*/
void			lst_iter(t_list *lst, void (*f)(t_list*));
t_list			*lst_last(const t_list *list);
t_list			*lst_find(const t_list *lst, const void *to_find,
	int (*cmp)(const void*, const void*));
t_list			*lst_content_find(const t_list *lst, const void *to_find,
	size_t to_find_size);

/*
** Modifiers
*/
void			lst_add(t_list **alst, t_list *new);
t_list			*lst_push_back(t_list **list, t_list *new);
void			lst_del_one(t_list **alst, void (*del)(void*, size_t));
void			lst_del(t_list **alst, void (*del)(void*, size_t));
void			lst_remove(t_list **list, t_list *to_remove);

/*
** Casts
*/
char			*lst_strjoin(const t_list *lst, const char *separator);

/*
** Destructors
*/
void			free_lst(t_list *list);

#endif
