/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:10:16 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 10:05:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char const	*save1;
	char const	*save2;

	save2 = s2;
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
			save1 = s1;
		while (*s2 != '\0' && *s1 == *s2)
		{
			++s1;
			++s2;
		}
		if (*s2 == '\0')
			return ((char *)save1);
		s1 = save1 + 1;
		s2 = save2;
	}
	return (NULL);
}
