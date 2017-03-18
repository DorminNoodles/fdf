/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/03/18 19:27:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"


int		test(void *param)
{
	printf("Expose !\n");
	return (0);
}

int		loop_hook(void *param)
{
	int i;
	t_ml *p;

	i = 0;
	p = (t_ml*)param;

	mlx_pixel_put(p->mlx, p->win, 5, 5, 0x00FFFFFF);
	mlx_pixel_put(p->mlx, p->win, 6, 6, 0x00FFFFFF);
	mlx_pixel_put(p->mlx, p->win, 7, 7, 0x00FFFFFF);
	mlx_pixel_put(p->mlx, p->win, 8, 8, 0x00FFFFFF);
	printf("Loop hook !\n");
	return (0);
}



int		quit(int keycode, void *param)
{
	t_v2d a;
	t_v2d b;
	t_v2d c;
	t_v2d d;
	t_v2d e;
	t_v2d f;
	t_v2d g;
	t_v2d h;
	t_ml *ptr;
	int x;
	int y;

	x = 0;
	y = 0;
	ptr = (t_ml*)param;

	printf("%d\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);


	if (keycode == 12)
	{
		a.x = 400;
		b.x = 750;
		a.y = 400;
		b.y = 750;

		c.x = 400;
		d.x = 750;
		c.y = 400;
		d.y = 100;

		e.x = 400;
		f.x = 40;
		e.y = 400;
		f.y = 10;

		g.x = 750;
		h.x = 40;
		g.y = 100;
		h.y = 10;

		draw_line(ptr, a, b);
		draw_line(ptr, c, d);
		draw_line(ptr, e, f);
		draw_line(ptr, g, h);
		mlx_pixel_put(ptr->mlx, ptr->win, a.x, a.y, 0x00FF0000);
		mlx_pixel_put(ptr->mlx, ptr->win, b.x, b.y, 0x00FF0000);
	}

	if (keycode == 13)
	{

		while (y < 250)
		{
			x = 50;
			while (x < 250)
			{
				mlx_pixel_put(ptr->mlx, ptr->win, x, y, 0x00000000);
				x++;
			}
			y++;
		}
		printf("bite");
	}


	return (0);
}

int main(void)
{
	t_ml *ml;
	void *mlx;
	void *win;
	int x;
	int y;

	x = 50;
	y = 50;
	mlx = mlx_init();
	win = mlx_new_window (mlx, 800, 800, "Sam Fisher");

	ml->mlx = mlx;
	ml->win = win;

/*
	while (y < 300)
	{
		x = 50;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
*/
	//mlx_expose_hook(win, &test, NULL);
	//mlx_loop_hook(win, &loop_hook, ml);
	mlx_key_hook(win, &quit, ml);
	mlx_loop(mlx);

	return (0);
}
