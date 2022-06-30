/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:05:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/30 13:42:06 by jecolmou         ###   ########.fr       */
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

void	ft_opop(t_map *tab, t_map *save, t_data *x)
{
	while (x->str)
	{
		tab = ft_add_back(tab, x->str);
		if (tab == NULL)
		{
			free(x->str);
			get_next_line(x->file, 1);
			ft_lstclear(&save);
			return ;
		}
		save = tab;
		x->len++;
		x->str = get_next_line(x->file, 0);
	}
}
//x->len++ btw save = tab && x->str = gnl(str, 0);

int	ft_open_map(char **argv, t_data *x)
{
	t_map	*tab;
	t_map	*save;

	tab = NULL;
	save = NULL;
	if (ft_open_file(argv, x) == 0)
		return (0);
	if (x->file)
	{
		x->str = get_next_line(x->file, 0);
		if (!x->str)
		{
			get_next_line(x->file, 1);
			return (0);
		}
		while (x->str)
		{
			tab = ft_add_back(tab, x->str);
			if (tab == NULL)
			{
				free(x->str);
				get_next_line(x->file, 1);
				ft_lstclear(&save);
				return (0);
			}
			save = tab;
			x->str = get_next_line(x->file, 0);
		}
	}
	get_next_line(x->file, 1);
	if (ft_execution_parsing_items(&tab, x) == 0)
		return (ft_lstclear(&tab), 0);
	if (ft_convert_in_char(&tab, x) == 0)
		return (ft_lstclear(&tab), 0);
	x->map = tab;
	return (1);
}
