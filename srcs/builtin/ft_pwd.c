/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:51:46 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 16:30:10 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
