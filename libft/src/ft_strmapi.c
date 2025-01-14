/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:03:43 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// char test(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (((c - 'a' + i) % 26) + 'a');
// 	if (c >= 'A' && c <= 'Z')
// 		return (((c - 'A' + i) % 26) + 'A');
// 	if (c >= '0' && c <= '9')
// 		return (((c - '0' + i) % 10) + '0');
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res_str;
	size_t	i;

	res_str = malloc(ft_strlen(s) + 1);
	if (res_str == NULL)
		return (res_str);
	i = 0;
	while (i < ft_strlen(s))
	{
		res_str[i] = f(i, s[i]);
		i++;
	}
	res_str[i] = 0;
	return (res_str);
}

// int main()
// {
// 	char str[] = "test";
// 	char * res = ft_strmapi(str, test);
// 	printf("%s\n", res);
// 	free(res);
// 	return 0;
// }
