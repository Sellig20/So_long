/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/26 18:43:12 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	x;
	char	**tab;
	int		len;
	int		i;

	tab = NULL;
	i = 0;
	x.index_line = 0;
	if (argc != 2)
		return (write(2, "Error : invalid number of arguments.\n", 35));
	if (ft_read_infile(argv[1]) == 1)
		x.file = open(argv[1], O_RDONLY);
	if (x.file)
	{
		printf("file = %d\n", x.file);
		x.str = get_next_line(x.file, 0);
		while (x.str)
		{
			tab = ft_split(x.str, '\n');
			x.index_line++;

			printf("index = %d\n", x.index_line);
			printf("tab = %s\n", tab[i]);
			ft_parsing_map(tab);
			free(x.str);
			x.str = get_next_line(x.file, 0);

		}
		len = x.index_line;
		printf("len = %d\n", len);
	}
	return (0);
}


