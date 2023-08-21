/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:20:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:35:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void			init_connection(t_connection *connection);
t_connection	*get_connection(void);
void			clear_connection(t_connection *connection);
void			free_connection(t_connection *connection);

void	init_connection(t_connection *connection)
{
	connection->first = 0;
	connection->second = 0;
}

t_connection	*get_connection(void)
{
	t_connection	*connection;

	connection = (t_connection *)malloc(sizeof(t_connection));
	if (!connection)
		crash(ENOMEM, 0);
	init_connection(connection);
	return (connection);
}

void	clear_connection(t_connection *connection)
{
	if (connection->first)
		free_command(connection->first);
	if (connection->second)
		free_command(connection->second);
	init_connection(connection);
}

void	free_connection(t_connection *connection)
{
	if (connection->first)
		free_command(connection->first);
	if (connection->second)
		free_command(connection->second);
	free(connection);
}
