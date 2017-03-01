#include <stdlib.h>

int		ft_nr(int value, int base)
{
	int result;

	if (value == 0)
		return (1);
	result = 0;
	if (value < 0)
		result = 1;
	while (value != 0)
	{
		value = value / base;
		result ++;
	}
	return (result);
}

char	ft_char(int x)
{
	if (x <= 9)
		return (x + 48);
	if (x == 10)
		return ('A');
	if (x == 11)
		return ('B');
	if (x == 12)
		return ('C');
	if (x == 13)
		return ('D');
	if (x == 14)
		return ('E');
	return ('F');
}

char	*ft_itoa_base(int value, int base)
{
	int nr;
	int rest;
	char *result;
	int minus;
	
	if ((base != 10 && value < 0) || base < 2 || base > 16)
		return (NULL);
	minus = 0;
	nr = ft_nr(value, base);
	result = (char*)malloc((nr + 1)*sizeof(*result));
	result[nr] = '\0';
	if (value == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (value == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		result[2] = '1';
		result[3] = '4';
		result[4] = '7';
		result[5] = '4';
		result[6] = '8';
		result[7] = '3';
		result[8] = '6';
		result[9] = '4';
		result[10] = '8';
		return (result);
	}	
	if (value < 0)
	{
		result[0] = '-';
		nr--;
		value = value * (-1);
		minus = 1;
	}
	while (value != 0)
	{
		rest = value % base;
		result[nr - 1 + minus] = ft_char(rest);
		nr--;
		value = value / base;
	}
	return (result);
}
