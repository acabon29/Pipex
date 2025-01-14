/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:19:22 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL || dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

//		((unsigned char *)s)[i] = (unsigned char)c;

// int main()
// {
// 	char dest2[] = "test";
// 	char dest[] = "test";
// 	char *src = "tehgfdh";
// 	size_t size = 10;
// 	memcpy(dest, src, size);
// 	ft_memcpy(dest, NULL, 0);
// 	printf("%s\n", dest);
// 	printf("%s\n", dest2);
// 	return 0;
// }