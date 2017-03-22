/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:43:28 by lchety            #+#    #+#             */
/*   Updated: 2017/03/22 19:45:05 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

char		**split_map(char *buff, t_ml *dna)
{
	char **tb;
	int nb_vect;
	int i;
	int j;

	i = 0;
	j = 0;
	nb_vect = dna->map_width * dna->map_height;

	tb = (char**)ft_memalloc(sizeof(char*) * nb_vect);

	while (buff[i] != '\0')
	{
		j = 0;
		while (ft_isdigit(buff[i]))
		{
			j++;
			i++;
		}
		if (j != 0)
		{
			printf("create_words\n");
		}
		i++;
	}

	return (NULL);
}

void	check_sign(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		//printf("HERE\n");
		if (buff[i] != '\n' && !ft_isdigit(buff[i]) && buff[i] != ' ')
		{
			ft_putstr("File Sign Error\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	check_layout(char *buff)
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
		// printf("boucle\n");
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

void		load_map(char *filename, t_ml *dna)
{
	int fd;
	char buff[USHRT_MAX];
	int ret;

	ret = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("File Error\n");
		exit (EXIT_FAILURE);
	}
	ret = read (fd, buff, USHRT_MAX - 1);
	buff[ret] = '\0';
	check_sign(buff);
	check_layout(buff);

	printf("check_sign : OK\n");
	map_size(dna, buff);
	dna->map = create_map(dna);
	fill_map(buff, dna);
	printf("ta mere la flute\n");
	//fill_map(dna, buff);

}
