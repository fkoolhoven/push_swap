/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:24 by felicia           #+#    #+#             */
/*   Updated: 2023/03/20 17:00:36 by fkoolhov         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

// =====FUNCTIONS===============================================================

void	print_linked_list(t_stack *stack);
t_stack	*initialize_stack(int argc, char **argv);
void	append_node(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	reset_indexes(t_stack *stack);
void	swap_a(t_stack **stack_a);
void	rotate_a(t_stack **stack_a);

#endif