/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:42:47 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/03 18:42:48 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	additional_function(t_stack *first_element)
{
	first_element->status_stack = 0;
	first_element->correct_nbr = 0;
	first_element->upper_middle = false;
	first_element->best_move = false;
	first_element->next = NULL;
	first_element->before = NULL;
	first_element->hold = NULL;
}

t_stack	*find_last_element(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
/*
	It checks if the stack is NULL. If it is, the function returns without doing anything.
	It dynamically allocates memory for a new stack element (first_element) using malloc.
	If the memory allocation fails, it returns without modifying the stack.
	It sets the value of the new stack element to size and then initializes other attributes of the element 
		using the additional_function (which sets various attributes like status_stack, correct_nbr, etc.).
	If the stack is empty (*stack == NULL), the new element becomes the first element in the stack,
		 and its before pointer is set to NULL.
	If the stack is not empty, it finds the last element of the stack using find_last_element 
		and appends the new element to the end by adjusting the next and before pointers accordingly.
*/

void	add_to_stack(t_stack **stack, int size)
{
	t_stack	*first_element;
	t_stack	*last_element;

	if (stack == NULL)
		return ;
	first_element = malloc(sizeof(t_stack));
	if (first_element == NULL)
		return ;
	first_element->value = size;
	additional_function(first_element);
	if (NULL == *stack)
	{
		*stack = first_element;
		first_element->before = NULL;
	}
	else
	{
		last_element = find_last_element(*stack);
		last_element->next = first_element;
		first_element->before = last_element;
	}
}
