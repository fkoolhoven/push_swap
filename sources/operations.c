/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:44 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/20 19:57:14 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	swap_a(t_stack **stack_a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	int		store_content;

	first_node = *stack_a;
	second_node = first_node->next;
	store_content = first_node->content;
	first_node->content = second_node->content;
	second_node->content = store_content;
	ft_printf("\n-------------\n");
	ft_printf("Executed swap_a\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_node;

	first_node = *stack_a;
	*stack_a = first_node->next;
	reset_indexes(*stack_a);
	if (*stack_b == NULL)
		first_node->next = NULL;
	prepend_node(stack_b, first_node);
	ft_printf("-------------\n");
	ft_printf("Executed push_b\n");
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(t_stack **stack_a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	int		last_index;

	first_node = *stack_a;
	second_node = first_node->next;
	*stack_a = second_node;
	last_index = stack_size(*stack_a);
	first_node->next = NULL;
	first_node->index = last_index;
	append_node(stack_a, first_node);
	reset_indexes(*stack_a);
	ft_printf("-------------\n");
	ft_printf("Executed rotate_a\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_node;

	last_node = find_last_node(*stack_a);
	prepend_node(stack_a, last_node);
	reset_indexes(*stack_a);
	ft_printf("-------------\n");
	ft_printf("Executed reverse_rotate_a\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.