/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:35:48 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// void	test2(unsigned int i, char *c)
// {
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = (my_abs((*c - 'a' - i) % 26) + 'a');
// 	if (*c >= 'A' && *c <= 'Z')
// 		*c = (my_abs((*c - 'A' - i) % 26) + 'A');
// 	if (*c >= '0' && *c <= '9')
// 		*c = (my_abs((*c - '0' - i) % 10) + '0');
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = 0;
}

// int main()
// {
// 	char str[] = "test";
// 	ft_striteri(str, test2);
// 	printf("%s\n", str);
// 	return 0;
// }