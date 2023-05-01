/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:32:17 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/22 17:25:46 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_sort(t_pile *pile)
{
	int	*p;

	p = pile->a;
	if (p[1] < p[0] && p[2] > p[0])
		inst_sa(pile, 0);
	else if (p[1] < p[0] && p[2] < p[0] && p[2] > p[1])
		inst_ra(pile, 0);
	else if (p[1] > p[0] && p[2] < p[0])
		inst_rra(pile, 0);
	else if (p[1] > p[0] && p[2] < p[1])
	{
		inst_sa(pile, 0);
		inst_ra(pile, 0);
	}
	else if (p[1] < p[0] && p[2] < p[1])
	{
		inst_sa(pile, 0);
		inst_rra(pile, 0);
	}
}

void	radix_sort(t_pile *pile)
{
	int	i;
	int	i_b;
	int	tmp_len;

	i_b = 0;
	while (check_sort(pile) == 0)
	{
		i = 0;
		tmp_len = pile->len_a;
		while (i < tmp_len)
		{
			if ((pile->a[0] >> i_b & 1) == 0)
				inst_pb(pile, 0);
			else
				inst_ra(pile, 0);
			i++;
		}
		i = -1;
		tmp_len = pile->len_b;
		while (i++ < tmp_len)
			inst_pa(pile, 0);
		i_b++;
	}
}
