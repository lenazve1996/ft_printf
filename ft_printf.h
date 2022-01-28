/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:10:36 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/28 17:02:15 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_output_for_px(unsigned long long n, char format, t_list *data);
int		ft_otput_for_x(unsigned int n, char specification);
char	*ft_itoa_xec(char *s, unsigned long long number, int len, char format);
void	ft_int_putchar(char c, t_list *data);
void	ft_otput_for_d(long number, t_list *data);
void	ft_otput_for_s(char *str, t_list *data);
void	ft_put_del_str(char *s, t_list *data, int index);
char	*ft_strnew(size_t size);
int		ft_count_char_number(unsigned long long n);
void	ft_print_indent(int n, t_list *data);

#endif