/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:47:21 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/04 09:47:22 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	int		lenght;
	t_stack	*last_element;

	lenght = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == lenght)
		return ;
	last_element = find_last_element(*stack);
	last_element->before->next = NULL;
	last_element->next = *stack;
	last_element->before = NULL;
	*stack = last_element;
	last_element->next->before = last_element;
}

void	rra(t_stack **a, bool check)
{
	reverse_rotate(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool check)
{
	reverse_rotate(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!check)
		write(1, "rrr\n", 4);
}
