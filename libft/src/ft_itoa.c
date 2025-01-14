/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:05:33 by acabon            #+#    #+#             */
/*   Updated: 2025/01/07 15:12:51 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	my_pow(int nb, int pow)
{
	int	i;
	int	res;

	res = 1;
	i = pow;
	while (i != 0)
	{
		res *= nb;
		i--;
	}
	return (res);
}

int	count_digits(int n)
{
	int	cmp;

	cmp = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n /= 10;
			cmp++;
		}
		n = -n;
	}
	if (n == 0)
		return (EXIT_FAILURE);
	while (n > 0)
	{
		n /= 10;
		cmp++;
	}
	return (cmp);
}

void	neg_nb(int *n, int *i, char **str_res)
{
	int	numb;

	if ((*n) < 0)
	{
		(*str_res)[(*i)++] = '-';
		if ((*n) == -2147483648)
		{
			numb = my_abs((*n) / my_pow(10, count_digits(*n) - 1));
			(*str_res)[(*i)++] = numb + '0';
			(*n) %= my_pow(10, count_digits(*n) - 1);
		}
		(*n) = -(*n);
	}
}

char	*ft_itoa(int n)
{
	char	*str_res;
	int		i;

	str_res = malloc(count_digits(n) + 1 + (n < 0));
	if (str_res == NULL)
		return (NULL);
	i = 0;
	neg_nb(&n, &i, &str_res);
	i += count_digits(n);
	str_res[i--] = 0;
	if (n == 0)
		str_res[i--] = n + '0';
	while (n > 0 && i >= 0)
	{
		str_res[i--] = n % 10 + '0';
		n /= 10;
	}
	return (str_res);
}

// int main()
// {
// 	char *test;
// 	test = ft_itoa(12);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(0);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(10);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(1000);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(-2147483648);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(-3648);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(1);
// 	printf("res = %s\n", test);
// 	free(test);
// 	test = ft_itoa(9);
// 	printf("res = %s\n", test);
// 	free(test);

// 	int n;
// 	char *d;
// 	for (int i = 0; i < 2000; i++)
// 	{
// 		n = rand();
// 		d = ft_itoa(n);
// 		// if (atoi(d) != n)
// 		printf("%d %s\n", n, d);
// 	}

// 	return 0;
// }
