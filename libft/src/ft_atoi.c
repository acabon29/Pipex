/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:57:02 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	signe;

	nb = 0;
	signe = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	while (is_num(*str))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * signe);
}

// int main()
// {
// 	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
// 	printf("%d\n", atoi(" ---+--+1234ab567"));
// 	printf("%d\n", ft_atoi(" +1234ab567"));
// 	printf("%d\n", atoi(" +1234ab567"));
// 	printf("%d\n", ft_atoi(" -1234ab567"));
// 	printf("%d\n", atoi(" -1234ab567"));
// 	printf("%d\n", ft_atoi(" -ab567"));
// 	printf("%d\n", atoi(" -ab567"));
// 	printf("%d\n", ft_atoi(" "));
// 	printf("%d\n", atoi(" "));
// 	printf("%d\n", ft_atoi(" +"));
// 	printf("%d\n", atoi(" +"));
// 	printf("%d\n", ft_atoi("    2147483647"));
// 	printf("%d\n", atoi("    2147483647"));
// 	printf("%d\n", ft_atoi(" -2147483648"));
// 	printf("%d\n", atoi(" -2147483648"));
// 	return 0;
// }