/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:40 by lchety            #+#    #+#             */
/*   Updated: 2017/03/26 18:00:52 by lchety           ###   ########.fr       */
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
	int **map;
	int map_w;
	int map_h;
	t_v2d origin;
	float min_z;
	float max_z;
	int blank;
	int posx;
	int posy;
	float elevation;
	float scale;
	float rot;
}t_ml;

#define MAP_WIDTH 18
#define MAP_HEIGHT 10
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "FDF"
#define SIGN " -\n"


void	draw_line(t_ml *env, t_v2d pa, t_v2d pb);
void	draw_line_iso(t_ml *env, t_v2d p1, t_v2d p2);
void	draw_map(t_ml *dna);
int		**create_map(t_ml *dna);
void	load_map(char *filename, t_ml *dna);
void	map_size(t_ml *dna, char *buff);
void	fill_map(char *buff, t_ml *dna);
char	**split_map(char *buff, t_ml *dna);
int		color_z(float z, float length_z);
void	draw_square(t_ml *dna, t_v2d pos, t_v2d size, int color);
t_v2d	v3d(float x, float y, float z);
void	create_map2(t_ml *dna, char *buff);

#endif
