/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 08:36:02 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:46:31 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_display(int h, int w, int x, int y)
{
	if (h == 1 && w == 1)
		ft_putchar('o');
	else if (h == 1 && w == x)
		ft_putchar('o');
	else if (h == y && w == 1)
		ft_putchar('o');
	else if (h == y && w == x)
		ft_putchar('o');
	else if (h == 1 || h == y)
		ft_putchar('-');
	else if (w == 1 || w == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	ft_display_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	rush(int x, int y)
{
	int		h;
	int		w;

	if (x <= 0 || y <= 0)
	{
		ft_display_error("Invalid dimensions\n");
		return ;
	}
	h = 1;
	while (h <= y)
	{
		w = 1;
		while (w <= x)
		{
			ft_display(h, w, x, y);
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}
