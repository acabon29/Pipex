/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:21:23 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	return (is_num(c));
}

// int main()
// {
// 	char c1 = 'f';
// 	char c2 = '3';
// 	char c3 = 'T';
// 	char c4 = '&';
// 	char c5 = ';';
// 	// printf("%s", str);
// 	printf("%d\n", ft_isdigit(c1));
// 	printf("%d\n", ft_isdigit(c2));
// 	printf("%d\n", ft_isdigit(c3));
// 	printf("%d\n", ft_isdigit(c4));
// 	printf("%d\n", ft_isdigit(c5));
// 	printf("%d\n", ft_isdigit(142));
// 	printf("%d\n", ft_isdigit(7645));
// 	printf("%d\n", ft_isdigit(10));
// 	return 0;
// }
