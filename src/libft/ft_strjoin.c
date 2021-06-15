/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lborges- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:38:17 by lborges-          #+#    #+#             */
/*   Updated: 2020/01/28 11:47:09 by lborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	char	*newstr;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((k + 1) * sizeof(*newstr));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
