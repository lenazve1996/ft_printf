/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:43:54 by ayajirob          #+#    #+#             */
/*   Updated: 2021/12/05 15:43:55 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((unsigned char)*s1 >= '\0' && (unsigned char)*s2 >= '\0' && n-- > 0)
	{
		if (((unsigned char)*s1 != (unsigned char)*s2) || \
		((unsigned char)*s1 == '\0') || ((unsigned char)*s1 == '\0'))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
