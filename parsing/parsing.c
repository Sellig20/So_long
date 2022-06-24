/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/24 17:35:53 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		ft_execution_parsing_items(t_map **tab, t_data *x)
{
	t_map	*map;

	map = *tab;
	if (ft_execution_rectangle(&map) == 0)
		return (0);
	if (ft_execution_wall(&map) == 0)
		return (0);
	ft_len_xy(&map, x);
	x->count_p = ft_parsing_map_p(&map, x, "P");
	if (ft_return_count_p(x) == 0)
		return (0);
	x->count_e = ft_parsing_map_e(&map, x, "E");
	if (ft_return_count_e(x) == 0)
		return (0);
	while (map)
	{
		x->count_c = ft_parsing_map_c(&map, x, "C");
		map = map->next;
	}
	if (ft_return_count_c(x) == 0)
		return (0);
	return (1);
}

int	ft_execution_rectangle(t_map **tab)
{
	t_map	*map;

	map = *tab;
	while (map)
	{
		if (ft_is_rectangle(&map) == 0)
		{
			write(2, "Error :\nInvalid format map\n", 27);
			return (0) ;
		}
		map = map->next;
	}
	return (1);
}

int		ft_execution_wall(t_map **tab)
{
	t_map	*map;

	map = *tab;
	if (ft_is_wall_last(&map) == 0 || ft_is_wall_first(&map) == 0
		|| ft_is_wall_first_case(&map) == 0 || ft_is_wall_last_case(&map) == 0)
	{
		write(2, "Error :\nNo wall around the rectangle\n", 37);
		return (0);
	}
	return (1);
}

int		ft_read_infile(char *infile)
{
	int		i;

	i = 0;
	if (!(ft_strnstr(&infile[ft_strlen(infile) - 4], ".ber", 4)))
	{
		write(2, "Error :\nInvalid extension for the map\n", 38);
		return (0);
	}
	if (ft_strncmp(infile, ".ber", 4) == 0)
	{
		write(2, "Error :\nInvalid infile\n", 23);
		return (0);
	}
	return (1);
}

int		ft_is_rectangle(t_map **tab)
{
	t_map	*map;
	t_map	*last;
	char	*str;
	int		i;
	int		len;

	map = *tab;
	str = map->x;
	i = 0;
	while (map->next)
	{
		map = map->next;
		last = map;
	}
	while (str[i])
	{
		len = ft_strlen(str);
		if (len != ft_strlen(last->x))
			return (0);
		i++;
	}
	return (1);
}
