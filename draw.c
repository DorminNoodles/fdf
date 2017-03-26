/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:11 by lchety            #+#    #+#             */
/*   Updated: 2017/03/26 16:44:05 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
#include <math.h>
#include "fdf.h"

t_v2d	v3d(float x, float y, float z)
{
	t_v2d v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	draw_square(t_ml *dna, t_v2d pos, t_v2d size, int color)
{
	int x;
	int y;
	int sizex;
	int sizey;


	x = (int)pos.x;
	y = (int)pos.y;
	sizex = (int)size.x;
	sizey = (int)size.y;

	while (x - pos.x < sizex)
	{
			// printf("bite x = %d\n", x);
		y = 0;
		while (y - pos.y < sizey)
		{
			// printf("bite y = %d\n", y);
			mlx_pixel_put(dna->mlx, dna->win, x, y, color);
			y++;
		}
		x++;
	}
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

	while (x < dna->map_w)
	{
		y = 0;
		while (y < dna->map_h)
		{
			a.z = dna->map[x][y];
			b.z = dna->map[x + 1][y];
			if (x < dna->map_w - 1)
			{
				draw_line_iso(dna, v3d(x,y,a.z), v3d(x + 1,y,b.z));
			}

			a.z = dna->map[x][y];
			b.z = dna->map[x][y + 1];

			if (y < dna->map_h - 1)
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

float	max_length(t_v2d p1, t_v2d p2)
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

void	draw_line_iso(t_ml *dna, t_v2d p1, t_v2d p2)
{
	t_v2d a;
	t_v2d b;

	a.x = (p1.x * 32 * dna->scale) - (p1.y * 32 * dna->scale);
	a.y = (p1.y * 16 * dna->scale) + (p1.x * 16 * dna->scale);
	b.x = (p2.x * 32 * dna->scale) - (p2.y * 32 * dna->scale);
	b.y = (p2.y * 16 * dna->scale) + (p2.x * 16 * dna->scale);

	a.y -= p1.z * dna->elevation;
	b.y -= p2.z * dna->elevation;

	a.z = p1.z;
	b.z = p2.z;
	draw_line(dna, a, b);
}

void	draw_line(t_ml *dna, t_v2d p1, t_v2d p2)
{
	int i;
	float deltax;
	float deltay;
	float deltaz;
	float length;

	i = 0;
	p1.x += 0.5 + dna->origin.x + dna->posx;
	p1.y += 0.5 + dna->origin.y + dna->posy;
	p2.x += dna->origin.x + dna->posx;
	p2.y += dna->origin.y + dna->posy;
	length = max_length(p1, p2);
	deltax = (p2.x - p1.x) / length;
	deltay = (p2.y - p1.y) / length;

	float len_z = (dna->max_z - dna->min_z);
	deltaz = (p2.z - p1.z) / length;
	while (i <= length)
	{

		if (!dna->blank)
			mlx_pixel_put(dna->mlx, dna->win, p1.x, p1.y, color_z(p1.z + fabsf(dna->min_z), len_z));
		else
			mlx_pixel_put(dna->mlx, dna->win, p1.x, p1.y, 0x00000000);
		p1.x += deltax;
		p1.y += deltay;
		p1.z += deltaz;
		i++;
	}
}
