/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/03/21 23:10:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**create_map(int width, int height)
{
	int i;
	int j;
	int	**map;

	i = 0;
	map = (int**)malloc(sizeof(int*) * width + 1);
	while (i < width + 1)
	{
		printf("ZERO\n");

		map[i] = (int*)malloc(sizeof(int) * height + 1);
		j = 0;
		while (j < height + 1)
		{
			printf("ZERO\n");
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
