/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:44:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/26 13:50:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

#define HM_NONE (void *)0xDEADBEEF

int		init(t_hmap *m)
{
	size_t		n;

	n = HM_INITIAL_SIZE;
	if (!(m->data = malloc(m->type_size * n)))
		return (1);
	m->capacity = n;
	while (n-- > 0)
		((t_hm_node *)(m->data + n * m->type_size))->next = HM_NONE;
	return (0);
}

int		hm_add(t_hmap *m, t_hm_node *kv)
{
	t_hm_node	*cur;
	t_hm_node	*tmp;

	if (m->capacity == 0)
		init(m);
	kv->hash = m->hash(kv) % m->capacity;
	tmp = ((t_hm_node *)(m->data + kv->hash * m->type_size));
	if (tmp->next == HM_NONE)
	{
		hm_memcpy(tmp, kv, m->type_size);
		tmp->next = NULL;
	}
	else
	{
		if (!(cur = (t_hm_node *)hm_memdup(kv, m->type_size)))
			return (1);
		cur->next = tmp->next;
		tmp->next = cur;
	}
	return (0);
}

/*
** Wrong behavior but... Ok for now
*/

int		hm_get(t_hmap *m, t_hm_node *kv)
{
	t_hm_node *tmp;

	if (m->capacity == 0)
		return (1);
	kv->hash = m->hash(kv) % m->capacity;
	tmp = (t_hm_node *)(m->data + kv->hash * m->type_size);
	if (tmp->next == HM_NONE)
		return (1);
	while (tmp && !m->equal(kv, tmp))
		tmp = tmp->next;
	if (tmp == NULL)
		return (1);
	hm_memcpy(kv, tmp, m->type_size);
	return (0);
}

#undef HM_NONE
