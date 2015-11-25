/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:20:00 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 17:02:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

#define TEST(FUN) printf("%s", #FUN);			\
	test_##FUN(&ft_##FUN);						\
	printf("\n")

int		main(void)
{
	TEST(atoi);
	TEST(strlen);
	TEST(tolower);
	TEST(toupper);
	return (0);
}
