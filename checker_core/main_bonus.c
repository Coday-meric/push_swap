/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:49:57 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/23 17:49:57 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (treat_argv(pile, argc, argv) == 0 || get_inst(pile) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		destroy_pile(pile);
		return (0);
	}
	if (check_sort(pile) == 0 || pile->len_b != 0)
	{
		ft_putstr_fd("KO\n", 1);
		destroy_pile(pile);
		return (0);
	}
	ft_putstr_fd("OK\n", 1);
	destroy_pile(pile);
	return (0);
}
