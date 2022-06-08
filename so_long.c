/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/08 19:23:08 by jecolmou         ###   ########.fr       */
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

int	ft_un_alloc(t_data *data)
{
	if (data->map)
		ft_lstclear(&data->map);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->ground)
		mlx_destroy_image(data->mlx_ptr, data->ground);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->charac)
		mlx_destroy_image(data->mlx_ptr, data->charac);
	if (data->collectible)
		mlx_destroy_image(data->mlx_ptr, data->collectible);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	return (1);
}

int	ft_get_images(t_data *data)
{
	int height;
	int width;

	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/GardenBed_Cucumbers_02.xpm", &width, &height);
	if (data->ground == NULL)
	{
		ft_putstr_fd("Error : image\n", 2);
		return (0);
	}
	data->charac = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/Chick_Down.xpm", &width, &height);
	if (data->charac == NULL)
	{
		ft_putstr_fd("Error : image\n", 2);
		return (0);
	}
	data->
	return (1);
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

	ft_bzero(&x, sizeof(t_data));
	if (ft_check_args(argc, argv) == 0)
		return (1);
	if (ft_open_map(argv, &x) == 0)
		return (1);
	close(x.file);
	x.mlx_ptr = mlx_init();
	if (x.mlx_ptr == NULL)
		return (ft_un_alloc(&x));
	if (ft_get_images(&x) == 0)
		return (ft_un_alloc(&x));

	x.win_ptr = mlx_new_window(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window !");
	if (x.win_ptr == NULL)
	{
		free(x.win_ptr);
		return (MLX_ERROR);
	}
	// x.img.mlx_img = mlx_new_image(x.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// x.img.addr = mlx_get_data_addr(x.img.mlx_img, &x.img.bpp, &x.img.line_len, &x.img.endian);
	mlx_loop_hook(x.mlx_ptr, &render, &x);
	mlx_hook(x.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &x);
	mlx_loop(x.mlx_ptr);
	mlx_destroy_display(x.mlx_ptr);
	free(x.mlx_ptr);
	return (0);
}
