/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:45:14 by lchety            #+#    #+#             */
/*   Updated: 2017/06/01 18:15:26 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

void	clear_map(t_ml *dna)
{
	dna->blank = 1;
	draw_map(dna);
	dna->blank = 0;
}

void	map_size(t_ml *dna, char *buff)
{
	int i;

	i = 0;
	dna->map_w = 0;
	dna->map_h = 0;
	while (buff[i] != '\n')
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			dna->map_w++;
		i++;
	}
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			dna->map_h++;
		i++;
	}
}

void	create_map(t_ml *dna)
{
	int i;

	i = -1;
	if (!(dna->map = (int**)ft_memalloc(sizeof(int*) * dna->map_w)))
		exit(EXIT_FAILURE);
	while (++i < dna->map_w)
		if (!(dna->map[i] = (int*)ft_memalloc(sizeof(int) * dna->map_h)))
			exit(EXIT_FAILURE);
}

int		get_z(char **buff)
{
	int		k;
	char	hot_plate[20];

	k = 0;
	ft_bzero(hot_plate, 20);

	while (*buff && k < 20)
	{
		hot_plate[k] = **buff;
		if (k >= 12)
			exit(EXIT_FAILURE);
		if (ft_isdigit(**buff) && (buff[0][1] == ' ' || buff[0][1] == '\n'))
		{
			(*buff)++;
			break;
		}
		k++;
		(*buff)++;
	}
	if (**buff != ' ' && **buff != '\n')
		exit(EXIT_FAILURE);
	return (ft_atoi(hot_plate));
}

void	fill_map(char *buff, t_ml *dna)
{
	int		i;
	int		j;
	int		k;
	int		nb_digit;
	char	hot_plate[20];

	i = -1;
	ft_bzero(hot_plate, 20);
	while (++i < dna->map_h)
	{
		j = -1;
		while (++j < dna->map_w)
		{
			dna->map[j][i] = get_z(&buff);
			z_limits(dna, dna->map[j][i]);
		}
	}
}

void	load_map(char *filename, t_ml *dna)
{
	int fd;
	char buff[USHRT_MAX];
	int ret;
	ret = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("File Error\n");
		exit(EXIT_FAILURE);
	}
	ret = read(fd, buff, USHRT_MAX - 1);
	if (ret == 0)
	{
		ft_putstr("Empty file !\n");
		exit(EXIT_FAILURE);
	}
	buff[ret] = '\0';
	check_map(buff);
	map_size(dna, buff);
	if (dna->map_w < 2)
		exit(EXIT_FAILURE);
	create_map(dna);
	fill_map(buff, dna);
}
