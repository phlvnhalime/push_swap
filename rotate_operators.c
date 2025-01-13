/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:07:51 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/04 09:07:54 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	int		lenght;
	t_stack	*last_element;

	lenght = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == lenght)
		return ;
	last_element = find_last_element(*stack);
	last_element->next = *stack;
	*stack = (*stack)->next;
	(*stack)->before = NULL;
	last_element->next->before = last_element;
	last_element->next->next = NULL;
}

void	ra(t_stack **a, bool check)
{
	rotate(a);
	if (!check)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool check)
{
	rotate(b);
	if (!check)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool check)
{
	rotate(a);
	rotate(b);
	if (!check)
		write(1, "rr\n", 3);
}
