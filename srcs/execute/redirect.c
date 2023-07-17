/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:57:37 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 20:09:50 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/minishell.h"

void		redirect(t_node *node, int fd_stdout);
static void	redirect_std(char *direction, char *file);
static void	redirect_append(char *direction, char *file, int fd_stdout);
static void	here_document(char *limiter, int fd, int fd_stdout);

void	redirect(t_node *node, int fd_stdout)
{
	t_node	*iter;
	char	*direction;
	char	*file;

	iter = node;
	while (iter)
	{
		direction = iter->data->word;
		iter = iter->right;
		file = iter->data->word;
		if (ft_strlen(direction) == 2)
			redirect_append(direction, file, fd_stdout);
		else
			redirect_std(direction, file);
		iter = iter->right;
	}
}

static void	redirect_std(char *direction, char *file)
{
	int	fd;
	int	len;

	len = 1;
	if (!ft_strncmp(direction, "<", len))
	{
		fd = open(file, O_RDONLY, 0644);
		if (fd == ERROR)
			crash(file, errno);
		if (dup2(fd, STDIN_FILENO) == ERROR)
			crash(direction, errno);
	}
	else if (!ft_strncmp(direction, ">", len))
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd == ERROR)
			crash(file, errno);
		if (dup2(fd, STDOUT_FILENO) == ERROR)
			crash(direction, errno);
	}
}

static void	redirect_append(char *direction, char *file, int fd_stdout)
{
	int	fd;
	int	len;

	len = 2;
	if (!ft_strncmp(direction, "<<", len))
	{
		here_document(file,
			open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644), fd_stdout);
		fd = open(".here_doc", O_RDONLY, 0644);
		if (fd == ERROR)
			crash("Here document", errno);
		if (dup2(fd, STDIN_FILENO) == ERROR)
			crash(direction, errno);
	}
	else if (!ft_strncmp(direction, ">>", len))
	{
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (fd == ERROR)
			crash(file, errno);
		if (dup2(fd, STDOUT_FILENO) == ERROR)
			crash(direction, errno);
	}
}

static void	here_document(char *limiter, int fd, int fd_stdout)
{
	char	*line;
	int		save_redirected_fd;

	if (fd == ERROR)
		crash("Here document", errno);
	save_redirected_fd = dup(STDOUT_FILENO);
	dup2(fd_stdout, STDOUT_FILENO);
	while (1)
	{
		line = readline("> ");
		if (!line)
			crash("Here document", errno);
		if (ft_strlen(line) == ft_strlen(limiter)
			&& !ft_strncmp(line, limiter, ft_strlen(line)))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	dup2(save_redirected_fd, STDOUT_FILENO);
	close(fd);
}
