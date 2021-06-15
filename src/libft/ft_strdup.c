/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lborges- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:03:00 by lborges-          #+#    #+#             */
/*   Updated: 2020/01/31 18:52:36 by lborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*new_s;

	s_len = ft_strlen(s1);
	new_s = malloc((s_len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s_len >= 0)
	{
		new_s[s_len] = (char)s1[s_len];
		s_len--;
	}
	return (new_s);
}
