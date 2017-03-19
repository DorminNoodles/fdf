/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:11 by lchety            #+#    #+#             */
/*   Updated: 2017/03/19 18:47:33 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

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
	// 1 sur x
	printf("p2x = %f\n", p2.x);
	printf("p2y = %f\n", p2.y);

	//p2.x = p2.x;
	p1.y += (p1.x/32) * 32;
	p2.y += (p2.x/32) * 32;

	p2.x -= (p2.y/32) * 32;

	printf("p1y = %f\n", p1.y);
	printf("p2y = %f\n", p2.y);
	printf("p1x = %f\n", p1.x);
	printf("p2x = %f\n", p2.x);



	// p2.x -= 64;
	// p1.y -= 32;
	// p2.y += 64;

	draw_line(env, p1, p2);
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
