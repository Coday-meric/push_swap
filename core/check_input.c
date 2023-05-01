/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:02:55 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/24 00:04:12 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_double(t_pile *pile)
{
	int	cnt;
	int	i;
	int	ii;

	i = 0;
	while (i < pile->len_a)
	{
		cnt = 0;
		ii = 0;
		while (ii < pile->len_a)
		{
			if (pile->a[i] == pile->a[ii])
				cnt++;
			ii++;
		}
		if (cnt > 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_input(char *data)
{
	if (ft_atoi(data) > 2147483647)
		return (1);
	if (ft_atoi(data) < -2147483648)
		return (1);
	return (0);
}
