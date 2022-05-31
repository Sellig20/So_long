/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/31 17:26:52 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_infile(char *infile)
{
	int i;

	i = 0;
	while (infile[i])
	{
		if (!(ft_strnstr(infile, ".ber", 1000)))
		{
			write(2, "Error : Invalid extension for the map\n", 38);
			return (0);
		}
		if (ft_strncmp(infile, ".ber", 4) == 0)
		{
			write(2, "Error : Invalid infile\n", 23);
			return (0);
		}
		else
			return (1);
		i++;
	}
	return (1);
}

int	ft_check_doublons(t_map **liste)
{
	t_map	*save1;
	t_map	*save2;
	// t_map	*save3;
	int i;

	save2 = NULL;
	i = 0;
	save1 = *liste;
	save2 = ft_add_back(save2, save1->x);

		while (i < ft_strlen(save2->x))
		{
			printf("save2 = %c\n", save2->x[i]);
			i++;
		}


	// save3 = NULL;
	// save3 = ft_add_back(save3, save1->x);
	// while (save3->x[i])
	// {
	// 	while (save2->x[i])
	// 	{
	// 		//if (save3->x[i] == save2->x[i])
	// 			printf("doublon : %c\n", save2->x[i]);
	// 		save2->x[i]++;
	// 	}
	// 	save3->x[i]++;
	// }
	return (1);
}

int	ft_parsing_map(t_map **tab, t_data *x, char *c)
{
	t_map *map;
	int res;
	int j;
	int size;
	j = 0;
	map = *tab;
	size = ft_lstsize(&map);

	printf("size = %d\n", size);
	while (j < size && map)
	{
		res = ft_check_doublons(&map);
		printf("j = %d\n", j);
		map = map->next;
		j++;
	}
	//printf("res = %d\n", res);
	while (map)
	{
		if ((ft_strncmp(c, "P", 1) == 0 && ft_strnstr(map->x, c, 1000)))
			x->count_p++;
		map = map->next;
	}
	return (x->count_p);
}

int ft_return_count(int count)
{
	if (count < 1)
	{
		write(2, "Error : missing character\n", 26);
		return (0);
	}
	else if (count == 1)
	{
		write(2, "P is here\n", 10);
		return (1);
	}
	else
	{
		write(2, "Error : two or more characters\n", 31);
		return (0);
	}
	return (1);
}
