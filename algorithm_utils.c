/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:02:58 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/04 11:03:00 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_rules(t_stack **stack, t_stack *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->upper_middle)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (c == 'b')
		{
			if (top->upper_middle)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static t_stack	*find_highest_element(t_stack *stack)
{
	int		high;
	t_stack	*highest_element;

	high = INT_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value > high)
		{
			high = stack->value;
			highest_element = stack;
		}
		stack = stack->next;
	}
	return (highest_element);
}

t_stack	*find_smallest_element(t_stack *stack)
{
	long	small;
	t_stack	*smallest_element;

	small = LONG_MAX;
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			smallest_element = stack;
		}
		stack = stack->next;
	}
	return (smallest_element);
}

void	last_elements_a(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest_element(*a);
	if (*a == highest)
		ra(a, false);
	else if ((*a)->next == highest)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	chunk_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		initialized_links(*a, *b);
		rotation_rules(a, find_smallest_element(*a), 'a');
		pb(b, a, false);
	}
}
