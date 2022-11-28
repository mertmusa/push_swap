/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ulibft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:57:09 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 16:44:07 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*string to int*/
int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			pos;
	char		*s;

	pos = 1;
	i = 0;
	res = 0;
	s = (char *)str;
	while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
		i++;
	if (s[i] == '+' || s[i] == '-')
		pos = 1 - 2 * (s[i++] == '-');
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 +(s[i++] - 48);
		if (res > 2147483647 && pos == 1)
			return (-1);
		else if (res > 2147483648 && pos == -1)
			return (0);
	}
	return ((int)(res * pos));
}

/*length of string*/
size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	return (a);
}

/*duplicate a string*/
char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
		return (0);
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/*is character a digit*/
int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

/*substring from a string*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*src;
	size_t	i;

	i = 0;
	src = (char *)s;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (0);
		*ret = '\0';
	}
	else
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (!ret)
			return (0);
		ft_strlcpy(ret, &src[start], len + 1);
	}
	return (ret);
}
