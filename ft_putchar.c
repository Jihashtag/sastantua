/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 04:44:12 by jbert             #+#    #+#             */
/*   Updated: 2014/08/03 04:45:53 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	if (!write(1, &c, 1))
		exit(-1);
}

void	ft_putsterr(char *s)
{
	while (*s && write(2, s++, 1) > 0)
		;
}

void sastantua(int size);

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '-')
		sastantua(atoi(argv[1]));
	else
		ft_putsterr("user_sastantua's use : ./user_sastantua size\nsize must be an int above or equal to 0\n");
	return (0);
}
