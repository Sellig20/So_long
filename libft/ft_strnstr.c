/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:02:43 by jecolmou          #+#    #+#             */
/*   Updated: 2022/05/24 18:42:45 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!needle[j])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && (i + j < len) && needle[j]
			&& haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char *to_find = "Bar";
//     char *str = "Foo Bar Baz";
//     char *str1 = "Mon aiguille arrive ici et coupe le reste de ma string";
//     char *to_find1 = "ici";
//     char *str2 = "pour aiguille vide";
//     char *to_find2 = " ";
//     char *str3 = " ";
//     char *to_find3 = "str_vide";
//     printf("------------exemple 1 -------------\n");
//     printf("\n");
//     printf("String = FooBarBaze \nAiguille = Bar \nreturn(result) = %s\n", ft_strnstr(str, to_find, 100));
//     printf("\n");
//     printf("------------exemple 2 -------------\n");
//     printf("\n");
//     printf("String = Mon aiguille arrive ici et coupe le reste de ma string \nAiguille = ici \nreturn(result) = %s\n", ft_strnstr(str1, to_find1, 1001));
//     printf("\n");
//     printf("------------exemple 3 -------------\n");
//     printf("\n");
//     printf("String = Pour aiguille vide \nAiguille = " " \nreturn(result) = %s\n", ft_strnstr(str2, to_find2, 1002));
//     printf("\n");
//     printf("------------exemple 4 -------------\n");
//     printf("\n");
//     printf("String = " " \nAiguille = " " \nreturn(result) = %s\n", ft_strnstr(str3, to_find3, 1003));
//     return 0;
// }
