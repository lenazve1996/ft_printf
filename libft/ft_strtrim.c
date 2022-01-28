/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:43:59 by ayajirob          #+#    #+#             */
/*   Updated: 2021/12/05 15:44:00 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp_str;
	int		len_for_trim;
	int		n_for_start;

	tmp_str = (char *)s1;
	n_for_start = 0;
	while (*tmp_str && ft_strchr(set, *tmp_str))
	{
		tmp_str++;
		n_for_start++;
	}
	len_for_trim = ft_strlen(tmp_str);
	tmp_str = tmp_str + len_for_trim - 1;
	while (len_for_trim > 0 && ft_strchr(set, *tmp_str))
	{
		tmp_str--;
		len_for_trim--;
	}
	tmp_str = ft_substr(s1, n_for_start, len_for_trim);
	return (tmp_str);
}
