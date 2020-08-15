/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:18:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 16:35:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/checkbox_entity.h"
#include "engine/error.h"
#include "ft/str.h"

static char	*create_path(const char *const path,
				const char *const name,
				const char *const suffix)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(path) + ft_strlen(name)
		+ ft_strlen(suffix))))
		return (NULL);
	ft_strcpy(str, path);
	ft_strncat(str, name, ft_strchr(name, '.') - name);
	ft_strcat(str, suffix);
	ft_strcat(str, ft_strchr(name, '.'));
	return (str);
}

t_result	init_checkbox_entity_base(t_checkbox_entity *const self,
				const t_checkbox_entity_args *const args)
{
	const char	*path;
	char		*normal;
	char		*hover;
	char		*checked;
	t_result	res;

	path = "resources/buttons/";
	normal = create_path(path, args->base_name, "");
	hover = create_path(path, args->base_name, "-hover");
	checked = create_path(path, args->base_name, "-click");
	if (!(normal && hover && checked))
	{
		free(normal);
		free(hover);
		free(checked);
		return (throw_result_str("init_checkbox_entity_base()",
			"failed to create paths"));
	}
	res = static_module_create(self, checkbox_entity(normal, hover, checked,
		args->window));
	free(normal);
	free(hover);
	free(checked);
	if (res == ERROR)
	{
		return (throw_result_str("init_checkbox_entity_base()",
			"failed to init checkbox entity base"));
	}
	return (OK);
}
