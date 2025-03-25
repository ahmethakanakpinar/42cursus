/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:56:10 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:34:03 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strncpy_bonus(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*f_strchr_bonus(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (NULL);
	return ((char *)str + i);
}

size_t	ft_strlen_endl_bonus(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*trim_free_bonus(char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && f_strchr_bonus(set, s1[start]))
		start++;
	end = ft_strlen(s1 + start);
	while (end > start && f_strchr_bonus(set, s1[(start + end) - 1]))
		end--;
	trimmed_str = malloc((end + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strncpy_bonus(trimmed_str, s1 + start, end);
	trimmed_str[end] = '\0';
	free(s1);
	return (trimmed_str);
}
