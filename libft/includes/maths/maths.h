/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:47:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:55:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <string.h>

# define PI 3.14159265359
# define LOG2 0.693147

int		ft_abs(int i);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

int		ft_atoi(const char *str);
double	ft_atof(const char *str);
char	*ft_itoa(int n);

size_t	ft_nblen(int n);

#endif
