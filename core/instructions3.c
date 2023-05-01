/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:09 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/21 17:37:03 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inst_rra(t_pile *pile, int conf)
{
	int	i;
	int	tmp;

	if (conf == 0)
		ft_putstr_fd("rra\n", 1);
	if (pile->len_a == 0)
		return ;
	i = pile->len_a;
	tmp = pile->a[i - 1];
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = tmp;
}

void	inst_rrb(t_pile *pile, int conf)
{
	int	i;
	int	tmp;

	if (conf == 0)
		ft_putstr_fd("rrb\n", 1);
	if (pile->len_b == 0)
		return ;
	i = pile->len_b;
	tmp = pile->b[i - 1];
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = tmp;
}

void	inst_rrr(t_pile *pile, int conf)
{
	if (conf == 0)
		ft_putstr_fd("rrr\n", 1);
	inst_rra(pile, conf);
	inst_rrb(pile, conf);
}
