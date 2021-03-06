/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 21:23:40 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 23:41:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		hr_strequ(const t_hm_node *a, const t_hm_node *b)
{
	char	*one;
	char	*two;

	one = ((t_hr_kv *)a)->key;
	two = ((t_hr_kv *)b)->key;
	if (one == NULL || two == NULL)
		return (0);
	while (*one == *two && *one)
	{
		one++;
		two++;
	}
	return (*one == *two);
}

size_t	hr_djb2(t_hr_kv *n)
{
	char		*str;
	size_t		hash;
	size_t		c;

	str = n->key;
	hash = 5381;
	while ((c = (unsigned char)*str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

size_t	hr_djb2a(t_hr_kv *n)
{
	char		*str;
	size_t		hash;
	size_t		c;

	str = n->key;
	hash = 5381;
	while ((c = (unsigned char)*str++))
		hash = ((hash << 5) + hash) ^ c;
	return (hash);
}

size_t	hr_sdbm(t_hr_kv *n)
{
	char	*str;
	size_t	hash;
	size_t	c;

	str = n->key;
	hash = 0;
	while ((c = (unsigned char)*str++))
		hash = c + (hash << 6) + (hash << 16) - hash;
	return (hash);
}

size_t	hr_fnv1a(t_hr_kv *n)
{
	char	*str;
	size_t	hash;
	size_t	c;

	str = n->key;
	hash = 14695981039346656037UL;
	while ((c = (unsigned char)*str++))
	{
		hash ^= c;
		hash *= 1099511628211;
	}
	return (hash);
}
