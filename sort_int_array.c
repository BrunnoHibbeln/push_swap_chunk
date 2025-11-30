/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:05:20 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/29 14:32:19 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
			swap_int(&arr[i++], &arr[j]);
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* int comparator for qsort */
int int_cmp(const void *p, const void *q)
{
	int	a;
	int	b;

	a = *(const int *)p;
	b = *(const int *)q;
	return (a > b) - (a < b);
}

void	sort_int_array(int *arr, int low, int high)
{
	int	p;

	p = 0;
	if (low < high)
	{
		p = partition(arr, low, high);
		sort_int_array(arr, low, p - 1);
		sort_int_array(arr, p + 1, high);
	}
}
