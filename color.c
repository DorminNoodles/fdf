/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:48:07 by lchety            #+#    #+#             */
/*   Updated: 2017/03/24 16:23:18 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		color_z(float z)
{
	int ret;
	int factor;
	int red;

	factor = 50;
	ret = 0x0000FF00;

	red = (255 / factor) * z;
	// printf("red %d\n", red);

	red = red << 16;
	ret = ret | red;
	//printf("rret ====> %x", ret);

	return (ret);
}
