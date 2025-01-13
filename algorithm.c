/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:44:10 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/04 09:44:11 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *best_move)
{
	while (*a != best_move->hold && *b != best_move)
		rr(a, b, false);
	status_of_stack(*a);
	status_of_stack(*b);
}

static void	reverse_rotate(t_stack **a, t_stack **b, t_stack *best_move)
{
	while (*a != best_move->hold && *b != best_move)
		rrr(a, b, false);
	status_of_stack(*a);
	status_of_stack(*b);
}

static void	moves(t_stack **a, t_stack **b)
{
	t_stack	*turn_best;

	turn_best = return_chunk(*b);
	if ((turn_best->upper_middle) && (turn_best->hold->upper_middle))
		rotate_both(a, b, turn_best);
	else if (!(turn_best->upper_middle) && !(turn_best->hold->upper_middle))
		reverse_rotate(a, b, turn_best);
	rotation_rules(b, turn_best, 'b');
	rotation_rules(a, turn_best->hold, 'a');
	pa(a, b, false);
}
/*
	lenght = stack_len(*a);: The length of stack a is stored in lenght.
	If the length is 5, it calls chunk_five (likely a function that handles special cases 
		when there are exactly 5 elements in stack a).
	If there are more than 3 elements, it moves elements from stack a to stack b using pb(b, a, false), 
		reducing the length until only 3 elements are left in a.
	last_elements_a(a);: This function likely handles sorting or positioning the last elements in stack a.
	Then, it enters a loop to process stack b. It initializes the links between elements (initialized_links(*a, *b)) 
		and performs the necessary movements (moves(a, b)) until stack b is empty.
	After stack b is empty, the program looks for the smallest element in stack a (find_smallest_element(*a)).
	Depending on whether the smallest element is in the upper middle part of the stack, it rotates (ra(a, false)) 
		or reverse-rotates (rra(a, false)) the stack a until the smallest element is at the top.
*/

void	insertion_algorithm(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		lenght;

	lenght = stack_len(*a);
	if (lenght == 5)
		chunk_five(a, b);
	else
	{
		while (lenght-- > 3)
			pb(b, a, false);
	}
	last_elements_a(a);
	while (*b)
	{
		initialized_links(*a, *b);
		moves(a, b);
	}
	status_of_stack(*a);
	smallest = find_smallest_element(*a);
	if (smallest->upper_middle)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
