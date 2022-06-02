/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/02 18:26:46 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	x;
	t_map	*tab;
	int		i;

	x.count_p = 0;
	x.count_e = 0;
	x.len = 0;
	i = 0;
	tab = NULL;
	if (argc != 2)
		return (write(2, "Error : invalid number of arguments.\n", 35));
	if (ft_read_infile(argv[1]) == 1)
		x.file = open(argv[1], O_RDONLY);
	if (x.file)
	{
		x.str = get_next_line(x.file, 0);
		while (x.str)
		{
			tab = ft_add_back(tab, x.str);
			x.len++;
			x.str = get_next_line(x.file, 0);
		}
	}
	x.count_p = ft_parsing_map_p(&tab, &x, "P");
	x.count_e = ft_parsing_map_e(&tab, &x, "E");
	ft_return_count_p(&x);
	ft_return_count_e(&x);
	//t_map *first;
	// if (ft_is_wall_last(&tab) == 0)
	// {
	// 	write(2, "Error : no wall around the rectangle\n", 37);
	// 	return (1);
	// }
	// first = tab;
	// if (ft_is_wall_first(&first) == 0)
	// {
	// 	write(2, "Error : no wall around the rectangle\n", 37);
	// 	return (1);
	// }
	// while (tab->next)
	// {
	// 	if (ft_is_rectangle(&tab, &x) == 0)
	// 	{
	// 		write(2, "Error : Invalid map\n", 20);
	// 		return (1);
	// 	}
	// 	tab = tab->next;
	// }
	if (ft_is_wall_first_case(&tab) == 0)
	{
		write(2, "Error : no wall around the rectangle\n", 37);
		return (1);
	}


	return (0);
}
