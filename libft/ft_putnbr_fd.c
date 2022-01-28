/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:43:35 by ayajirob          #+#    #+#             */
/*   Updated: 2021/12/05 15:43:36 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = 0 - a;
	}
	if (a >= 10)
		ft_putnbr_fd(a / 10, fd);
	a = a % 10 + '0';
	ft_putchar_fd(a, fd);
}
