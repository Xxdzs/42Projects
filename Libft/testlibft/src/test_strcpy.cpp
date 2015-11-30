/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:37:13 by angagnie          #+#    #+#             */
//   Updated: 2015/11/30 17:36:57 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_strcpy(char *(*ft)(char *dst, char const *src))
{
	char buf[BUFSIZE];

	fun_tester_na(strcpy, ft, clear_buf(buf), "to be copied");
	fun_tester_na(strcpy, ft, clear_buf(buf), "");
}
