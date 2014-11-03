/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 04:46:09 by jbert             #+#    #+#             */
/*   Updated: 2014/08/03 18:43:44 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		save_i(int i)
{
	static int	save;

	if (i == 0)
		return (save);
	else
		save = i;
	return (save);
}

void	put_car(int	size, int i, int *j)
{
	if (size > 4 && ((i == ((size - 2)/ 2) + 1 && (size % 2)) || \
				(i == (size / 2) + 3))\
			&& j[0] == (j[1] / 2 + 1) + ((size + 1) / 2) - 2)
		ft_putchar('$');
	else
		ft_putchar('|');
}

void	aff(int *j, int sp, int *base_s, int s)
{
	static int	size = 0;

	if (!size)
	{
		size = s;
		return ;
	}
	sp = 0;
	while (++sp <= base_s[0])
		ft_putchar(' ');
	ft_putchar('/');
	j[0] = 0;
	while (++j[0] <= j[1])
	{
		if (save_i(0) > 2 && ((size % 2) || save_i(0) >= 4) && \
			(size - s) == 0 && (j[0] > (j[1] / 2) - ((size - 1) / 2) && \
			j[0] < (j[1] / 2 + 1) + ((size + 1) / 2)))
			put_car(size, save_i(0), j);
		else
			ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

int		sastantua_c(int size)
{
	int	sp;
	int	s;
	int	i;
	int	j;

	sp = 1;
	j = 2;
	s = 1;
	while (s <= size)
	{
		i = 1;
		if (!((s + 1) % 2))
			j += 2;
		if (s < size)
			sp += j;
		while (i <= s + 2)
		{
			sp += 2;
			i++;
		}
		s++;
	}
	aff(0, 0, 0, size);
	sp /= 2;
	return (sp - 1);
}

void	sastantua(int size)
{
	int	base_s[2];
	int	sp;
	int	s;
	int	i;
	int	j[3];

	base_s[1] = sastantua_c(size);
	s = 1;
	sp = 1;
	j[1] = 1;
	j[2] = 2;
	while (s <= size)
	{
		i = 0;
		while (++i <= (s + 2) && save_i(i))
		{
			base_s[0] = base_s[1] - (j[1] / 2);
			aff(j, sp, base_s, s);
			j[1] += 2;
		}
		s++;
		if (!(s % 2))
			j[2] += 2;
		j[1] += j[2];
	}
}
