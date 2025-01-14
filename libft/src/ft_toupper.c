/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:14:52 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (is_alpha(c))
		c -= 32;
	return (c);
}

// int main()
// {
// 	char test1 = 'a';
// 	char test2 = 'F';
// 	char test3 = '6';
// 	printf("test1 = %c\n", ft_toupper(test1));
// 	printf("test2 = %c\n", ft_toupper(test2));
// 	printf("test3 = %c\n", ft_toupper(test3));
// 	return 0;
// }
