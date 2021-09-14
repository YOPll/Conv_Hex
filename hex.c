#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_atoi(char *p)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (p[i] == ' ' || p[i] == '\t' || p[i] == '\n' || p[i] == '\r' || p[i] == '\v' || p[i] == '\f')
	{
		i++;
	}
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (p[i] >= '0' && p[i] <= '9')
	{
		res = res *10 + (p[i] - '0');
		i++; 
	}
	return (res * sign);

}
void	ft_hex(int x)
{
	if (x == 0)
		ft_putchar('0');
	char hex[16] = "0123456789abcdef";
	int save[10];
	int here = 0;

	while (x)
	{
		save[here] = (x % 16);
		here++;
		x = x / 16;
	}
	while (here > 0)
	{
		ft_putchar(hex[save[here-1]]);
		here--;
	}
	
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		i = ft_atoi(av[1]);
		ft_hex(i);
	}
	ft_putchar('\n');
}
