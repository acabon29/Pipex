/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:42:31 by acabon            #+#    #+#             */
/*   Updated: 2025/01/28 16:01:48 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cmp_word(const char *str, char sep)
{
	int	nb;
	int	cmp;

	if (str == NULL)
		return (-1);
	nb = 0;
	cmp = 1;
	while (*str)
	{
		while (*str && *str == sep)
		{
			str++;
			cmp = 1;
		}
		if (*str && cmp == 1)
		{
			cmp = 0;
			nb++;
		}
		else if (*str)
			str++;
	}
	return (nb);
}

static int	ft_cmp_letters(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab_str;

	tab_str = (char **)malloc((ft_cmp_word(s, c) + 1) * sizeof(char *));
	if (tab_str == NULL || ft_cmp_word(s, c) == -1)
		return (free(tab_str), NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab_str[i] = (char *)malloc(ft_cmp_letters(s, c) + 1);
			if (tab_str[i] == NULL)
				return (free_tabn((void **)tab_str, i - 1), NULL);
			j = 0;
			while (*s && *s != c)
				tab_str[i][j++] = *s++;
			tab_str[i++][j] = 0;
		}
	}
	tab_str[i] = 0;
	return (tab_str);
}

// int main(int argc, char *argv[])
// {
// 	char **str;
// 	int i;

// 	(void)argc;

// 	str = ft_split(argv[1], argv[2][0]);
// 	i = 0;
// 	// printf("test = %s\n", (char *)str);
// 	if (str != NULL)
// 	{
// 		while (str[i] != 0)
// 		{
// 			// printf("%s\n", str[i]);
// 			// free(str[i]);
// 			i++;
// 		}
// 		// free(str[i]);
// 		// free(str);
// 	}
// 	return 0;
// }