/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/27 17:30:27 by lchety           ###   ########.fr       */
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

void	create_map(t_ml *dna)
{
	int i;

	i = -1;
	dna->map = (int**)ft_memalloc(sizeof(int*) * dna->map_w + 1);
	while (i++ < dna->map_w + 1)
		dna->map[i] = (int*)ft_memalloc(sizeof(int) * dna->map_h + 1);
}

void	fill_map(char *buff, t_ml *dna)
{
	int i;
	int j;
	int k;
	int nb_digit;
	char hot_plate[20];

	ft_bzero(hot_plate, 20);
	i = -1;
	while (i++ < dna->map_h + 1)
	{
		j = 0;
		while (j < dna->map_w)
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
					if (dna->max_z < dna->map[j][i])
						dna->max_z = dna->map[j][i];
					if(dna->min_z > dna->map[j][i])
						dna->min_z = dna->map[j][i];
					break;
				}
				buff++;
				k++;
			}
			ft_bzero(hot_plate, 20);
			j++;
		}
		printf("\n");
	}
}

/*
void	create_map2(t_ml *dna, char *buff)
{
	int i;
	int j;
	int k;
	int nb_digit;
	char hot_plate[20];

	i = -1;
	ft_bzero(hot_plate, 20);
	i = 0;
	while (i < dna->map_h + 1)
	{
		j = 0;
		while (j < dna->map_w)
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
					printf("test => %d\n", ft_atoi(hot_plate));
					dna->map[j][i] = 0;
					printf("HIVE\n");
					//if ()
					break;
				}
				buff++;
				k++;
			}
			ft_bzero(hot_plate, 20);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/
