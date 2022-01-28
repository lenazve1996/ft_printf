/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:43:42 by ayajirob          #+#    #+#             */
/*   Updated: 2021/12/05 15:43:43 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		n;
	char	*buf;

	len = ft_strlen(s1);
	buf = (char *)ft_calloc(len + 1, sizeof(char));
	n = 0;
	if (buf == NULL)
		return (NULL);
	while (n <= len)
	{
		buf[n] = s1[n];
		n++;
	}
	return (buf);
}
