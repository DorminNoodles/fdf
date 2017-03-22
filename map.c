/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/22 19:44:20 by lchety           ###   ########.fr       */
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
	char	**z_tab;

	i = 0;
	j = 0;

	z_tab = split_map(buff, dna);
	while (i < dna->map_height)
	{
		while (j < dna->map_width)
		{
			dna->map[i][j] = 0;
			j++;
		}
		i++;
	}

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
