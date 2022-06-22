/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/22 18:03:02 by jecolmou         ###   ########.fr       */
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
		ft_putstr_fd("Error : image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	return (1);
}

void ft_len_x(t_map **tab, t_data *data)
{
	int i;
	char	*str;
	t_map *map;

	i = 0;
	map = *tab;
	str = map->x;
	while (str[i])
	{
		data->len_x = ft_strlen(str);
		i++;
	}
	data->len_x--;
}

void ft_len_y(t_map **tab, t_data *data)
{
	t_map *map;

	map = *tab;
	data->len_y = ft_lstsize(&map);
}

int	refresh(t_data *data)
{
	usleep(20000);
	render(data);
	return (1);
}

int	is_accessible(t_data *data, char c, int x, int y)
{
	(void)y;
	(void)x;
	if (c != '0' && c != 'C' && !(c == 'E' && data->item_count == 0))
		return (0);
	// else if (c == 'E')
	// {
	// 	// data->map[y][x] = 'F';
	// 	return (0);
	// }
	return (1);
}

int	deal_key(int key, t_data *data)
{
		if (key == 119 && is_accessible(data, data->dtab[data->player->coord.y - 1][data->player->coord.x], data->player->coord.x, data->player->coord.y - 1)) //W
		{
			// printf("x = %d\n", data->player->coord.x);
			// printf("y = %d\n", data->player->coord.y);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
			data->player->coord.y -= 1;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
		}
		else if (key == 115 && is_accessible(data, data->dtab[data->player->coord.y + 1][data->player->coord.x], data->player->coord.x, data->player->coord.y + 1)) //S
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
			data->player->coord.y += 1;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
		}
		else if (key == 97 && is_accessible(data, data->dtab[data->player->coord.y][data->player->coord.x - 1], data->player->coord.x - 1, data->player->coord.y)) //A
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
			data->player->coord.x -= 1;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
		}
		else if (key == 100 && is_accessible(data, data->dtab[data->player->coord.y][data->player->coord.x + 1], data->player->coord.x + 1, data->player->coord.y)) //D
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->player->coord.x * 128, data->player->coord.y * 128);
			data->player->coord.x += 1;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, data->player->coord.x * 128, data->player->coord.y * 128);
		}
	return (1);
}

int main(int argc, char **argv)
{
	t_data	x;

	ft_bzero(&x, sizeof(t_data));

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
	// mlx_loop_hook(x.mlx_ptr, &render, &x);
	mlx_hook(x.win_ptr, 2, 1L << 0, deal_key, &x);
	// mlx_hook(x.mlx->win_ptr, 17, 0L, exit_game, &x);
	mlx_loop_hook(x.mlx_ptr, refresh, &x);
	// mlx_hook(x.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &x);
	mlx_loop(x.mlx_ptr);
	// mlx_destroy_display(x.mlx_ptr);
	// free(x.mlx_ptr);
	return (0);
}
