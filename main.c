/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:25:45 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/03 14:25:47 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	The program reads command-line arguments, processes them into a stack,
	and sorts them using various methods depending on the number of elements in the stack.
	It handles cases with small stacks (2 or 3 elements) differently from larger stacks 
	(more than 3 elements), applying appropriate sorting algorithms.
*/

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = revise_split(av[1], ' ');
	initialized_stack(&a, (av + 1), ac == 2);
	if (!is_ordered(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			last_elements_a(&a);
		else
			insertion_algorithm(&a, &b);
	}
	// Memory cleaned up!
	free_stack(&a);
	free_stack(&b);
}
