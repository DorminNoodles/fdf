/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:19:51 by lchety            #+#    #+#             */
/*   Updated: 2017/03/30 23:34:03 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_ml *dna)
{
	dna->origin.x = SCREEN_WIDTH / 2;
	dna->origin.y = 50;
	dna->posx = 0;
	dna->posy = 0;
	dna->z_height = 1;
	dna->scale = 1.0;
	dna->rot = 1.0;
	dna->max_z = 0;
	dna->min_z = 0;
}
