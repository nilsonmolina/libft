/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:24:17 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 19:03:55 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c);
static char	*get_word(char const *str, char c, int index);

char		**ft_strsplit(char const *s, char c)
{
	char 	**split;
	int		index;
	int 	word;

	if (!s && !c)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split)
		return (NULL);
	index = 0;
	word = 0;
	while (s[index])
	{
		if (index == 0 && s[index] != c)
			split[word++] = get_word(s, c, index);
		else if (s[index] != c && s[index - 1] == c)
			split[word++] = get_word(s, c, index);
		index++;
	}
	split[word] = NULL;
	return (split);
}

static int	word_count(char const *str, char c)
{
	int count;
	int index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (index == 0 && str[index] != c)
			count++;
		else if (str[index] != c && str[index - 1] == c)
			count++;
		index++;
	}
	return (count);
}

static char	*get_word(char const *str, char c, int start)
{
	char	*word;
	int		index;
	int		length;
	int		tail;
	
	length = 0;
	tail = start;
	while (str[tail] != c && str[tail] != '\0')
	{
		tail++;
		length++;
	}
	word = (char *)malloc(sizeof(*word) * (length + 1));
	if (!word)
		return (NULL);
	index = 0;
	while (start < tail)
		word[index++] = str[start++];
	word[index] = '\0';
	return (word);
}
