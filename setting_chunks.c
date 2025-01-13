/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:07 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/04 11:09:08 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	status_of_stack(t_stack *stack)
{
	int	middle;
	int	counter;

	counter = 0;
	if (stack == NULL)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->status_stack = counter;
		if (counter <= middle)
			stack->upper_middle = true;
		else
			stack->upper_middle = false;
		stack = stack->next;
		++counter;
	}
}

void	hold_elements(t_stack *a, t_stack *b)
{
	t_stack	*a_status;
	t_stack	*hold_elements;
	long	compare_both_elements;

	while (b)
	{
		compare_both_elements = LONG_MAX;
		a_status = a;
		while (a_status)
		{
			if (a_status->value > b->value
				&& a_status->value < compare_both_elements)
			{
				compare_both_elements = a_status->value;
				hold_elements = a_status;
			}
			a_status = a_status->next;
		}
		if (LONG_MAX == compare_both_elements)
			b->hold = find_smallest_element(a);
		else
			b->hold = hold_elements;
		b = b->next;
	}
}

void	calculate_chunk(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->correct_nbr = b->status_stack;
		if (!(b->upper_middle))
			b->correct_nbr = len_b - (b->status_stack);
		if ((b->hold->upper_middle))
			b->correct_nbr += b->hold->status_stack;
		else
			b->correct_nbr += len_a - (b->hold->status_stack);
		b = b->next;
	}
}

void	set_chunk(t_stack *b)
{
	long	final_hold_value;
	t_stack	*final_hold;

	if (NULL == b)
		return ;
	final_hold_value = LONG_MAX;
	while (b)
	{
		if (b->correct_nbr < final_hold_value)
		{
			final_hold_value = b->correct_nbr;
			final_hold = b;
		}
		b = b->next;
	}
	final_hold->best_move = true;
}

void	initialized_links(t_stack *a, t_stack *b)
{
	status_of_stack(a);
	status_of_stack(b);
	hold_elements(a, b);
	calculate_chunk(a, b);
	set_chunk(b);
}
