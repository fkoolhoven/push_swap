/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:24 by felicia           #+#    #+#             */
/*   Updated: 2023/03/28 15:04:41 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include "stdbool.h"

// =====STRUCTS=================================================================

typedef struct s_stack
{
	unsigned int	index;
	int				number;
	struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*left_pile_top;
	struct s_stack	*right_pile_top;
	bool			part_of_ascending_list;
	bool			part_of_descending_list;
}	t_stack;

typedef struct s_merge
{
	int				optimal;
	int				stored_optimal;
	int				stack_a_length;
	int				a_distance;
	int				b_distance;
	int				a_moves;
	int				b_moves;
}	t_merge;

// =====FUNCTIONS===============================================================

void	print_linked_list(t_stack *stack);
void	initialize_stack(t_stack **stack, int argc, char **argv);
void	prepend_node(t_stack **stack, t_stack *new_node);
void	append_node(t_stack **stack, t_stack *new_node);
t_stack	*find_last_node(t_stack *stack);
int		calculate_stack_size(t_stack *stack);
void	reset_indexes(t_stack *stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_b, t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_longest_ascending_list(t_stack **stack_a);
t_stack	*find_longest_descending_list(t_stack **stack_a);
void	seperate_list_from_rest(t_stack **stack_a, t_stack **stack_b, t_stack *list_start);
void	merge_stacks(t_stack **stack_a, t_stack **stack_b);
void	find_distance_of_first_node(t_stack **stack_a, t_stack *current_node, t_merge *merge);
void	look_for_better_option(t_stack **stack_a, t_stack *current_node, t_merge *merge);
int		find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge);
bool	in_ideal_position(t_stack **stack_a, t_stack *current_node);
bool	found_right_position(t_stack *current_node, t_stack *a_compare);
void	final_rotate(t_stack **stack_a);

#endif