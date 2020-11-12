#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	base_ok(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		printf("%c : %d\n", c, i);
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	power(int len, int pow)
{
	int puiss;

	puiss = len;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (len);
	while (pow > 1)
	{
		puiss *= len;
		pow--;
	}
	return (puiss);
}

int	ft_atoi(char *nbr, char *base)
{
	int base_len;
	int i;
	int neg;
	int res;
	int ipow;

	base_len = 0;
	i = 0;
	neg = 1;
	res = 0;
	ipow = 0;

	printf("c = %c\n", nbr[i]);
	printf("%s", nbr);
	while (base[base_len])
		base_len++;
	while (nbr[ipow])
		ipow++;
	while (nbr[i] == (' ' || "\t" || "\n" || "\v" || "\f" || "\r"))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg *= -1;
		i++;
	}
	ipow -= i;
	printf("c = %c\n", nbr[i]);
	while (is_in_base(nbr[i], base) >= 0)
	{
		ipow--;
		res = res + is_in_base(nbr[i], base) * power(base_len, ipow);
		i++;
		printf("res = %d\n", res);
	}
	return (res * neg);
}

int	calc_size(int num, char *base)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (base[i])
		i++;
	while (num >= 1)
	{
		num /= i;
		res++;
	}
	return (res);
}

int	filling_conv(int num, int i, int base_len, char *convert, char *base)
{
	if (num >= base_len)
	{
		i = filling_conv(num / base_len, i, base_len, convert, base);
		printf("i = %d\n", i);
		convert[i] = base[num % base_len];
		printf("%c car\n", convert[i] = base[num % base_len]);
	}
	else
		convert[i] = base[num];
	return (i);
}

void	conv_by_base(int num, char *convert, char *base)
{
	int i;
	int base_len;

	i = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (num < 0)
	{
		convert[i] = '-';
		num *= -1;
		printf("conv %s\n", convert);
		i++;
	}
	i = filling_conv(num, i, base_len, convert, base);
	convert[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int num;
	int size;
	char *convert;

	if (base_ok(base_from) == 0 || base_ok(base_to) == 0)
		return (NULL);
	num = ft_atoi(nbr, base_from);
	printf("%d\n", num);
	size = calc_size(num, base_to);
	printf("%d size\n", size);
	convert = (char *)malloc(sizeof(char) * size + 2);
	conv_by_base(num, convert, base_to);
	return (convert);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("total : %s\n", ft_convert_base(argv[1], argv[2], argv[2]));
	return (0);
}
