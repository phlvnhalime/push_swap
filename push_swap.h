/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:02:23 by hpehliva          #+#    #+#             */
/*   Updated: 2024/12/03 14:02:25 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				status_stack;
	int				correct_nbr;
	bool			upper_middle;
	bool			best_move;
	struct s_stack	*next;
	struct s_stack	*before;
	struct s_stack	*hold;
}					t_stack;

// revise split
char				**revise_split(char *str, char separator);
// Error checked with this code!
int					invalid_entries(char *str);
int					check_dub(t_stack *a, int size);
void				error_free(t_stack **a, char *av[], bool ac_two);
void				free_matrix(char **av);
void				free_stack(t_stack **stack);
// Create Stack with link and return stack!
void				initialized_stack(t_stack **a, char *av[], bool ac_two);
t_stack				*return_chunk(t_stack *stack);
// Put all elements to stack with link!
void				add_to_stack(t_stack **stack, int size);
t_stack				*find_last_element(t_stack *stack);
// Check stack, if is it ordered!
bool				is_ordered(t_stack *stack);
int					stack_len(t_stack *stack);
// Algorithm
void				insertion_algorithm(t_stack **a, t_stack **b);
//--- Setting stack;
void				status_of_stack(t_stack *stack);
void				hold_elements(t_stack *a, t_stack *b);
void				calculate_chunk(t_stack *a, t_stack *b);
void				set_chunk(t_stack *b);
void				initialized_links(t_stack *a, t_stack *b);

//--- --- utils of algorithm
void				chunk_five(t_stack **a, t_stack **b);
t_stack				*find_smallest_element(t_stack *stack);
void				last_elements_a(t_stack **a);
void				rotation_rules(t_stack **stack, t_stack *top, char c);

// Operators!
// Swap!
void				sa(t_stack **a, bool check);
void				sb(t_stack **b, bool check);
void				ss(t_stack **a, t_stack **b, bool check);
// Push
void				pa(t_stack **a, t_stack **b, bool check);
void				pb(t_stack **b, t_stack **a, bool check);
// rotate
void				ra(t_stack **a, bool check);
void				rb(t_stack **b, bool check);
void				rr(t_stack **a, t_stack **b, bool check);
// reverse_rotate
void				rra(t_stack **a, bool check);
void				rrb(t_stack **b, bool check);
void				rrr(t_stack **a, t_stack **b, bool check);
#endif
