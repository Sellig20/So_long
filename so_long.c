/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/08 14:32:30 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	create(t_data *data)
{
	int	i;
	int	j;
	t_data x;

	images(&x, map);
	return (x);
}

void	images(t_data *data, t_map *map)
{
	world->bg = mlx_xpm_file_to_image(data->mlx_ptr, data->win_ptr, "./texture/GardenBed_Cucumbers_02.xpm", &map->height, &map->width);
}

void	display_map(t_data *data, int i, int j)
{
	if (data.map->x[i] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->bg, j * 60, i * 60);
	}
}

int main(int argc, char **argv)
{
	t_data	x;
	t_data mapi;
	ft_check_args(argc, argv);
	ft_open_map(argv, &x);
	close(x.file);

	x.mlx_ptr = mlx_init();
	if (x.mlx_ptr == NULL)
		return (MLX_ERROR);
	x.win_ptr = mlx_new_window(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window !");
	if (x.win_ptr == NULL)
	{
		free(x.win_ptr);
		return (MLX_ERROR);
	}
	// x.img.mlx_img = mlx_new_image(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// x.img.addr = mlx_get_data_addr(x.img.mlx_img, &x.img.bpp, &x.img.line_len, &x.img.endian);
	mapi = create(x);
	mlx_loop_hook(x.mlx_ptr, &render, &x);
	mlx_hook(x.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &x);
	mlx_loop(x.mlx_ptr);
	mlx_destroy_display(x.mlx_ptr);
	free(x.mlx_ptr);
	return (0);
}
