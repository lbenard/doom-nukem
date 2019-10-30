/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_table.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:28:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:04:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_TABLE_H
# define LOOKUP_TABLE_H

/*
** Return the interpolated float result between the two float values
*/
float	lerp(float v0, float v1, float t);

/*
** Returns the percentage of value between start and end
*/
float	inverse_lerp(float v0, float v1, float value);

/*
** Lookup tables for costly mathematics operations
*/
# define SINE_TABLE_SIZE 1024

float	sine_lookup(const float t);

# define COSINE_TABLE_SIZE 1024

float	cosine_lookup(const float t);

# define TANGENT_TABLE_SIZE 1024

float	tangent_lookup(const float t);

#endif
