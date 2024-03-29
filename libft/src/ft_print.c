/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:14:20 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/13 01:20:01 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print(int fd, char *str, ...)
{
	va_list		lst;
	char		*tmp;

	va_start(lst, str);
	while (*str)
		if (*str == '%' && *(str + 1) == 's' && (str += 2))
		{
			tmp = va_arg(lst, char*);
			write(fd, tmp, ft_strlen(tmp));
		}
		else if (*str == '%' && *(str + 1) == 'd' && (str += 2))
		{
			tmp = ft_itoa(va_arg(lst, int));
			write(fd, tmp, ft_strlen(tmp));
			free(tmp);
		}
		else if (*str == '%' && *(str + 1) == 'p' && (str += 2))
		{
			tmp = ft_utoabase((unsigned int)va_arg(lst, void*), 16);
			write(fd, tmp, ft_strlen(tmp));
			free(tmp);
		}
		else
			write(fd, str++, 1);
	va_end(lst);
}
