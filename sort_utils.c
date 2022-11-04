/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:15:06 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/04 22:39:49 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3div(t_info *info)
{
	int	i;
	int	pv1;
	int	pv2;

	i = info->size_a / 3;
	pv1 = info->arr[i];
	i = info->size_a * 2 / 3;
	pv2 = info->arr[i];
	i = info->size_a;
	while (i)
	{
		ft_sort_3div_instruct(info, pv1, pv2);
		i--;
	}
}

void	ft_sort_3div_instruct(t_info *info, int pv1, int pv2)
{
	if (info->top_a->content < pv1)
	{
		pb(info);
		rb(info);
	}
	else if (info->top_a->content < pv2)
		pb(info);
	else
		ra(info);
}

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int		a_loc;
	int		b_loc;
	int		i;
	t_num	*stack_b;
	int		num;

	i = 0;
	stack_b = info->top_b;
	while (i < info->size_b)
	{
		num = stack_b->content;
		a_loc = set_a_location(num, info);
		if (i >= (info->size_b + 1) / 2)
			b_loc = (info->size_b - i) * -1;
		else
			b_loc = i;
		if (i == 0 || ft_get_faster(*a, *b, a_loc, b_loc))
		{
			*a = a_loc;
			*b = b_loc;
		}
		stack_b = stack_b->next;
		i++;
	}
}

int	ft_get_faster(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	ft_sort_last(t_info *info)
{
	int	min_location;

	min_location = set_a_location_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info);
			min_location--;
		}
		else
		{
			rra(info);
			min_location++;
		}
	}
}
