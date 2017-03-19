/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/03/19 18:45:59 by lchety           ###   ########.fr       */
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
		a.x = 0;
		b.x = 0;
		a.y = 0;
		b.y = 1 * 64;

		c.x = 0 * 64;
		d.x = 1 * 64;
		c.y = 0;
		d.y = 0;

		e.x = 0;
		f.x = 40;
		e.y = 0;
		f.y = 10;

		g.x = 0;
		h.x = 250;
		g.y = 0;
		h.y = 380;

		//draw_line(ptr, a, b);
		//draw_line_iso(ptr, a, b);
		draw_line_iso(ptr, c, d);
		//draw_line_iso(ptr, c, d);
		// draw_line(ptr, c, d);
		// draw_line(ptr, e, f);
		// draw_line(ptr, g, h);
		// mlx_pixel_put(ptr->mlx, ptr->win, a.x, a.y, 0x00FF0000);
		// mlx_pixel_put(ptr->mlx, ptr->win, b.x, b.y, 0x00FF0000);
		// mlx_pixel_put(ptr->mlx, ptr->win, c.x, c.y, 0x00FF0000);
		// mlx_pixel_put(ptr->mlx, ptr->win, d.x, d.y, 0x00FF0000);

		// mlx_pixel_put(ptr->mlx, ptr->win, e.x + 1, e.y, 0x00FF0000);
		//mlx_pixel_put(ptr->mlx, ptr->win, f.x, f.y, 0x00FF0000);

		mlx_pixel_put(ptr->mlx, ptr->win, 0, 0, 0x00FFFF00);
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
	win = mlx_new_window (mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y, WINDOW_TITLE);

	ml->mlx = mlx;
	ml->win = win;
	ml->origin.x = SCREEN_SIZE_X / 2;
	ml->origin.y = SCREEN_SIZE_Y / 2;

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
