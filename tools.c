/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:51:54 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/24 16:41:29 by jecolmou         ###   ########.fr       */
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

void	ft_display_move(t_data *data)
{
		ft_putstr_fd("move = ", 1);
		write(1, ft_itoa(data->move_count), ft_int_len(data->move_count));
		write(1, "\n", 1);
}
