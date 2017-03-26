/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/03/26 16:41:07 by lchety           ###   ########.fr       */
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



int		quit(int keycode, void *ptr)
{
	t_ml *dna;
	int x;
	int y;
	t_v2d p1;
	t_v2d size;

	x = 0;
	y = 0;
	dna = (t_ml*)ptr;

	printf("%d\n", keycode);

	if (keycode == 12)
	{
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 123)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->posx -= 10;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 124)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->posx += 10;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 126)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->posy -= 10;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 125)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->posy += 10;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 116)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->elevation += 0.4;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 121)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->elevation -= 0.4;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 24 || keycode == 69)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->scale += 0.02;
		dna->blank = 0;
		draw_map(dna);
	}
	if (keycode == 27 || keycode == 78)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->scale -= 0.02;
		dna->blank = 0;
		draw_map(dna);
	}

	if (keycode == 91)
	{
		dna->blank = 1;
		draw_map(dna);
		dna->rot += 0.2;
		dna->blank = 0;
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
	win = mlx_new_window (mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

	dna.mlx = mlx;
	dna.win = win;
	dna.origin.x = SCREEN_WIDTH / 2;
	dna.origin.y = 50;
	dna.posx = 0;
	dna.posy = 0;
	dna.elevation = 1;
	dna.scale = 1.0;
	dna.rot = 1.0;

	if (argc == 2)
		load_map(argv[1], &dna);
	else
	{
		ft_putstr("Out !\n");
		exit(EXIT_FAILURE);
	}
	// printf("Test\n");
	// printf("TEST => %f\n", (10 - 5));
	//mlx_expose_hook(win, &test, NULL);
	//mlx_loop_hook(win, &loop_hook, ml);
	mlx_key_hook(win, &quit, &dna);
	mlx_loop(mlx);

	return (0);
}
