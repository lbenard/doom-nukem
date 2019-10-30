/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:36:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:21:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "containers/list.h"
#include <stdlib.h>
#include <unistd.h>

static void	read_line(t_fd *fd, char (*buffer)[BUFF_SIZE + 1],
	char **line, char **chr)
{
	size_t	read_size;
	char	*tmp;

	while (!(*chr = ft_strchr((char*)*line, '\n')))
	{
		if ((read_size = read(fd->fd, *buffer, BUFF_SIZE)) == 0)
			return ;
		(*buffer)[read_size] = 0;
		tmp = *line;
		*line = ft_strjoin(*line, *buffer);
		free(tmp);
		if (*line == NULL)
			return ;
	}
}

static int	get_line(t_fd *fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*chr;

	*line = ft_strdup(fd->buffer);
	buffer[0] = 0;
	read_line(fd, &buffer, line, &chr);
	if (*line == NULL)
		return (READ_ERROR);
	if (ft_strlen(buffer) == 0 && ft_strlen(*line) == 0)
	{
		free(*line);
		return (READ_FINISH);
	}
	if (chr)
	{
		ft_strcpy(fd->buffer, &chr[1]);
		chr[0] = 0;
	}
	else
		fd->buffer[0] = 0;
	return (LINE_READ);
}

int			ft_get_next_line(const int fd, char **line)
{
	static t_list	*fd_list = NULL;
	t_list			*find;
	t_fd			new_fd;
	int				retval;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (READ_ERROR);
	new_fd.fd = fd;
	new_fd.buffer[0] = 0;
	if (!fd_list)
	{
		if (!(fd_list = new_lstcpy(&new_fd, sizeof(t_fd))))
			return (READ_ERROR);
		find = fd_list;
	}
	else if (!(find = lst_content_find(fd_list, &fd, sizeof(int))))
	{
		if (!(find = new_lst(&new_fd, sizeof(t_fd))))
			return (READ_ERROR);
		lst_add(&fd_list, find);
	}
	if ((retval = get_line(find->content, line)) == 0)
		lst_remove(&fd_list, find);
	return (retval);
}
