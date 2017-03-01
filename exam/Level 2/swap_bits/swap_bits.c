/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:13:33 by anadam            #+#    #+#             */
/*   Updated: 2017/01/10 15:16:23 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char swap_bits(unsigned char octet)
{
	unsigned char first = octet << 4;
	unsigned char second = octet >> 4;
	unsigned char final = first | second;

	return (final);
}
