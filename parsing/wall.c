/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:36:57 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/03 12:37:42 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_wall_first(t_map **first)
{
	t_map *ffirst;
	int i = 0;
	ffirst = *first;
	while (ffirst->x[i])
	{
		char *str = ffirst->x;
		if (str[i] == '1' || str[i] == '\n')
		{
				//printf("c bon que des 1\n");
				//return 0;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_wall_last(t_map **tab)
{
	t_map *map;
	t_map *last;
	int i = 0;
	map = *tab;
	while (map->next)
	{
		map = map->next;
		last = map;
	}
	char *strl = last->x;

	i = 0;
	while (last->x[i])
	{
		if (strl[i] == '1' || strl[i] == '\n')
		{
			//coucou
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_wall_first_case(t_map **tab)
{
	t_map *map;

	map = *tab;
	int i = 0;
	while (map)
	{
		if (map->x[i] == '1')
		{
			//
		}
		else
			return (0);
		map = map->next;
	}
	return (1);
}

int	ft_is_wall_last_case(t_map **tab)
{
	t_map *map;

	map = *tab;
	int len;
	len = ft_strlen(map->x);
	while (map)
	{
		if (map->x[len - 2] == '1')
		{
			//
		}
		else
			return (0);
		map = map->next;
	}
	return (1);
}
