#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	bits[8];
	int		nb;
	int		count;
	char	z;

	nb = octet;
	count = 0;
	while (count < 8)
	{
		bits[count] = nb % 2;
		nb = nb / 2;
		count++;
	}
	if (bits[4] == 0) //daca pe bitul 4 ii 0 se inlocuieste cu 1
		bits[4] = 1;
	while (count - 1 >= 0)
	{
		z = bits[count - 1] + 48;
		write(1, &z, 1);
		count--;
	}
}

int main()
{
	unsigned char bit = 12;
	print_bits(bit);
	return (0);
}
