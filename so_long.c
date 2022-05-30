/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/30 18:48:04 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data	x;
	t_map	*tab;
	int		len;
	int		i;

	i = 0;
	tab = NULL;
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
			tab = ft_add_back(tab, x.str);
			x.str = get_next_line(x.file, 0);
		}

	}
	while (tab)
	{
		printf("tab = %s\n", tab->map);
		tab = tab->next;
	}
	if (ft_parsing_map(tab) == 0)
			write(2, "Error : missing character\n", 26);
	len = x.index_line;
	return (0);
}

	// printf("tab = %s\n", x.str);
	// 		tab = ft_split(x.str, '\n');
	// 		x.index_line++;
	//
	// 		printf("index = %d\n", x.index_line);
	// 		free(x.str);

///////////////////////////////
// char = 'c'

// char * = "Salut a tous les amis\n"
// char ** = { "Salut a tous les amis\n",
			// "Coucou tout le monde\n",
			// "Comment ca va aujourdhui\n"}
