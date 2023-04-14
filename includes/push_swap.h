/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:24 by felicia           #+#    #+#             */
/*   Updated: 2023/04/14 19:50:36 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include "stdbool.h"
# include <limits.h>

// =====STRUCTS=================================================================

typedef struct s_stack
{
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
	char			up_down_switch;
	char			a_up_or_down;
	char			b_up_or_down;
	int				a_distance;
	int				b_distance;
	int				move_amount_optimal;
	int				a_moves;
	int				b_moves;
	int				stack_a_length;
}	t_merge;

// =====FUNCTIONS===============================================================

void	print_linked_list(t_stack *stack);
void	validate_input(int argc, char **argv);
void	initialize_stack(t_stack **stack, int argc, char **arguments);
bool	stack_a_already_sorted(t_stack **stack_a);
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
void	find_longest_list(t_stack **stack_a, char asc_or_desc);
void	seperate_lists(t_stack **stack_a, t_stack **stack_b);
void	merge_stacks(t_stack **stack_a, t_stack **stack_b);
void	find_distance_first_number(t_stack **stack_a,
			t_stack *current_node, t_merge *merge);
void	search_better_option_top(t_stack **stack_a,
			t_stack *current_node, t_merge *merge);
void	search_better_option_bottom(t_stack **stack_a,
			t_stack **stack_b, t_merge *merge);
void	find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge);
void	check_if_optimal(t_merge *merge, char a_direction, char b_direction);
bool	no_need_to_rotate_a(t_stack **stack_a, t_stack *current_node);
bool	found_right_position(t_stack *current_node, t_stack *a_compare);
void	execute_merge(t_stack **stack_a, t_stack **stack_b, t_merge *merge);
void	final_rotate(t_stack **stack_a);
void	handle_errors(char *message);

#endif