/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:14:55 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/07 16:26:24 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_min(t_num *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret > stack->content)
		{
			ret = stack->content;
		}
		stack = stack->next;
	}
	return (ret);
}

int	get_stack_max(t_num *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret < stack->content)
		{
			ret = stack->content;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_min(t_info *info)
{
	int		ret;
	int		min;
	int		tmp;
	t_num	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	min = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == min)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	set_a_location_max(t_info *info)
{
	int		ret;
	int		max;
	int		tmp;
	t_num	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	max = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == max)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_info *info)
{
	t_num	*stack_a;
	int		ret;

	stack_a = info->top_a;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->content && num < stack_a->next->content)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}
