/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:43:28 by lchety            #+#    #+#             */
/*   Updated: 2017/03/31 13:58:46 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
char		**split_map(char *buff, t_ml *dna)
{
	char **tb;
	char *tmp;
	int nb_digit;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = buff;
	tb = (char**)ft_memalloc(sizeof(char*) * dna->map_w * dna->map_h);
	while (*tmp)
	{
		nb_digit = 0;
		while (ft_isdigit(*tmp) || *tmp == '-')
		{
			tmp++;
			nb_digit++;
		}
		if (nb_digit)
		{
			tb[j] = (char*)ft_memalloc(sizeof(char) * (nb_digit + 1));
			i = 0;
			while (i < nb_digit)
			{
				tb[j][i] = *(tmp - (nb_digit - i));
				i++;
			}
			j++;
		}
		tmp++;
	}
	return (tb);
}
*/

void		check_sign(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (!ft_strchr(SIGN, buff[i]) && !ft_isdigit(buff[i]))
		{
			ft_putstr("File Sign Error\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void		check_layout(char *buff)
{
	int i;
	int j;
	int width;

	i = 0;
	j = 0;
	width = 0;
	while (buff[i] != '\n')
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			width++;
		i++;
	}
	i++;
	j = 0;
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			j++;
		if (buff[i] == '\n')
		{
			printf("j = %d\n", j);
			if (j != width)
			{
				ft_putstr("layout error\n");
				exit(EXIT_FAILURE);
			}
			j = 0;
		}
		i++;
	}
	printf("width = %d\n", width);
}
