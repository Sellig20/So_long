/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/24 13:55:47 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_infile(char *infile)
{
	int i;

	i = 0;
	while (infile[i])
	{
		if (!(ft_strnstr(&infile[i], ".ber", 4)))
		{
			write(2, "Error : Invalid extension for the map", 37);
			return (0);
		}
		if (ft_strncmp(infile, ".ber", 4) == 0)
		{
			write(2, "errror appelez Kwame svp\n", 25);
			return (0);
		}
	}
	return (1);
}

