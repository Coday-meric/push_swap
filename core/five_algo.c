/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:13:12 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/23 00:13:12 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_five_sort(t_pile *pile)
{
	inst_pb(pile, 0);
	inst_pb(pile, 0);
	three_sort(pile);
}

static void	bypass_five_sort(t_pile *pile, int *i)
{
	if (*i == pile->len_a)
	{
		inst_pa(pile, 0);
		inst_ra(pile, 0);
		*i = -1;
	}
}

static void	go_five_sort(t_pile *pile, int *i)
{
	if (*i > (pile->len_a / 2))
	{
		*i = (pile->len_a - *i);
		while (*i > 0)
		{
			inst_rra(pile, 0);
			*i = *i - 1;
		}
	}
	else
	{
		while (*i > 0)
		{
			inst_ra(pile, 0);
			*i = *i - 1;
		}
	}
}

static void	back_five_sort(t_pile *pile, int *it)
{
	if (*it > (pile->len_a / 2))
	{
		*it = (pile->len_a - *it);
		while (*it > 0)
		{
			inst_ra(pile, 0);
			*it = *it - 1;
		}
	}
	else
	{
		while (*it > 0)
		{
			inst_rra(pile, 0);
			*it = *it - 1;
		}
	}
}

void	five_sort(t_pile *pile)
{
	int	i;
	int	i_;
	int	it;

	init_five_sort(pile);
	i_ = 0;
	while (i_ < 2)
	{
		i = 0;
		while (pile->b[0] > pile->a[i] && i < pile->len_a)
			i++;
		bypass_five_sort(pile, &i);
		it = i;
		go_five_sort(pile, &i);
		if (i != -1)
			inst_pa(pile, 0);
		back_five_sort(pile, &it);
		i_++;
	}
}
