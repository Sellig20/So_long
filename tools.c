/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:51:54 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/25 19:24:32 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_args(char	**args)
{
	char	**tmp;

	tmp = args;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(args);
}

int		refresh(t_data *data)
{
	usleep(20000);
	render(data);
	return (1);
}

void	ft_display_move(t_data *data)
{
	char	*str;

	str =  ft_itoa(data->move_count);
	ft_putstr_fd("Move = ", 1);
	write(1, str ,ft_int_len(data->move_count));
	write(1, "\n", 1);
	free(str);
}

int		ft_exit_game(t_data *data)
{
	(void)data;
	//mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_un_alloc(data);
	ft_free_args(data->dtab);
	return (1);
}
