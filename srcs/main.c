/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:21:03 by lchety            #+#    #+#             */
/*   Updated: 2017/03/31 14:37:27 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

void	free_map(t_ml *dna)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < dna->map_w)
	{
		free (dna->map[i]);
		i++;
	}


}

int		main(int argc, char **argv)
{
	t_ml dna;
	void *mlx;
	void *win;

	init(&dna);

	mlx = mlx_init();
	win = mlx_new_window (mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

	dna.mlx = mlx;
	dna.win = win;

	if (argc == 2)
		load_map(argv[1], &dna);
	else
	{
		ft_putstr("usage: fdf input_file\n");
		exit(EXIT_FAILURE);
	}
	draw_map(&dna);
	printf("HERE\n");
	printf("test => %d\n", dna.map_w + 1);
	mlx_hook(win, 2, 3, &controller, &dna);
	mlx_loop(mlx);
	return (0);
}
