/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/08 20:26:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

t_result	parse_map_file(char *path)
{
	char			*data;
	t_dnon_object	*obj;

	if (!(data = get_file_datas(path)))
		return (throw_result_str("parse_map_file", "failed to get datas"));
	if (!check_curly_braces(data))
		return (throw_result_str("parse_map_file", "error around curly braces"));
	obj = create_dnon_object(ft_strdup("root"), LIST);
	to_object(data, obj);
	// obj = get_child_object_by_key(obj, "player");
	// if (obj)
	// {
	debug_object(obj);
	// 	// printf("%s\n", get_string_value_by_key(obj, "1", "default"));
	// 	printf("%d\n", get_int_value_by_key(obj, "direction", 42));
	// }
	// else
	// 	printf("doesn't find child with this key\n");
	free_object(obj);
	return (OK);
}