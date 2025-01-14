/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:49 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// int main()
// {
// 	char *src = "Je m'appel Arthur";
// 	char *test;
// 	test = ft_substr(src, 0, 100);
// 	printf("%s\n", test);
// 	free(test);

// 	char * s = ft_substr("tripouille", 0, 42000);
// 	/* 1 */ printf("str = %s\n", s);
// 	/* 1 */ printf("%d\n", !strcmp(s, "tripouille"));

// 	s = ft_substr("tripouille", 1, 1);
// 	/* 3 */ printf("str = %s\n", s);
// 	free(s);
// 	return 0;
// }