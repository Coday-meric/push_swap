/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:17:00 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/21 23:51:14 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	destroy_pile(t_pile *pile)
{
	free(pile->a);
	free(pile->b);
	free(pile);
}

int	main(int argc, char **argv)
{
	t_pile	*pile;

	if (argc == 1)
		return (0);
	pile = ft_calloc(1, sizeof(t_pile));
	if (treat_argv(pile, argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		destroy_pile(pile);
		return (0);
	}
	if (pile->len_a == 3)
		three_sort(pile);
	else if (pile->len_a == 5)
		five_sort(pile);
	else
		radix_sort(pile);
	destroy_pile(pile);
	return (0);
}
