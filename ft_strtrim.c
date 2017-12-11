/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:46:46 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 16:20:51 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		leading_ws(char const *str);
static int		trailing_ws(char const *str);

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		index;
	int		iterator;
	int		length;
	int		head;
	int		tail;
	
	if (!s)
		return (NULL);
	head = leading_ws(s);
	tail = trailing_ws(s);
	length = ft_strlen(s) - head - tail;
	if (length < 0)
		return (ft_strcpy((char*)malloc(sizeof(char) + 1), ""));
	str = (char *)malloc(sizeof(*str) * (length + 1));
	if (!str)
		return (NULL);
	index = 0;
	iterator = head;
	while (iterator < head + length)
		str[index++] = s[iterator++];
	str[index] = '\0';
	return (str);
}

static int		leading_ws(char const *str)
{
	int index;

	index = 0;
	while (IS_WS(str[index]))
		index++;
	return (index);
}

static int		trailing_ws(char const *str)
{
	int index;
	int length;

	length = ft_strlen(str) - 1;
	index = length;
	while (index > 0 && (IS_WS(str[index]) || str[index] == '\0'))
		index--;
	return (length - index);	
}
