/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:11 by lchety            #+#    #+#             */
/*   Updated: 2017/03/24 18:50:08 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
#include "fdf.h"

t_v2d	v3d(float x, float y, float z)
{
	t_v2d v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	draw_map(t_ml *dna)
{
	int x;
	int y;
	int z;

	t_v2d a;
	t_v2d b;


	x = 0;
	y = 0;
	z = 0;
	a.z = 0;
	b.z = 0;

	printf("debug => %d\n", dna->map[0][1]);
	printf("debug => %d\n", dna->map[1][0]);

	while (x < dna->map_width)
	{
		y = 0;
		while (y < dna->map_height)
		{
			a.z = dna->map[x][y];
			b.z = dna->map[x + 1][y];
			//z = dna->map[x + 1][y] * 12;
			//printf("z = %d\n", z);
			if (x < dna->map_width - 1)
			{
				draw_line_iso(dna, v3d(x,y,a.z), v3d(x + 1,y,b.z));
			}

			a.z = dna->map[x][y];
			b.z = dna->map[x][y + 1];

			if (y < dna->map_height - 1)
			{
				draw_line_iso(dna, v3d(x,y,a.z), v3d(x,y + 1,b.z));
			}
			y++;
		}
		x++;
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

	a.y -= p1.z * 5;
	b.y -= p2.z * 5;

	// printf("z => %f\n", p1.z);

	a.z = p1.z;
	b.z = p2.z;

	draw_line(env, a, b);
}

void	draw_line(t_ml *env, t_v2d p1, t_v2d p2)
{
	int i;
	float deltax;
	float deltay;
	float deltaz;
	float length;

	i = 0;
	p1.x += 0.5 + env->origin.x;
	p1.y += 0.5 + env->origin.y;
	p2.x += env->origin.x;
	p2.y += env->origin.y;
	length = find_length(p1, p2);
	deltax = (p2.x - p1.x) / length;
	deltay = (p2.y - p1.y) / length;
	deltaz = (p2.z - p1.z) / length;

	// printf("deltaz => %f\n", deltaz);

	//printf("Z COLOR => %f\n", deltaz);
	// printf("length = %f\n", length);
	// printf("deltax = %f\n", deltax);
	// printf("deltay = %f\n", deltay);
	while (i <= length)
	{
		mlx_pixel_put(env->mlx, env->win, p1.x, p1.y, color_z(p1.z));
		p1.x += deltax;
		p1.y += deltay;
		p1.z += deltaz;
		i++;
	}
	//printf("p1.z => %f\n", p1.z);
}
