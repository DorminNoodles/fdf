/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:11 by lchety            #+#    #+#             */
/*   Updated: 2017/03/22 19:15:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
#include "fdf.h"

void	draw_map(t_ml *env, int **map)
{
	int i;
	int j;

	t_v2d a;
	t_v2d b;


	i = 0;
	a.z = 0;
	b.z = 0;

	//map = create_map(MAP_WIDTH, MAP_HEIGHT);


	// printf("test = %d\n", map[0][0]);
	// printf("test = %d\n", map[1][3]);
	// printf("test = %d\n", map[4][4]);
	// printf("test = %d\n", map[4][5]);
	// printf("test = %d\n", map[2][2]);

	map[4][4] = 1;
	map[4][5] = 1;
	map[4][6] = 1;
	// map[0][0] = 1;
	// map[1][0] = 1;
	// map[2][0] = 1;
	// map[3][0] = 1;
	// map[4][0] = 1;
	// map[5][0] = 1;
	// map[6][0] = 1;
	// map[7][0] = 1;
	// map[8][0] = 1;

	while (i <= MAP_HEIGHT)
	{
		j = 0;
		while (j <= MAP_WIDTH)
		{
			a.x = j;
			a.y = i;
			b.x = j + 1;
			b.y = i;

			a.z = map[j][i] * 32;

			if (j < MAP_WIDTH)
			{
				b.z = map[j + 1][i] * 32;
				draw_line_iso(env, a, b);
			}
			a.x = j;
			a.y = i;
			b.x = j;
			b.y = i + 1;

			a.z = map[j][i] * 32;

			if (i < MAP_HEIGHT)
			{
				b.z = map[j][i + 1] * 32;
				draw_line_iso(env, a, b);
			}
			j++;
		}
		i++;
	}
}

void	draw_tile(t_v2d pos)
{


}

float	find_length(t_v2d p1, t_v2d p2)
{
	float	lx;
	float	ly;

	lx = p2.x - p1.x;
		if (lx < 0)
			lx = lx * -1;
	ly = p2.y - p1.y;
		if (ly < 0)
			ly = ly * -1;

	if (lx > ly)
		return (lx);
	else
		return (ly);
}

void	draw_line_iso(t_ml *env, t_v2d p1, t_v2d p2)
{
	t_v2d a;
	t_v2d b;


	a.x = (p1.x * 32) - (p1.y * 32);
	a.y = (p1.y * 16) + (p1.x * 16);
	b.x = (p2.x * 32) - (p2.y * 32);
	b.y = (p2.y * 16) + (p2.x * 16);

	//printf("draw_line iso z = %f\n", p1.z);
	a.y -= p1.z;
	b.y -= p2.z;

	// p2.x -= 64;
	// p1.y -= 32;
	// p2.y += 64;

	draw_line(env, a, b);
}

void	draw_line(t_ml *env, t_v2d p1, t_v2d p2)
{
	int i;
	float deltax;
	float deltay;
	float length;

	i = 0;
	p1.x += 0.5 + env->origin.x;
	p1.y += 0.5 + env->origin.y;
	p2.x += env->origin.x;
	p2.y += env->origin.y;
	length = find_length(p1, p2);
	deltax = (p2.x - p1.x) / length;
	deltay = (p2.y - p1.y) / length;
	// printf("length = %f\n", length);
	// printf("deltax = %f\n", deltax);
	// printf("deltay = %f\n", deltay);
	while (i <= length)
	{
		mlx_pixel_put(env->mlx, env->win, p1.x, p1.y, 0x00FFFFFF);
		p1.x += deltax;
		p1.y += deltay;
		i++;
	}
}
