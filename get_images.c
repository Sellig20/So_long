/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:30:49 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/24 17:32:51 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_get_images(t_data *data)
{
	int		height;
	int		width;

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
	 "./texture/GardenBed_Cucumbers_02.xpm", &width, &height);
	if (data->wall == NULL)
	{
		ft_putstr_fd("Error :\nWall image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->charac = mlx_xpm_file_to_image(data->mlx_ptr,
	 "./texture/Chick_Down.xpm", &width, &height);
	if (data->charac == NULL)
	{
		ft_putstr_fd("Error :\nCharacter image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	if (ft_get_images_annex(data, height, width) == 0)
		return (0);
	return (1);
}

int		ft_get_images_annex(t_data *data, int height, int width)
{
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
	 "./texture/Radish.xpm", &width, &height);
	if (data->collectible == NULL)
	{
		ft_putstr_fd("Error :\nCollectible image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
	 "./texture/Hole.xpm", &width, &height);
	if (data->exit == NULL)
	{
		ft_putstr_fd("Error :\nExit image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr,
	 "./texture/GardenBed_Carrots_01.xpm", &width, &height);
	if (data->ground == NULL)
	{
		ft_putstr_fd("Error :\nGround image\n", 2);
		ft_un_alloc(data);
		return (0);
	}
	return (1);
}
