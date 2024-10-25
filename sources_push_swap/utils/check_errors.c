/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:10:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/10/25 13:40:05 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int check_errors(int ac, char **av)
{
    int i;
    int j;
    int k;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
                return (1);
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
                return (1);
            j++;
        }
        k = i + 1;
        while (k < ac)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[k]))
                return (1);
            k++;
        }
        i++;
    }
    return (0);
}