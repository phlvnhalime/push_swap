/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revise_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:27:17 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/10 10:27:18 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stddef.h>

static int	ft_count_words(char const *str, char separator)
{
	int		count;
	bool	check_inside;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		check_inside = false;
		while (str[i] != '\0' && str[i] == separator)
			++i;
		while (str[i] != separator && str[i] != '\0')
		{
			if (check_inside == false)
			{
				++count;
				check_inside = true;
			}
			++i;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	i = 0;
	int			letter;
	char		*tmp;
	int			ltr_len;

	letter = 0;
	ltr_len = 0;
	while (str[i] == separator)
		++i;
	while (str[i + ltr_len] && str[i + ltr_len] != separator)
		++ltr_len;
	tmp = malloc(sizeof(char) + 1 * (size_t)ltr_len);
	if (tmp == NULL)
		return (NULL);
	while ((str[i] != separator) && str[i])
	{
		tmp[letter++] = str[i++];
	}
	tmp[letter] = '\0';
	return (tmp);
}

char	**revise_split(char *str, char separator)
{
	char	**str_split;
	int		num_words;
	int		i;

	i = 0;
	num_words = ft_count_words(str, separator);
	while (!num_words)
		exit(1);
	str_split = malloc(sizeof(char *) * (size_t)(num_words + 2));
	if (str_split == NULL)
		return (NULL);
	while (num_words-- >= 0)
	{
		if (0 == i)
		{
			str_split[i] = malloc(sizeof(char));
			if (NULL == str_split[i])
				return (NULL);
			str_split[i++][0] = '\0';
			continue ;
		}
		str_split[i++] = get_next_word(str, separator);
	}
	str_split[i] = NULL;
	return (str_split);
}
