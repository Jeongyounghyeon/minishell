/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:16:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 17:50:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "variables.h"
# include "parse/lex.h"

int		take_heredoc(t_lex_list *cur, \
						t_sh_variable *sh_variable, int heredoc_num);

#endif