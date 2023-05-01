/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:41:44 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/21 17:08:29 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inst_sa(t_pile *pile, int conf)
{
	int	tmp;

	if (conf == 0)
		ft_putstr_fd("sa\n", 1);
	if (pile->len_a <= 1)
		return ;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
}

void	inst_sb(t_pile *pile, int conf)
{
	int	tmp;

	if (conf == 0)
		ft_putstr_fd("sb\n", 1);
	if (pile->len_b <= 1)
		return ;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
}

void	inst_ss(t_pile *pile, int conf)
{
	if (conf == 0)
		ft_putstr_fd("ss\n", 1);
	inst_sa(pile, conf);
	inst_sb(pile, conf);
}

void	inst_pa(t_pile *pile, int conf)
{
	int	i;

	if (conf == 0)
		ft_putstr_fd("pa\n", 1);
	if (pile->len_b == 0)
		return ;
	i = pile->len_a + 1;
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = pile->b[0];
	i = 0;
	while (i < pile->len_b)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->len_a = pile->len_a + 1;
	pile->len_b = pile->len_b - 1;
}

void	inst_pb(t_pile *pile, int conf)
{
	int	i;

	if (conf == 0)
		ft_putstr_fd("pb\n", 1);
	if (pile->len_a == 0)
		return ;
	i = pile->len_b + 1;
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = pile->a[0];
	i = 0;
	while (i < pile->len_a)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->len_b = pile->len_b + 1;
	pile->len_a = pile->len_a - 1;
}
