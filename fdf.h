/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:40 by lchety            #+#    #+#             */
/*   Updated: 2017/03/18 16:46:08 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include "mlx.h"

typedef struct
{
	void *mlx;
	void *win;

}t_ml;

typedef struct s_v2d
{
	float x;
	float y;

}t_v2d;

void	draw_line(t_ml *env, t_v2d pa, t_v2d pb);


#endif
