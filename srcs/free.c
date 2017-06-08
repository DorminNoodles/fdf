/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:54:27 by lchety            #+#    #+#             */
/*   Updated: 2017/06/07 08:52:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_map(t_ml *dna)
{
	dna->blank = 1;
	draw_map(dna);
	dna->blank = 0;
}

void	free_map(t_ml *dna)
{
	int i;

	while (i < dna->map_w)
	{
		free(dna->map[i]);
		dna->map[i] = NULL;
		i++;
	}
	free(dna->map);
	dna->map = NULL;
}
