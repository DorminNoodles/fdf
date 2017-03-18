/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/03/17 23:06:10 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct
{
	void *mlx;
	void *win;

}t_ml;

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

void	print_line(t_ml *env, float startx, float endx, float starty, float endy)
{
	int lengthx;
	int lengthy;
	int i;
	float y;

	lengthx = endx - startx;
	lengthy = endy - starty;
	printf("print_line !\n");
	i = 0;


	//printf("lengthx = %d\n", lengthx);
	// printf("y = %d\n");

	while (i < lengthx)
	{
		y = ((float)lengthy / (float)lengthx) * i;
		printf("%f\n", y);
		mlx_pixel_put(env->mlx, env->win, (int)startx + i, starty + (int)y, 0x00FFFFFF);
		i++;
	}

	//tous les tant sur x je dois incrementer y
	//je dois prendre la longueur de x et la longueur y et diviser y par x ? si y = 2 et x = 10 je veux que y = 5 donc 10/2=x/y   y=x/y

}

int		quit(int keycode, void *param)
{
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
		print_line(ptr, 50.0, 344.0, 40.0, 120.0);
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
	win = mlx_new_window (mlx, 600, 600, "vieille pute");

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
