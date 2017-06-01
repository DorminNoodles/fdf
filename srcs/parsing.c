/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:43:28 by lchety            #+#    #+#             */
/*   Updated: 2017/06/01 16:55:28 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void		check_map(char *buff)
{
	check_sign(buff);
	check_layout(buff);
}

void		check_sign(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (!ft_strchr(SIGN, buff[i]) && !ft_isdigit(buff[i]))
		{
			ft_putstr("File Sign Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void		check_layout(char *buff)
{
	int i;
	int j;
	int width;

	i = -1;
	j = 0;
	width = 0;
	while (buff[++i] != '\n')
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			width++;
	i++;
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			j++;
		if (buff[i] == '\n')
		{
			if (j != width)
				error("error layout\n");
			j = 0;
		}
		i++;
	}
}
