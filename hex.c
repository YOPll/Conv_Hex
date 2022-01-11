#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_dec(char *str)
{
	int	sum;
	int	j;
	int	len;

	sum = 0;
	j = 0;
	len = (strlen(str) - 1);
	while (len >= 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
		{
			sum = sum + (str[len] - 48) * pow(16, j);
			j++;
		}
		else if (str[len] >= 'A' && str[len] <= 'F')
		{
			sum = sum + (str[len] - 55) * pow(16, j);
			j++;
		}
		len--;
	}
	printf("Decimal Value is %d", sum);
}

void	ft_hex(int x)
{
	if (x == 0)
		ft_putchar('0');
	char hex[16] = "0123456789ABCDEF";
	int save[10];
	int here = 0;

	while (x)
	{
		save[here] = (x % 16);
		here++;
		x = x / 16;
	}
	ft_putstr("Hex Value is ");
	while (here > 0)
	{
		ft_putchar(hex[save[here-1]]);
		here--;
	}
}

int	main(void)
{
	char	hex[1000];
	int		choice;
	int 	dec;
	
    printf("For Decimal to HEX Type: 1\n");
	printf("For HEX to Decimal Type: 2\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("Please! Enter the Decimal value :");
		scanf("%d", &dec);
		ft_hex(dec);
	}
	else if(choice == 2)
	{
		printf("Please! Enter the HEX value :");
		scanf("%s", hex);
		ft_dec(hex);
	}
	else
		printf("404 try again");

	ft_putchar('\n');
}
