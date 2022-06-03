/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/03 18:08:33 by jecolmou         ###   ########.fr       */
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
	if (ft_strlen(argv[1]) == 0)
		return (1);
	if (argc != 2)
		return (write(2, "Error : invalid number of arguments.\n", 35));
	if (ft_read_infile(argv[1]) == 1)
		x.file = open(argv[1], O_RDONLY);
	else
		return (1);
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
	ft_execution_parsing_items(&tab, &x);
	return (0);
}
