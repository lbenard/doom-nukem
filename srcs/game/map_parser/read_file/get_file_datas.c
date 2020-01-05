/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_datas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:51:48 by ppetitea          #+#    #+#             */
/*   Updated: 2019/12/25 12:52:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "engine/error.h"

char	*update_data_with_buffer(char *datas, char *buf)
{
	char	*ret;

	if (datas == NULL)
		return (ft_strdup(buf));
	ret = ft_strjoin(datas, buf);
	free(datas);
	return (ret);
}

char		*get_file_datas(char *path)
{
	int		fd;
	size_t	buf_size;
	ssize_t	read_len;
	char	*buf;
	char	*datas;

	datas = NULL;
	buf_size = 2048;
	if ((fd = open(path, O_RDONLY)) <= 2)
		return (throw_error_str("parse_map_file()", "open failed"));
	if (!(buf = (char*)malloc(sizeof(char) * (buf_size + 1))))
		return (throw_error_str("parse_map_file()", "malloc failed"));
	while ((read_len = read(fd, buf, buf_size)) > 0)
	{
		buf[read_len] = '\0';
		if (!(datas = update_data_with_buffer(datas, buf)))
			break ;
	}
	free(buf);
	return (datas);
}