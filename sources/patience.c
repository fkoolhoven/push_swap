/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/21 18:03:57 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// find longest list of ascending number within stack_a
// push items not in list to stack_b
// merge stack_b back into stack_a

void	print_list(int **list)
{
	int	i;

	i = 0;
	while (list)
	{
		ft_printf("%i ", *list[i]);
		i++;
	}
	ft_printf("\n");
}

int	**fill_list(int list_length, t_stack **tops)
{
	int	**list;
	t_stack	*last_top;

	last_top = tops[list_length];
	list = ft_calloc(list_length, sizeof(int));
	if (list == NULL)
	{
		ft_putendl_fd("Error: Failed to malloc final list", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	while (list_length > 0)
	{
		list[list_length] = &last_top->content;
		last_top = last_top->left_pile_top;
		list_length--;
	}
	return (list);
}

t_stack	*find_pile(int current_node, t_stack **stack_a, t_stack **tops)
{
	int		check_top;
	t_stack	*top;
	t_stack	*node;
	t_stack	*stored;

	top = *tops;
	check_top = 0;
	if (current_node == 0)
		return (NULL);
	while (top)
	{
		if (node->content < top->content)
		{
			top = node;
			top->left_pile_top = stored; // stored is previous top
			top->left_pile_top->right_pile_top = top;
			return (top);
		}
		top = top->right_pile_top;
	}
	return (NULL);
}

void	longest_list(t_stack **stack_a)
{
	t_stack	*tops;
	t_stack	*found_pile;
	int		stack_size;
	int		i;
	int		j;
	int		**final_list;
	t_stack	*current_node;

	current_node = *stack_a;
	stack_size = calculate_stack_size(*stack_a);
	//tops = ft_calloc(stack_size, sizeof(t_stack));
	tops = NULL;
	i = 0;
	j = 0;
	while (i < stack_size)
	{
		found_pile = find_pile(i, stack_a, &tops);
		if (found_pile)
		{
			// already doing this in find_pile function
			// found_pile = current_node;
			// tops
			// found_pile->left_pile_top = found_pile
			// tops[found_pile]->left_pile_top = tops[found_pile - 1];
			// set pointer to tops
		}
		else
		{
			printf("\n\ncheck\n\n");
			tops = current_node;
			printf("\n\ncheckafter\n\n");
			// set pointer to tops
			j++;
		}
		current_node = current_node->next;
		i++;
	}
	final_list = fill_list(j, &tops);
	print_list(final_list);
}
