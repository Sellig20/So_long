/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:05:16 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/25 19:24:45 by jecolmou         ###   ########.fr       */
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

void	ft_open_file(char	**argv, t_data *x)
{
	if (ft_read_infile(argv[1]) == 1)
		x->file = open(argv[1], O_RDONLY);
	else
		return ;
}

int	ft_open_map(char **argv, t_data *x)
{
	t_map	*tab;

	tab = NULL;
	ft_open_file(argv, x);
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
			//free(x->str);
			x->str = get_next_line(x->file, 0);
		}
		//free(x->str);
	}
	get_next_line(x->file, 1);
	if (ft_execution_parsing_items(&tab, x) == 0)
	{
		ft_lstclear(&tab);
		return (0);
	}
	ft_convert_in_char(&tab, x);
	//x->map = malloc(sizeof(t_map) * x->len_x);
	x->map = tab;
	ft_lstclear(&tab);
	return (1);
}
