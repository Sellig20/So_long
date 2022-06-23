/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:36:57 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/23 22:40:07 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		ft_is_wall_first(t_map **first)
{
	t_map	*ffirst;
	char	*str;
	int		i;

	i = 0;
	ffirst = *first;
	while (ffirst->x[i])
	{
		str = ffirst->x;
		if (str[i] == '1' || str[i] == '\n')
		{
				//
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_wall_last(t_map **tab)
{
	t_map	*map;
	t_map	*last;
	char	*strl;
	int		i;

	map = *tab;
	i = 0;
	while (map->next)
	{
		map = map->next;
		last = map;
	}
	strl = last->x;
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

int		ft_is_wall_first_case(t_map **tab)
{
	t_map	*map;
	int		i;

	map = *tab;
	i = 0;
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

int		ft_is_wall_last_case(t_map **tab)
{
	t_map	*map;
	int		len;

	map = *tab;
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
