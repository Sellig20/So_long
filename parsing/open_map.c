/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:05:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/04 17:02:28 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_initialise(t_data *x)
{
	x->count_p = 0;
	x->count_e = 0;
	x->count_c = 0;
	x->len = 0;
	x->file = 0;
}

int	ft_check_args(int argc, char **argv)
{
	if (ft_strlen(argv[1]) == 0)
		return (0);
	if (argc != 2)
	{
		write(2, "Error : invalid number of arguments\n", 36);
		return (0);
	}
	return (1);
}

int	ft_open_map(char **argv, t_data *x)
{
	t_map	*tab;
	int		i;

	tab = NULL;
	i = 0;
	ft_initialise(x);
	if (ft_read_infile(argv[1]) == 1)
		x->file = open(argv[1], O_RDONLY);
	else
		return (0);
	if (x->file)
	{
		x->str = get_next_line(x->file, 0);
		while (x->str)
		{
			tab = ft_add_back(tab, x->str);
			x->len++;
			x->str = get_next_line(x->file, 0);
		}
	}
	get_next_line(x->file, 1);
	ft_execution_parsing_items(&tab, x);
	ft_lstclear(&tab);
	return (1);
}
