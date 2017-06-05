/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/06/01 16:58:23 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

void	z_limits(t_ml *dna, int z)
{
	dna->max_z = (dna->max_z < z) ? z : dna->max_z;
	dna->min_z = (dna->min_z > z) ? z : dna->min_z;
}

int		main(int argc, char **argv)
{
	t_ml dna;
	void *mlx;
	void *win;

	init(&dna);
	if (argc == 2)
	load_map(argv[1], &dna);
	else
	{
		ft_putstr("usage: fdf input_file\n");
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	dna.mlx = mlx;
	dna.win = win;
	draw_map(&dna);
	mlx_hook(win, 2, 3, &controller, &dna);
	mlx_loop(mlx);
	return (0);
}
