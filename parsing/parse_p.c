/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:31:30 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/04 17:29:37 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_parsing_map_p(t_map **tab, t_data *x, char *c)
{
	t_map	*map;

	map = *tab;
	while (map)
	{
		if (ft_check_doublons_p(&map) == 0)
		{
			x->count_p++;
		}
		if ((ft_strncmp(c, "P", 1) == 0 && ft_strnstr(map->x, c, 1000)))
		{
			x->count_p++;
		}
		map = map->next;
	}
	return (x->count_p);
}

int	ft_check_doublons_p(t_map **liste)
{
	t_map	*a;
	char	*str;
	int		i;
	int		j;

	a = *liste;
	str = a->x;
	i = 0;
	while (a->next)
	{
		while (str[i])
		{
			j = i + 1;
			while (str[j])
			{
				if (str[i] == 'P' && str[j] == 'P')
					return (0);
				j++;
			}
			i++;
		}
		a = a->next;
	}
	return (1);
}

int	ft_return_count_p(t_data *x)
{
	if (x->count_p < 1)
	{
		write(2, "Error : missing P character\n", 28);
		return (0);
	}
	else if (x->count_p == 1)
	{
		write(2, "P is here\n", 10);
		return (1);
	}
	else
	{
		write(2, "Error : two or more P characters\n", 33);
		return (0);
	}
	return (1);
}
