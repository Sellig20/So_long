/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:39:55 by jecolmou          #+#    #+#             */
/*   Updated: 2022/06/02 18:25:31 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_infile(char *infile)
{
	int i;

	i = 0;
	while (infile[i])
	{
		if (!(ft_strnstr(infile, ".ber", 1000)))
		{
			write(2, "Error : Invalid extension for the map\n", 38);
			return (0);
		}
		if (ft_strncmp(infile, ".ber", 4) == 0)
		{
			write(2, "Error : Invalid infile\n", 23);
			return (0);
		}
		else
			return (1);
		i++;
	}
	return (1);
}

int	ft_check_doublons_p(t_map **liste)
{
	int i = 0;
	int j;
	t_map *a;
	a = *liste;
	char *str = a->x;
	while (a->next)
	{
		while (str[i])
		{
			j = i + 1;
			while (str[j])
			{
				if (str[i] == 'P' && str[j] == 'P')
					return(0);
				j++;
			}
			i++;
		}
		a = a->next;
	}
	return (1);
}

int	ft_parsing_map_p(t_map **tab, t_data *x, char *c)
{
	t_map *map;

	map = *tab;
	while (map)
	{
		if (ft_check_doublons_p(&map) == 0)
			x->count_p++;
		if ((ft_strncmp(c, "P", 1) == 0 && ft_strnstr(map->x, c, 1000)))
		 	x->count_p++;
		map = map->next;
	}
	return (x->count_p);
}

int	ft_parsing_map_e(t_map **tab, t_data *x, char *c)
{
	t_map *map;

	map = *tab;
	while (map)
	{
		if ((ft_strncmp(c, "E", 1) == 0 && ft_strnstr(map->x, c, 1000)))
		 	x->count_e++;
		map = map->next;
	}
	return (x->count_e);
}

int ft_return_count_e(t_data *x)
{
	if (x->count_e < 1)
	{
		write(2, "Error : missing E character\n", 28);
		return (0);
	}
	else if (x->count_e == 1)
	{
		write(2, "E is here\n", 10);
		return (1);
	}
	return (1);
}

int ft_return_count_p(t_data *x)
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
		write(2, "Error : two or more characters\n", 31);
		return (0);
	}
	return (1);
}

int ft_is_rectangle(t_map **tab, t_data *x) //si ma map est bien un rectangle
{
	t_map *map;
	t_map *last;
	char	*str;
	int i;
	(void)x;
	int len;

	map = *tab;
	str = map->x;
	i = 0;
	while (map->next)
	{
		map = map->next;
		last = map;
	}
	while (str[i])
	{
		len = ft_strlen(str);
		if (len != ft_strlen(last->x))
		 	return (0);
		i++;
	}
	return (1);
}

// int	ft_is_space(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 		{
// 			if (str[i + 1] == ' ' || str[i + 1] == '\0')
// 				return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	ft_is_wall_first(t_map **first)
{
	t_map *ffirst;
	int i = 0;
	ffirst = *first;
	while (ffirst->x[i])
	{
		char *str = ffirst->x;
		if (str[i] == '1' || str[i] == '\n')
		{
				//printf("c bon que des 1\n");
				//return 0;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_wall_first_case(t_map **tab)
{
	t_map *map;

	map = *tab;
	int i = 0;
	while (map)
	{
		if (map->x[i] == '1')
		{
			//
		}
		else
			return (0);
		map = map->next;
	}
	return (1);
}

int	ft_is_wall_last(t_map **tab)
{
	t_map *map;
	t_map *last;
	int i = 0;
	map = *tab;
	while (map->next)
	{
		map = map->next;
		last = map;
	}
	char *strl = last->x;

	i = 0;
	while (last->x[i])
	{
		if (strl[i] == '1' || strl[i] == '\n')
		{
			//coucou
		}
		else
			return (0);
		i++;
	}
	return (1);
}

////segfault en carte invalide a cause des missing P et E a fixer

		// printf("len = %d\n", len);
		// printf("last size = %d\n", ft_strlen(last->x));
	// if ((ft_strncmp(last->x, "1", ft_strlen(last->x)) != 0))
	// 			printf("ya pas qe des 1 ici en bas !\n");
