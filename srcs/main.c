/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/06/09 13:13:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

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
		error("usage: fdf input_file\n");
	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	dna.mlx = mlx;
	dna.win = win;
	draw_map(&dna);
	mlx_hook(win, 2, 3, &controller, &dna);
	mlx_loop(mlx);
	return (0);
}
