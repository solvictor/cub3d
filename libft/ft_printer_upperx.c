/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_upperx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:13:04 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/19 18:01:09 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printer_upperx(int nb)
{
	int	len;

	len = 0;
	ft_putnbr_ui_hexa_up(nb, &len);
	return (len);
}
