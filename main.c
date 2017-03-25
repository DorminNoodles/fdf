/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/03/25 15:21:12 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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



int		quit(int keycode, void *dna)
{
	t_v2d a;
	t_v2d b;
	t_v2d c;
	t_v2d d;
	t_v2d e;
	t_v2d f;
	t_v2d g;
	t_v2d h;
	t_v2d i;
	t_v2d j;
	t_v2d k;
	t_v2d l;
	t_ml *ptr;
	int x;
	int y;

	x = 0;
	y = 0;
	ptr = (t_ml*)dna;

	printf("%d\n", keycode);

	if (keycode == 12)
	{
		draw_map(dna);
	}
	if (keycode == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

int main(int argc, char **argv)
{
	t_ml dna;
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window (mlx, SCREEN_WIDTH, SCREEN_SIZE_Y, WINDOW_TITLE);

	//load_map(argv[1]);
	dna.mlx = mlx;
	dna.win = win;
	dna.origin.x = SCREEN_WIDTH / 2;
	dna.origin.y = 50;

	if (argc == 2)
		load_map(argv[1], &dna);
	else
	{
		ft_putstr("Out !\n");
		exit(EXIT_FAILURE);
	}

	printf("TEST => %f\n", (10 - 5));

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
	mlx_key_hook(win, &quit, &dna);
	mlx_loop(mlx);

	return (0);
}
