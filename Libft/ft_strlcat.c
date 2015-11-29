/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:12:37 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 20:12:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	char	*const save = s1;

	while (*s1 != '\0' && n-- > 0)
		s1++;
	while (*s2 != '\0' && n-- > 0)
	*s1++ = *s2++;
	*s1 = '\0';
//	return (s1 - save);
	return (0);
}
