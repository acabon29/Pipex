/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:21:23 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	return (is_alpha(c) || is_alphamaj(c));
}

// int main()
// {
// 	char c1 = 'f';
// 	char c2 = '3';
// 	char c3 = 'T';
// 	char c4 = '&';
// 	char c5 = ';';
// 	// printf("%s", str);
// 	printf("%d\n", ft_isalpha(c1));
// 	printf("%d\n", ft_isalpha(c2));
// 	printf("%d\n", ft_isalpha(c3));
// 	printf("%d\n", ft_isalpha(c4));
// 	printf("%d\n", ft_isalpha(c5));
// 	return 0;
// }
