/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:36:41 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/24 17:39:15 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_accessible(t_data *data, char c, int x, int y)
{
	if (c != '0' && c != 'C' && c != 'D' && c != 'P' && !(c == 'E' && data->count_c == 0))
		return (0);
	else if (c == 'C')
	{
		data->count_c--;
		printf("collectible a get : %d\n", data->count_c);
		data->dtab[y][x] = 'D';
		return (1);
	}
	else if (c == 'E' && data->count_c == 0)
		exit(0);
	data->move_count++;
	return (1);
}

int		deal_key(int key, t_data *data)
{
	if (key == 119 && is_accessible(data, data->dtab[data->player->coord.y - 1][data->player->coord.x],
	 data->player->coord.x, data->player->coord.y - 1)) //W
		ft_elsif_key_w(data);
	else if (key == 115 && is_accessible(data, data->dtab[data->player->coord.y + 1][data->player->coord.x],
	 data->player->coord.x, data->player->coord.y + 1)) //S
		ft_elsif_key_s(data);
	else if (key == 97 && is_accessible(data, data->dtab[data->player->coord.y][data->player->coord.x - 1],
	 data->player->coord.x - 1, data->player->coord.y)) //A
		ft_elsif_key_a(data);
	else if (key == 100 && is_accessible(data, data->dtab[data->player->coord.y][data->player->coord.x + 1],
	 data->player->coord.x + 1, data->player->coord.y)) //D
		ft_elsif_key_d(data);
	else if (key == 65307)
		exit(0);
	return (1);
}
