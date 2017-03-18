/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:35:11 by lchety            #+#    #+#             */
/*   Updated: 2017/03/18 19:24:48 by lchety           ###   ########.fr       */
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

void	draw_line(t_ml *env, t_v2d p1, t_v2d p2)
{
	int i;
	int j;
	float deltax;
	float deltay;
	float length;

	p1.y += 0.5;
	p1.x += 0.5;

	length = find_length(p1, p2);
/*
	if (p2.x - p1.x > p2.y - p1.y)
	{
		length = p2.x - p1.x;
	}
	else
		length = p2.y - p1.y;
*/
	//find longest distance
	deltax = (p2.x - p1.x) / length;
	deltay = (p2.y - p1.y) / length;

	printf("length = %f\n", length);
	printf("deltax = %f\n", deltax);
	printf("deltay = %f\n", deltay);

	//printf("print_line !\n");
	i = 0;

	while (i < length)
	{
		printf("y = %f\n", p1.y + (deltay * i));
		mlx_pixel_put(env->mlx, env->win, (int)p1.x + (deltax * i), p1.y + (deltay * i), 0x00FFFFFF);
		i++;
	}

	//tous les tant sur x je dois incrementer y
	//je dois prendre la longueur de x et la longueur y et diviser y par x ? si y = 2 et x = 10 je veux que y = 5 donc 10/2=x/y   y=x/y

}
