/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:01:54 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/21 17:47:16 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *x)
{
	(void)x;
	//
	return (0);
}

int	handle_input(int keysym, t_data *x)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(x->mlx_ptr, x->win_ptr);
	return (0);
}

// int handle_keypress(int keysym, t_data *x)
// {
// 	if (keysym == XK_Escape)
// 		mlx_destroy_window(x->mlx_ptr, x->win_ptr);
// 	printf("Keypress : %d\n", keysym);
// 	return (0);
// }

int	handle_keyrelease(int keysym, void *x)
{
	(void)x;
	printf("Keyrelease : %d\n", keysym);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	// if (keysym == XK_Up)
	// {
	// 	ft_move_c_up();
	// }
	return (0);
}

#define X 0
#define Y 1

t_player	*ft_create_player(int i, int j)
{
	t_player	*play;
	t_coor		coord;

	play = malloc(sizeof(t_player));
	coord.x = j;
	coord.y = i;
	play->coord = coord;
	play->dir = -1;
	return (play);
}

int	ft_convert_in_char(t_map **tab, t_data *data)
{
	t_map *map;
	int i = 0;
	map = *tab;
	data->dtab = malloc(sizeof(ft_lstsize(&map) + 1));
	if (data->dtab == NULL)
		return (0);
	while (map)
	{
		data->dtab[i] = map->x;
		map = map->next;
		i++;
	}
	ft_index(data);
	return (1);
}

void	ft_index(t_data *x)
{
	int	i;
	int	j;
	char	**str;

	i = 0;
	str = NULL;
	while (x->dtab[i])
	{
		j = 0;
		while (x->dtab[i][j])
		{
			if (x->dtab[i][j] == 'P')
			{
				x->player = ft_create_player(i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	int	i;
	char	*str;
	int	pos[2];
	int	k;


	k = 0;
	pos[Y] = 0;
	i = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->map)
	{
		pos[X] = 0;
		str = data->map->x;
		while (*str)
		{
			if (*str == '1')
			{
				data->stop_wall[k][0] = pos[X];
				data->stop_wall[k][1] = pos[Y];
				//compte les1. remplis le tableau stop_wall avec ls positions de tous le 1. malloc le stop_wall avec lenombre de 1 dans ta map.
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, pos[X], pos[Y]);
				k++;
			}
			if (*str == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, pos[X], pos[Y]);
			if (*str == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, pos[X], pos[Y] + (128 / 2));
			if (*str == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->charac, pos[X], pos[Y]);
			if (*str == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, pos[X], pos[Y]);
			pos[X] += 128;
			str++;
		}
		pos[Y] += 128;
		data->map = data->map->next;
	}
	return (0);
}

