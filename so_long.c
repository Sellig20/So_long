/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/09 19:58:51 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*create(t_data *data)
{
	ft_get_images(data);
	return (data);
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

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/GardenBed_Cucumbers_02.xpm", &width, &height);
	if (data->wall == NULL)
	{
		ft_putstr_fd("Error : image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->charac = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/Chick_Down.xpm", &width, &height);
	if (data->charac == NULL)
	{
		ft_putstr_fd("Error : image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/Radish.xpm", &width, &height);
	if (data->collectible == NULL)
	{
		ft_putstr_fd("Error : image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/Hole.xpm", &width, &height);
	if (data->exit == NULL)
	{
		ft_putstr_fd("Error : image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, "./texture/GardenBed_Carrots_01.xpm", &width, &height);
	if (data->ground == NULL)
	{
		ft_putstr_fd("error : image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	return (1);
}

// void	display_map(t_data *data, int i, int j)
// {
// 	if (data->map->x[i] == '0')
// 	{
// 		printf("un zero trouve !! \n");
// 		//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, j * 60, i * 60);
// 	}
// }

int ft_len_x(t_data *data)
{
	int i;
	char	*str;

	i = 0;
	str = data->map->x;
	while (str[i])
	{
		data->len_x = ft_strlen(str);
		i++;
	}
	printf("str[i] = %d\n", data->len);
	return (data->len_x);
}

int ft_len_y(t_data *data)
{
	data->len_y = ft_lstsize(&data->map);
	return (data->len_y);
}

int main(int argc, char **argv)
{
	t_data	x;

	ft_bzero(&x, sizeof(t_data));
	if (argc != 2)
	{
		write(2, "Error : invalid number of arguments\n", 36);
		return (1);
	}
	if (ft_check_args(argc, argv))
		return (1);
	if (ft_open_map(argv, &x) == 0)
		return (1);
	close(x.file);
	x.mlx_ptr = mlx_init();
	if (x.mlx_ptr == NULL)
		return (ft_un_alloc(&x));
	if (ft_get_images(&x) == 0)
		return (ft_un_alloc(&x));
	x.win_ptr = mlx_new_window(x.mlx_ptr, x.len_x * 128, x.len_y * 128, "So_long.c");
	if (x.win_ptr == NULL)
	{
		free(x.win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(x.mlx_ptr, &render, &x);
	printf("coucou\n");
	mlx_hook(x.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &x);
	mlx_loop(x.mlx_ptr);
	mlx_destroy_display(x.mlx_ptr);
	free(x.mlx_ptr);
	return (0);
}
