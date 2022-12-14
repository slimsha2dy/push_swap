/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:05:01 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/07 16:25:56 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			sa(info);
	}
	else if (info->size_a == 3)
	{
		ft_sort_three_case(info);
	}
	else
	{
		ft_sort_rest(info);
	}
}

void	ft_sort_three_case(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_a->content;
	mid = info->top_a->next->content;
	bot = info->top_a->next->next->content;
	if (top > mid && mid > bot)
	{
		sa(info);
		rra(info);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else
		rra(info);
}

void	ft_sort_rest(t_info *info)
{
	int	a;
	int	b;

	ft_sort_3div(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			sa(info);
	}
	if (info->size_a == 3)
		ft_sort_three_case(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		ft_rotate_same(info, &a, &b);
		ft_rotate_a(info, a);
		ft_rotate_b(info, b);
		pa(info);
	}
	ft_sort_last(info);
}
