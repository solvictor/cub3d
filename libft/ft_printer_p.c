/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:43:51 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/19 18:01:09 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printer_p(void *addr)
{
	if (addr)
		return (write(1, "0x", 2) + ft_putnbr_ul_hexa((unsigned long) addr));
	return (write(1, "(nil)", 5));
}
