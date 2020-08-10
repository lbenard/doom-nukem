/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:47:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/08 19:12:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <string.h>
# ifdef __linux__
#  include <sys/types.h>
# endif

# define PI 3.14159265359
# define LOG2 0.693147

int		ft_abs(int i);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

float	ft_fabs(float i);
float	ft_fmin(float a, float b);
float	ft_fmax(float a, float b);

double	ft_dabs(double i);
double	ft_dmin(double a, double b);
double	ft_dmax(double a, double b);

size_t	ft_smin(size_t a, size_t b);
size_t	ft_smax(size_t a, size_t b);

ssize_t	ft_ssabs(ssize_t i);
ssize_t	ft_ssmin(ssize_t a, ssize_t b);
ssize_t	ft_ssmax(ssize_t a, ssize_t b);

int		ft_atoi(const char *str);
double	ft_atof(const char *str);
char	*ft_itoa(int n);

size_t	ft_nblen(int n);

/*
** Return the interpolated float result between the two float values
*/
float	lerp(float v0, float v1, float t);

/*
** Returns the percentage of value between start and end
*/
float	inverse_lerp(float v0, float v1, float value);

#endif
