/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:43:26 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/03 16:43:29 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	It first skips any leading whitespace (spaces, tabs, etc.).
	If the string has a + or - sign, it sets the sign accordingly.
	Then, it processes the digits in the string, multiplying num by 10 and adding the digit value.
	Finally, it returns the number, considering the sign (+ or -).
*/

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

/*
    Create the stack with this command line values
    Checked it!
    To be sure the number is valid!
*/

t_stack	*return_chunk(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->best_move)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
/*
	invalid_entries(av[i]) checks if the current entry is invalid. 
	If it is, the error_free function is called to handle the error (likely freeing memory and terminating the program).
	ft_atol(av[i]) is used to convert each argument into a long integer.
	If the value is out of the integer range (INT_MAX or INT_MIN), it calls error_free again.
	check_dub(*a, (int)size) checks if the value is already in the stack (duplicates).
	If a duplicate is found, it calls error_free.
*/

void	initialized_stack(t_stack **a, char **av, bool ac_two)
{
	long	size;
	int		i;

	i = 0;
	while (av[i])
	{
		if (invalid_entries(av[i]))
			error_free(a, av, ac_two);
		// Convert to string as an integer
		size = ft_atol(av[i]);
		if (size > INT_MAX || size < INT_MIN)
			error_free(a, av, ac_two);
		if (check_dub(*a, (int)size))
			error_free(a, av, ac_two);
		add_to_stack(a, (int)size);
		++i;
	}
	if (ac_two)
		free_matrix(av);
}
