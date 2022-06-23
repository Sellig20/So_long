/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:05:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/23 19:03:54 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error : invalid number of arguments\n", 36);
		return (0);
	}
	if (ft_strlen(argv[1]) == 0)
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
			if (tab == NULL)
			{
				ft_lstclear(&tab);
				return (0);
			}
			x->len++;
			x->str = get_next_line(x->file, 0);
		}
	}
	get_next_line(x->file, 1);
	if (ft_execution_parsing_items(&tab, x) == 0)
		return (0);
	ft_convert_in_char(&tab, x);
	x->map = tab;
	return (1);
}
