#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-1);
}

void	ft_sort(char **tab, int nb)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				c = tab[i];
				tab[i] = tab[j];
				tab[j] = c;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 0)
	{
		ft_sort(&argv[1], argc - 1);
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
