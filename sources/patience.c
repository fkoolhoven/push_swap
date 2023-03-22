/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/22 12:42:45 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// find longest list of ascending number within stack_a
// push items not in list to stack_b
// merge stack_b back into stack_a

// int	**fill_list(int list_length, t_stack **top)
// {
// 	int	**list;
// 	t_stack	*last_top;

// 	last_top = tops[list_length];
// 	list = ft_calloc(list_length, sizeof(int));
// 	if (list == NULL)
// 	{
// 		ft_putendl_fd("Error: Failed to malloc final list", STDERR_FILENO);
// 		exit (EXIT_FAILURE);
// 	}
// 	while (list_length > 0)
// 	{
// 		list[list_length] = &last_top->content;
// 		last_top = last_top->left_pile_top;
// 		list_length--;
// 	}
// 	return (list);
// }

void	print_list(t_stack **top)
{
	t_stack	*item;

	item = *top;
	while (item && item->right_pile_top) // move through all the top and find last one
	{
		item = item->right_pile_top;
	}
	while (item) // follow way back to find list
	{
		ft_printf("%i ", item->content);
		item = item->left_pile_top;
	}
	ft_printf("\n");
}


t_stack	*find_pile(t_stack *current_node, t_stack **tops)
{
	int		check_top;
	t_stack	*top;
	t_stack	*stored;

	top = *tops;
	check_top = 0;
	if (current_node == 0)
		return (NULL);
	while (top)
	{
		printf("0 top->content = %i\n", top->content);
		if (current_node->content < top->content)
		{
			current_node->right_pile_top = top->right_pile_top;
			printf("1 current_node->content = %i and top->content = %i\n", current_node->content, top->content);
			top = current_node; // new top is current node
			printf("2 stored->content = %i\n", stored->content);
			top->left_pile_top = stored; // point new top to left pile top
			printf("3 top->content = %i && left_top = %i\n", top->content, top->left_pile_top->content);
			top->left_pile_top->right_pile_top = top; // point left pile top to new top for next search
			printf("4 current new top should be correct = %i\n", top->left_pile_top->right_pile_top->content);
			return (top);
		}
		stored = top;
		top = top->right_pile_top;
	}
	return (NULL);
}

void	longest_list(t_stack **stack_a)
{
	t_stack	*top;
	t_stack	*first_top;
	t_stack	*found_pile;
	int		stack_size;
	int		i;
	int		j;
	t_stack	*current_node;

	current_node = *stack_a;
	stack_size = calculate_stack_size(*stack_a);
	top = NULL;
	i = 0;
	j = 0;
	while (i < stack_size && current_node)
	{
		printf("\n\nNEXT NODE\n\n");
		found_pile = find_pile(current_node, &top);
		if (!found_pile)
		{
			while (top && top->right_pile_top) // move through all the top and find last one
			{
				top = top->right_pile_top;
			}
			if (top)
			{
				printf("\n\nwhen creating new pile: current_node->content = %i and last top we found was top->content = %i\n\n", current_node->content, top->content);
				top->right_pile_top = current_node; // make last top point to current node as new pile top
				current_node->left_pile_top = top; // make new top point to correct left pile top
			}
			else
			{
				top = current_node;
				first_top = top; // what if first top is replaced
			}
			j++;
		}
		top = first_top;
		current_node = current_node->next;
		i++;
	}
	print_list(&top);
}
