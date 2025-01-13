/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:45:20 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/03 16:45:21 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*free_stack;
	t_stack	*status;

	if (stack == NULL)
		return ;
	status = *stack;
	while (status)
	{
		free_stack = status->next;
		free(status);
		status = free_stack;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char *av[], bool ac_two)
{
	free_stack(a);
	if (ac_two)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	invalid_entries(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		++str;
	}
	return (0);
}

int	check_dub(t_stack *a, int size)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == size)
			return (1);
		a = a->next;
	}
	return (0);
}
