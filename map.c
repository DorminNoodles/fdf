/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/20 22:07:32 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**create_map(void)
{
	int i;
	int j;
	int	**map;

	map = (int**)malloc(sizeof(int*) * MAP_WIDTH);

	while (i < MAP_WIDTH)
	{
		map[i] = (int*)malloc(sizeof(int) * MAP_HEIGHT);
		j = 0;
		while (j < MAP_HEIGHT)
		{
			printf("j\n");
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
