/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:11:39 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/10 18:59:19 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/include/get_next_line.h"
# include "push_swap.h"

void	ft_error_bonus(char *line);
void	execute_command(char *line, t_node **a, t_node **b);

#endif