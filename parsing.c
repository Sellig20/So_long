/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/01 15:42:29 by jecolmou         ###   ########.fr       */
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
	int i = 0;
	int j;
	t_map *a;
	a = *liste;
	char *str = a->x;
	while (a->next)
	{
		while (str[i])
		{
			j = i + 1;
			while (str[j])
			{
				//printf("str[i] = %s\n", str);
				//printf("I = %c\n", str[i]);
				if (str[i] == 'P' && str[j] == 'P')
					return(0);
				j++;
			}
			i++;
		}
		a = a->next;
	}
	return (1);
}











// int	ft_check(t_map **liste)
// {
// 	t_map	*save1;
// 	t_map	*save2;
// 	int i;
// 	//int j;
// 	//char *c = "P";

// 	save2 = NULL;
// 	i = 0;
// 	save1 = *liste;
// 	save2 = ft_add_back(save2, save1->x);
// 	while (i < ft_strlen(save2->x))
// 	{
// 		printf("save2 = %c\n", save2->x[i]);
// 		i++;
// 	}
// 	return (1);
// }

int	ft_parsing_map(t_map **tab, t_data *x, char *c)
{
	// t_map *tmp;
	t_map *map;
//	int res;
	int j;
	int size;
	// int i = 0;
	j = 0;
	map = *tab;
	size = ft_lstsize(&map);
	(void)c;
	// while (j < size && map)
	// {
	// 	res = ft_check(&map);
	// 	map = map->next;
	// 	j++;
	// }
	// printf("res = %d\n", res);
	while (map)
	{
		if (ft_check_doublons(&map) == 0)
			x->count_p++;
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
