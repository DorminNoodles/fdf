/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:40 by lchety            #+#    #+#             */
/*   Updated: 2017/03/21 22:52:12 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct s_v2d
{
	float x;
	float y;
	float z;

}t_v2d;

typedef struct s_ml
{
	void *mlx;
	void *win;
	t_v2d origin;

}t_ml;

#define MAP_WIDTH 18
#define MAP_HEIGHT 10
#define SCREEN_WIDTH 1500
#define SCREEN_SIZE_Y 800
#define WINDOW_TITLE "FDF"


void	draw_line(t_ml *env, t_v2d pa, t_v2d pb);
void	draw_line_iso(t_ml *env, t_v2d p1, t_v2d p2);
void	draw_map(t_ml *env, int **map);
int		**create_map(int width, int height);


#endif
