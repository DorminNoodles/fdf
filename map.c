/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/21 21:15:46 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**create_map(void)
{
	int i;
	int j;
	int	**map;

	i = 0;
	map = (int**)malloc(sizeof(int*) * MAP_WIDTH + 1);
	while (i < MAP_WIDTH + 1)
	{
		printf("ZERO\n");

		map[i] = (int*)malloc(sizeof(int) * MAP_HEIGHT + 1);
		j = 0;
		while (j < MAP_HEIGHT + 1)
		{
			printf("ZERO\n");
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
