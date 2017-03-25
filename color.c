/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:48:07 by lchety            #+#    #+#             */
/*   Updated: 2017/03/25 23:46:25 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_z(float z, float length_z)
{
	int ret;
 	float factor;
	int red;
	int green;
	int blue;

	// printf("deltaz => %f\n", deltaz);
	factor = 255 / length_z;

	green = 255 - ((int)(factor * z));
	blue = (int)(factor * z);

	//if(green != 0 && green != 255)
	// printf("green => %d\n", green);


	//if (red > 200)
		// printf("red => %f\n", red);
	//if (red != 0)
		//printf("%f * %f = %d\n", factor, z, red);
	// printf("red => %x\n", red);

	ret = 0x00FF0000;
	green = green << 8;
	//red = red << 16;
	ret = ret | green;
	ret = ret | blue;
	//printf("rret ====> %#.8x\n", ret);
	return (ret);
}
