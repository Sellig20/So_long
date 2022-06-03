/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/03 15:07:09 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_execution_parsing(t_map **tab, t_data *x)
{
	t_map *map;

	map = *tab;
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

void	ft_test(t_map **tab, t_data *x)
{
	t_map *map;

	map = *tab;
	while (map)
	{
		if (ft_is_rectangle(&map, x) == 0)
		{
			write(2, "Error : Invalid map\n", 20);
			return ;
		}
		map = map->next;
	}
}
	//
	//t_map *first;
	// if (ft_is_wall_last(tab) == 0)
	// {
	// 	write(2, "Error : no wall around the rectangle\n", 37);
	// 	return (1);
	// }
	// first = tab;
	// if (ft_is_wall_first(first) == 0)
	// {
	// 	write(2, "Error : no wall around the rectangle\n", 37);
	// 	return (1);
	// }

	// if (ft_is_wall_first_case(tab) == 0)
	// {
	// 	write(2, "Error : no wall around the rectangle\n", 37);
	// 	return (1);
	// }
	// if (ft_is_wall_last_case(tab) == 0)
	// {
	// 	write(2, "Error : no wall around the rectangle\n", 37);
	// 	return (1);
	// }


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

int ft_is_rectangle(t_map **tab, t_data *x)
{
	t_map *map;
	t_map *last;
	char	*str;
	int i;
	(void)x;
	int len;

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

////segfault en carte invalide a cause des missing P et E a fixer

		// printf("len = %d\n", len);
		// printf("last size = %d\n", ft_strlen(last->x));
	// if ((ft_strncmp(last->x, "1", ft_strlen(last->x)) != 0))
	// 			printf("ya pas qe des 1 ici en bas !\n");
