/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/24 15:57:15 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size(t_ml *dna, char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\n')
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			dna->map_width++;
		i++;
	}
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			dna->map_height++;
		i++;
	}
}

void	fill_map(char *buff, t_ml *dna)
{
	int i;
	int j;
	int x;
	int y;
	char	**z_tab;

	i = 0;
	j = 0;

	x =0;
	y = 0;

	z_tab = split_map(buff, dna);

	printf("REDRUM *%s*\n", z_tab[0]);
	printf("REDRUM *%s*\n", z_tab[1]);
	printf("REDRUM *%s*\n", z_tab[2]);
	printf("REDRUM *%s*\n", z_tab[5]);
	printf("start\n");
	printf("%d\n", dna->map_height * dna->map_width);
	int fuck = 0;
	while (i < dna->map_height * dna->map_width)
	{
		printf("%s  ", *(z_tab + i));
		i++;
		fuck++;
		if (fuck == 19)
		{
			printf("\n");
			fuck = 0;
		}
	}
	printf("exit\n");
	printf("test\n");
	printf("map height => %d\n", dna->map_height);
	printf("map width => %d\n", dna->map_width);

	i = 0;

	printf("map test de merde %d\n", dna->map[2][1]);

	i = 0;
	y = 0;
	while (y < dna->map_height)
	{
		x = 0;
		while (x < dna->map_width)
		{
			dna->map[x][y] = ft_atoi(*z_tab++);
			x++;
		}
		y++;
	}

	printf("exit\n");

	printf("test map = %d\n", dna->map[1][0]);
	printf("test map = %d\n", dna->map[0][1]);
}

int		**create_map(t_ml *dna)
{
	int i;
	int j;
	int	**map;

	i = 0;
	map = (int**)malloc(sizeof(int*) * dna->map_width + 1);
	while (i < dna->map_width + 1)
	{
		map[i] = (int*)malloc(sizeof(int) * dna->map_height + 1);
		j = 0;
		while (j < dna->map_height + 1)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
