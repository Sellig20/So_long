/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:05:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/29 19:14:20 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error :\nInvalid number of arguments\n", 36);
		return (0);
	}
	if (ft_strlen(argv[1]) == 0)
	{
		write(2, "Error :\nInvalid number of arguments\n", 36);
		return (0);
	}
	return (1);
}

int	ft_open_file(char	**argv, t_data *x)
{
	x->file = open(argv[1], O_DIRECTORY);
	if (x->file > 2)
	{
		close(x->file);
		ft_putstr_fd("Error :\nInvalid folder\n", 2);
		return (0);
	}
	if (ft_read_infile(argv[1]) == 1)
		x->file = open(argv[1], O_RDONLY);
	if (x->file == -1)
	{
		ft_putstr_fd("Error :\nInvalid file\n", 2);
		return (0);
	}
	return (1);
}

int	ft_open_map(char **argv, t_data *x)
{
	t_map	*tab;

	tab = NULL;
	if (ft_open_file(argv, x) == 0)
		return (0);
	if (x->file)
	{
		x->str = get_next_line(x->file, 0);
		while (x->str)
		{
			tab = ft_add_back(tab, x->str);
			if (tab == NULL)
			{
				free(x->str);
				return (0);
			}
			x->len++;
			x->str = get_next_line(x->file, 0);
		}
	}
	get_next_line(x->file, 1);
	if (ft_execution_parsing_items(&tab, x) == 0)
	{
		ft_lstclear(&tab);
		return (0);
	}
	if (ft_convert_in_char(&tab, x) == 0)
	{
		ft_lstclear(&tab);
		ft_free_args(x->dtab);
		return (0);
	}
	x->map = tab;
	return (1);
}
