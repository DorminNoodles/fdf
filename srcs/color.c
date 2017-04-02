/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:48:07 by lchety            #+#    #+#             */
/*   Updated: 2017/04/02 20:05:24 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(t_ml *dna, float z)
{
	int ret;
 	float factor;
	int red;
	int green;
	int blue;

	if (dna->blank)
		return (0x00000000);
	if ((dna->max_z - dna->min_z) != 0)
		factor = 255 / (dna->max_z - dna->min_z);
	else
		factor = 0;
	green = 255 - ((int)(factor * z));
	blue = (int)(factor * z);
	ret = 0x00FF0000;
	green = green << 8;
	ret = ret | green;
	ret = ret | blue;
	return (ret);
}
