/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_table.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:28:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/18 18:30:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_TABLE_H
# define LOOKUP_TABLE_H

# include "maths/maths.h"

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
