/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:24 by felicia           #+#    #+#             */
/*   Updated: 2023/03/20 19:26:00 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"

// =====STRUCTS=================================================================

typedef struct s_stack
{
	unsigned int	index;
	int				content;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

// =====FUNCTIONS===============================================================

void	print_linked_list(t_stack *stack);
t_stack	*initialize_stack(int argc, char **argv);
void	prepend_node(t_stack **stack, t_stack *new_node);
void	append_node(t_stack **stack, t_stack *new_node);
t_stack	*find_last_node(t_stack *stack);
int		stack_size(t_stack *stack);
void	reset_indexes(t_stack *stack);
void	swap_a(t_stack **stack_a);
void	rotate_a(t_stack **stack_a);
void	reverse_rotate_a(t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);

#endif