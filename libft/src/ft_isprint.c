/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:21:23 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int main()
// {
// 	char c1 = 'f';
// 	char c2 = '3';
// 	char c3 = 'T';
// 	char c4 = '&';
// 	char c5 = ';';
// 	// printf("%s", str);
// 	printf("%d\n", ft_isprint(c1));
// 	printf("%d\n", ft_isprint(c2));
// 	printf("%d\n", ft_isprint(c3));
// 	printf("%d\n", ft_isprint(c4));
// 	printf("%d\n", ft_isprint(c5));
// 	printf("%d\n", ft_isprint(142));
// 	printf("%d\n", ft_isprint(7645));
// 	printf("%d\n", ft_isprint(10));
// 	return 0;
// }
