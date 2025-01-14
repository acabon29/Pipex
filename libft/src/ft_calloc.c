/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:01:53 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res_val;

	if (size != 0 && nmemb > ULONG_MAX / size)
		return (NULL);
	res_val = malloc(nmemb * size);
	if (res_val == NULL)
		return (NULL);
	ft_bzero(res_val, nmemb * size);
	return (res_val);
}

// int main()
// {
// 	char *test;
// 	size_t nmemb = 4;
// 	size_t size = 10;
// 	test = ft_calloc(0, 0);
// 	// test = calloc(0, 0);
// 	printf("%s\n", test);

// 	if (test == NULL)
// 	{
// 		printf("erreur2");
// 		return 0;
// 	}

// 	size_t i = 0;
// 	while (i < nmemb * size)
// 	{
// 		if (((char *)test)[i])
// 		{
// 			printf("erreur2");
// 		}
// 		i++;
// 	}
// 	printf("tt bon");
// 	free(test);
// 	return 0;
// }
