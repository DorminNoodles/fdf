/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:40 by lchety            #+#    #+#             */
/*   Updated: 2017/04/02 20:05:27 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "mlx.h"
#include "libft.h"

#define FALSE 0
#define TRUE 1
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define ZOOM_IN	24
#define ZOOM_OUT 27
#define UP_Z 116
#define DOWN_Z 121
#define ESCAPE 53
#define RESET 12

typedef char bool;
typedef struct s_v2d
{
	float x;
	float y;
	float z;

}t_v3d;

typedef struct s_ml
{
	void *mlx;
	void *win;
	int **map;
	int map_w;
	int map_h;
	t_v3d origin;
	float min_z;
	float max_z;
	int blank;
	int posx;
	int posy;
	float z_height;
	float scale;
	float rot;

}t_ml;

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "FDF"
#define SIGN " -\n"


void	draw_line(t_ml *dna, t_v3d a, t_v3d b);
void	draw_line_iso(t_ml *env, t_v3d p1, t_v3d p2);
void	draw_map(t_ml *dna);
void	load_map(char *filename, t_ml *dna);
void	map_size(t_ml *dna, char *buff);
void	fill_map(char *buff, t_ml *dna);
int		color(t_ml *dna, float z);
void	draw_square(t_ml *dna, t_v3d pos, t_v3d size, int color);
t_v3d	v3d(float x, float y, float z);
void	create_map2(t_ml *dna, char *buff);
void	create_map(t_ml *dna);
void	init(t_ml *dna);
int		input(int keycode, void *ptr);
int		controller(int keycode, void *param);
void	clear_map(t_ml *dna);
void	check_sign(char *buff);
void	check_layout(char *buff);
void	free_map(t_ml *dna);

#endif
