/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:11 by lchety            #+#    #+#             */
/*   Updated: 2017/04/02 20:06:42 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_v3d	v3d(float x, float y, float z)
{
	t_v3d v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	draw_map(t_ml *dna)
{
	int		x;
	int		y;
	t_v3d	b;

	x = -1;
	b.z = 0;
	while (++x < dna->map_w)
	{
		y = -1;
		while (++y < dna->map_h)
		{
			if (x < dna->map_w - 1)
			{
				b.z = dna->map[x + 1][y];
				draw_line_iso(dna, v3d(x, y, dna->map[x][y]),
				v3d(x + 1, y, b.z));
			}
			if (y < dna->map_h - 1)
			{
				b.z = dna->map[x][y + 1];
				draw_line_iso(dna, v3d(x, y, dna->map[x][y]),
				v3d(x, y + 1, b.z));
			}
		}
	}
}

float	max_length(t_v3d p1, t_v3d p2)
{
	float	lx;
	float	ly;

	lx = p2.x - p1.x;
	if (lx < 0)
		lx *= -1;
	ly = p2.y - p1.y;
	if (ly < 0)
		ly *= -1;
	if (lx > ly)
		return (lx);
	return (ly);
}

void	draw_line_iso(t_ml *dna, t_v3d p1, t_v3d p2)
{
	t_v3d a;
	t_v3d b;

	a.x = (p1.x - p1.y) * 32 * dna->scale;
	a.y = (p1.y + p1.x) * 16 * dna->scale;
	b.x = (p2.x - p2.y) * 32 * dna->scale;
	b.y = (p2.y + p2.x) * 16 * dna->scale;
	a.y -= p1.z * dna->z_height;
	b.y -= p2.z * dna->z_height;
	a.z = p1.z;
	b.z = p2.z;
	draw_line(dna, a, b);
}

void	draw_line(t_ml *dna, t_v3d a, t_v3d b)
{
	int		i;
	float	deltax;
	float	deltay;
	float	deltaz;
	float	length;

	i = 0;
	a.x += 0.5 + dna->origin.x + dna->posx;
	a.y += 0.5 + dna->origin.y + dna->posy;
	b.x += dna->origin.x + dna->posx;
	b.y += dna->origin.y + dna->posy;
	length = max_length(a, b);
	deltax = (b.x - a.x) / length;
	deltay = (b.y - a.y) / length;
	deltaz = (b.z - a.z) / length;
	while (i <= length)
	{
		mlx_pixel_put(dna->mlx, dna->win, a.x, a.y, color(dna, a.z +
		fabsf(dna->min_z));
		a.x += deltax;
		a.y += deltay;
		a.z += deltaz;
		i++;
	}
}
