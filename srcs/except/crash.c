/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:51:59 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 20:10:47 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	crash(char *message, int errnum);

void	crash(char *message, int errnum)
{
	perror(message);
	exit(errnum);
}