/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:04:22 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] == little[j]
			&& j < len_little && i + j < len)
			j++;
		if (j == len_little)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

//flag -lbsd

// int	main ()
// {
// 	char str1[] = "dfgghjkl;'ltestkjtsthg";
// 	char to_find[] = "fdrftghjk";
// 	char to_find2[] = "test";
// 	char to_find3[] = "";
// 	printf("%s\n", ft_strnstr(str1, to_find, 10));
// 	printf("%s\n", ft_strnstr(str1, to_find, 40));
// 	printf("%s\n", ft_strnstr(str1, to_find2, 10));
// 	printf("%s\n", ft_strnstr(str1, to_find2, 40));
// 	printf("%s\n", ft_strnstr(str1, to_find3, 40));
// 	// printf("%s\n", strnstr(str1, to_find, len));
// 	return 0;
// }