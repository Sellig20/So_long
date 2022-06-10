/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/10 17:50:41 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_execution_parsing_items(t_map **tab, t_data *x)
{
	t_map	*map;

	map = *tab;
	ft_execution_rectangle(&map);
	ft_execution_wall(&map);
	ft_len_xy(&map, x);
	x->count_p = ft_parsing_map_p(&map, x, "P");
	ft_return_count_p(x);
	x->count_e = ft_parsing_map_e(&map, x, "E");
	ft_return_count_e(x);
	while (map)
	{
		x->count_c = ft_parsing_map_c(&map, x, "C");
		map = map->next;
	}
	ft_return_count_c(x);
}

void	ft_len_xy(t_map **tab, t_data *x)
{
	t_map *map;

	map = *tab;
	ft_len_x(&map, x);
	ft_len_y(&map, x);
	if (x->len_x > 20)
	{
		ft_putstr_fd("Error : wrong width\n", 2);
		return ;
	}
	if (x->len_y > 11)
	{
		ft_putstr_fd("Error : wrong height\n", 2);
		return ;
	}
}

void	ft_execution_rectangle(t_map **tab)
{
	t_map	*map;

	map = *tab;
	if (ft_is_rectangle(&map) == 0)
	{
		write(2, "Error : Invalid format map\n", 27);
		return ;
	}
}

void	ft_execution_wall(t_map **tab)
{
	t_map	*map;

	map = *tab;
	if (ft_is_wall_last(&map) == 0 || ft_is_wall_first(&map) == 0
		|| ft_is_wall_first_case(&map) == 0 || ft_is_wall_last_case(&map) == 0)
	{
		write(2, "Error : no wall around the rectangle\n", 37);
		return ;
	}
}

int	ft_read_infile(char *infile)
{
	int	i;

	i = 0;
	if (!(ft_strnstr(&infile[ft_strlen(infile) - 4], ".ber", 4)))
	{
		write(2, "Error : Invalid extension for the map\n", 38);
		return (0);
	}
	if (ft_strncmp(infile, ".ber", 4) == 0)
	{
		write(2, "Error : Invalid infile\n", 23);
		return (0);
	}
	return (1);
}

int	ft_is_rectangle(t_map **tab)
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
