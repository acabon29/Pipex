/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:32:07 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = NULL;
	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)&(s[ft_strlen(s)]));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			last = (char *)&(s[i]);
		i++;
	}
	return (last);
}

// int	main ()
// {
// 	char *str1 = "test1";
// 	char c1 = 's';
// 	char c2 = 't';
// 	char c3 = 0;
// 	char c4 = 'u';
// 	printf("%s\n", ft_strrchr(str1, c1));
// 	printf("%s\n", ft_strrchr(str1, c2));
// 	printf("%s\n", ft_strrchr(str1, c3));
// 	printf("%s\n", ft_strrchr(str1, c4));
// 	return 0;
// }