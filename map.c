/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/26 20:23:06 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size(t_ml *dna, char *buff)
{
	int i;

	i = 0;
	dna->map_w = 0;
	dna->map_h = 0;
	while (buff[i] != '\n')
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			dna->map_w++;
		i++;
	}
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			dna->map_h++;
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
	x = 0;
	y = 0;

	z_tab = split_map(buff, dna);
	printf("start\n");
	printf("%d\n", dna->map_h * dna->map_w);
	int fuck = 0;
	while (i < dna->map_h * dna->map_w)
	{
		// printf("%s  ", *(z_tab + i));
		i++;
		fuck++;
		if (fuck == 19)
		{
			printf("\n");
			fuck = 0;
		}
	}
	i = 0;
	dna->min_z = 0;
	dna->max_z = 0;
	i = 0;
	y = 0;
	while (y < dna->map_h)
	{
		x = 0;
		while (x < dna->map_w)
		{
			dna->map[x][y] = ft_atoi(*z_tab++);
			if (dna->min_z > dna->map[x][y])
				dna->min_z = dna->map[x][y];
			if (dna->max_z < dna->map[x][y])
				dna->max_z = dna->map[x][y];
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
	map = (int**)malloc(sizeof(int*) * dna->map_w + 1);
	while (i < dna->map_w + 1)
	{
		printf(" i => %d\n", dna->map_w);
		map[i] = (int*)malloc(sizeof(int) * dna->map_h + 1);
		j = 0;
		while (j < dna->map_h + 1)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	create_map2(t_ml *dna, char *buff)
{
	int i;
	int j;
	int k;
	int nb_digit;
	char hot_plate[20];

	i = 0;
	printf("%c\n", buff[0]);
	printf("%c\n", buff[1]);
	printf("%c\n", buff[2]);
	printf("%c\n", buff[3]);
	ft_bzero(hot_plate, 20);
	dna->map = (int**)malloc(sizeof(int*) * dna->map_w + 1);
	while (i < dna->map_w + 1)
	{
		dna->map[i] = (int*)malloc(sizeof(int) * dna->map_h + 1);
		i++;
	}
	i = 0;
	while (i < dna->map_h + 1)
	{
		j = 0;
		while (j < dna->map_w + 1)
		{
			k = 0;
			while (*buff)
			{
				hot_plate[k] = *buff;
				if (ft_isdigit(*buff) && (buff[1] == ' ' || buff[1] == '\n'))
				{
					buff++;
					k++;
					hot_plate[k] = *buff;
					dna->map[j][i] = ft_atoi(hot_plate);
					printf("ATOI =>%d\n", ft_atoi(hot_plate));
					break;
				}
				buff++;
				k++;
				//if (ft_isdigit(*buff) && (buff[1] == ' ' || buff[1] == '\n'))
					//break;
			}
			ft_bzero(hot_plate, 20);
			j++;
		}
		i++;
	}
}
