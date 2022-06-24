/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:33:28 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/24 16:38:37 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_elsif_key_s(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
	data->player->coord.y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
	ft_display_move(data);
}

void	ft_elsif_key_a(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
	data->player->coord.x -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
	ft_display_move(data);
}

void	ft_elsif_key_d(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
	data->player->coord.x += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
	ft_display_move(data);
}

void	ft_elsif_key_w(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
	data->player->coord.y -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
	ft_display_move(data);
}
