/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:24:18 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 13:27:50 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			len += ft_putnbr_fd(n / 10, fd);
			c = -(n % 10) + '0';
			len += write(fd, &c, 1);
			return (len);
		}
		len += write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	len += write(fd, &c, 1);
	return (len);
}

// int main()
// {
// 	int fd;
// 	fd = open("file_test", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	// ft_putnbr_fd(-42, fd);
// 	ft_putnbr_fd(-2147483648, fd);
// 	// ft_putnbr_fd(-214748, fd);
// 	close(fd);
// 	return 0;
// }