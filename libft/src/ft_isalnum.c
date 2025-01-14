/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:21:23 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h" 

int	ft_isalnum(int c)
{
	return (is_alpha(c) || is_alphamaj(c) || is_num(c));
}

// int main()
// {
// 	char c1 = 'f';
// 	char c2 = '3';
// 	char c3 = 'T';
// 	char c4 = '&';
// 	char c5 = ';';
// 	// printf("%s", str);
// 	printf("%d\n", ft_isalnum(c1));
// 	printf("%d\n", ft_isalnum(c2));
// 	printf("%d\n", ft_isalnum(c3));
// 	printf("%d\n", ft_isalnum(c4));
// 	printf("%d\n", ft_isalnum(c5));
// 	return 0;
// }