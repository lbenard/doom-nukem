/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:26:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/09 01:01:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

static char	*add_newline(char *text)
{
	char	*tmp;

	if (text)
	{
		tmp = text;
		text = ft_strjoin(text, "\n");
		free(tmp);
		return (text);
	}
	else
		return (NULL);
}

static char	*join_next_line(char *text, char *next_line)
{
	char	*tmp;

	if (text && next_line)
	{
		tmp = text;
		text = ft_strjoin(text, next_line);
		free(tmp);
		free(next_line);
		return (text);
	}
	else
	{
		free(text);
		free(next_line);
		return (NULL);
	}
}

static void	*dn_read_handle_error(int file_descriptor)
{
	close(file_descriptor);
	return (throw_error_str("dn_read_file()", "failed to create map string"));
}

char		*dn_read_file(const char *path)
{
	int		file_descriptor;
	char	*map_str;
	char	*line;

	if ((file_descriptor = open(path, O_RDONLY)) <= 0)
		return (throw_error_str("dn_read_file()", "failed to open file"));
	if (!(map_str = ft_strdup("\n")))
		return (dn_read_handle_error(file_descriptor));
	while (ft_get_next_line(file_descriptor, &line))
	{
		if (!line || !dn_is_line_correct(line))
		{
			free(map_str);
			free(line);
			close(file_descriptor);
			return (throw_error_str("dn_read_file()", "failed to read line"));
		}
		if (!(map_str = join_next_line(map_str, add_newline(line))))
		{
			close(file_descriptor);
			return (throw_error_str("dn_read_file()", "map syntax error"));
		}
	}
	close(file_descriptor);
	return (map_str);
}
