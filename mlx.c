/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:01:54 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/09 19:20:59 by jecolmou         ###   ########.fr       */
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
	return (0);
}

#define X 0
#define Y 1

int	render(t_data *data)
{
	int	i;
	char	*str;
	int	pos[2];

	pos[Y] = 0;
	i = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->map)
	{
		pos[X] = 0;
		// printf("x = %c\n", data->map->x[i]);
		str = data->map->x;
		while (*str)
		{
			if (*str == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, pos[X], pos[Y]);
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

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
