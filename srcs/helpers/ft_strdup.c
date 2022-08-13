/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:28:28 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/09 22:28:30 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*copy;

	i = -1;
	size = ft_strlen(s);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	while (++i < size)
		copy[i] = s[i];
	copy[i] = 0;
	return (copy);
}
