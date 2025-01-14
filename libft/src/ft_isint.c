/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:28:19 by acabon            #+#    #+#             */
/*   Updated: 2025/01/07 15:17:04 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isint(char *str)
{
	long	nb;
	int		i;
	int		sign;

	sign = 1;
	nb = 0;
	i = 0;
	if (str[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_SUCCESS);
		nb = (nb * 10) + str[i] - '0';
		if ((nb > 2147483648 && sign == -1) || (nb > 2147483647 && sign == 1))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}
