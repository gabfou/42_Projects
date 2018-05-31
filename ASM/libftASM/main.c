#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/* Part 1 */
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, char *src);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_puts(char *s);

/* Part 2 */
int	ft_strlen(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *str);

/* Part 3 */
void	ft_cat(int fd);
/* Bonus */
int	ft_isupper(int c);
int	ft_islower(int c);


void	ft_partone(void)
{
	int ret;
	char *str;
	char buf[9];
/* Part 1 */
printf("\033[31mPartie 1 : \n\n");

	str = strdup("test");
	printf("\033[32mTest de ft_bzero\033[0m\n");
	printf("ft_bzero(%s, 4)\n", str);
	ft_bzero((void *)str, 4);
	printf("(en int (pour y voir quelque chose)): %d%d%d%d\n\n", str[0], str[1], str[2], str[3]);


	printf("\033[32mft_strcat\033[0m\n");
	ft_strcat(buf, "");
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	ft_strcat(buf, "Bon");
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	ft_strcat(buf, "j");
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	ft_strcat(buf, "our.");
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	ft_strcat(buf, "");
	write(1, buf, strlen(buf));
	write(1, "\n", 1);

	printf("\033[32mft_isalpha\033[0m\n");
	printf("%c, retour : %d\n", 'z', ft_isalpha('z'));
	printf("%c, retour : %d\n", 'B', ft_isalpha('B'));
	printf("%c, retour : %d\n", '9', ft_isalpha('9'));
	printf("%c, retour : %d\n", 'a', ft_isalpha('a'));
	printf("%c, retour : %d\n\n", ' ', ft_isalpha(' '));

	printf("\033[32mft_isdigit\033[0m\n");
	printf("%c, retour : %d\n", '0', ft_isdigit('0'));
	printf("%c, retour : %d\n", '4', ft_isdigit('4'));
	printf("%c, retour : %d\n", '9', ft_isdigit('9'));
	printf("%c, retour : %d\n", 'a', ft_isdigit('a'));
	printf("%c, retour : %d\n\n", ' ', ft_isdigit(' '));

	printf("\033[32mft_isalnum\033[0m\n");
	printf("%c, retour : %d\n", 'z', ft_isalnum('z'));
	printf("%c, retour : %d\n", 'B', ft_isalnum('B'));
	printf("%c, retour : %d\n", '9', ft_isalnum('9'));
	printf("%c, retour : %d\n", 'a', ft_isalnum('a'));
	printf("%c, retour : %d\n\n", ' ', ft_isalnum(' '));

	printf("\033[32mft_isascii\033[0m\n");
	printf("%c, retour : %d\n", 'z', ft_isascii('z'));
	printf("%c, retour : %d\n", -19, ft_isascii(-19));
	printf("%c, retour : %d\n", '9', ft_isascii('9'));
	printf("%c, retour : %d\n", 128, ft_isascii(128));
	printf("%c, retour : %d\n\n", 150, ft_isascii(150));

	printf("\033[32mft_isprint\033[0m\n");
	printf("%c, retour : %d\n", 'z', ft_isprint('z'));
	printf("%c, retour : %d\n", -19, ft_isprint(-19));
	printf("%c, retour : %d\n", '9', ft_isprint('9'));
	printf("%c, retour : %d\n", 126, ft_isprint(126));
	printf("%c, retour : %d\n\n", 127, ft_isprint(127));

	printf("\033[32mft_toupper\033[0m\n");
	printf("%c deviens %c\n", 'a', ft_toupper('a'));
	printf("%c deviens %c\n", 'B', ft_toupper('b'));
	printf("%c deviens %c\n", '5', ft_toupper('5'));
	printf("%c deviens %c\n\n", ' ', ft_toupper(' '));

	printf("\033[32mft_tolower\033[0m\n");
	printf("%c deviens %c\n", 'a', ft_tolower('a'));
	printf("%c deviens %c\n", 'B', ft_tolower('b'));
	printf("%c deviens %c\n", '5', ft_tolower('5'));
	printf("%c deviens %c\n\n", ' ', ft_tolower(' '));

	printf("\033[32mft_puts\033[0m\n");
	printf("ft_puts(\"Appel de ft_puts\")\n");
	ret = ft_puts("Appel de ft_puts");
	printf("\nretour : %d\n\n", ret);
}


void	ft_parttwo(void)
{
	int ret;
	char *str;
/* Part 2 */
printf("\033[31mPartie 2 : \n\n");


	printf("\033[32mft_strlen\033[0m\nparametre : bonjour");
	ret = ft_strlen("bonjour");
	printf("\nretour : %d\n", ret);
	ret = ft_strlen("");
	printf("\nTest 2 : \nretour : %d\n\n", ret);


	str = strdup("test");
	printf("\033[32mft_memset\033[0m\n");
	printf("ft_memset(%s, '9', 3)\n", str);
	printf("Retour : %s\n\n", ft_memset((void *)str, '9', 3));

	str = strdup("Chaine 1\0");
	printf("\033[32mft_memcpy\033[0m\n");
	printf("ft_memcpy(%s, %s, 4):\n", str, "ooook");
	printf("%s\n\n", (char*)ft_memcpy(str, "ooook", 4));

	str = strdup("Chaine 1");
	printf("\033[32mft_strdup\033[0m\n");
	printf("Copie de 'test de copie d'une chaine'\n");
	printf("%s\n\n", ft_strdup("test de copie d'une chaine"));

}

void	ft_partthree(int ac, char **av)
{
	printf("\033[31mPartie 3 : \n\n");

	printf("\033[32mTest de ft_cat\033[0m\n");
	ft_cat(0);
	ft_cat(open(__FILE__, O_RDONLY));
	ft_cat(open(av[0], O_RDONLY));
	ft_cat(-42);
	(void)ac;
}

void	ft_bonus(void)
{
/* Bonus */
printf("\033[31mBonus : \n\n");


	printf("\033[32mft_isupper\033[0m\n");
	printf("%c, retour : %d\n", '0', ft_isupper('0'));
	printf("%c, retour : %d\n", 'a', ft_isupper('a'));
	printf("%c, retour : %d\n", 'A', ft_isupper('A'));
	printf("%c, retour : %d\n", 'f', ft_isupper('f'));
	printf("%c, retour : %d\n\n", 'F', ft_isupper('F'));

	printf("\033[32mft_islower\033[0m\n");
	printf("%c, retour : %d\n", '0', ft_islower('0'));
	printf("%c, retour : %d\n", 'a', ft_islower('a'));
	printf("%c, retour : %d\n", 'A', ft_islower('A'));
	printf("%c, retour : %d\n", 'f', ft_islower('f'));
	printf("%c, retour : %d\n\n", 'F', ft_islower('F'));
}


int	main(int ac, char **av)
{
	int i = 1;

	if (ac == 1)
	{
		ft_partone();
		ft_parttwo();
		ft_partthree(ac, av);
		ft_bonus();
	}
	else if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], "part1") == 0)
				ft_partone();
			else if (strcmp(av[i], "part2") == 0)
				ft_parttwo();
			else if (strcmp(av[i], "part3") == 0)
				ft_partthree(ac, av);
			else if (strcmp(av[i], "bonus") == 0)
				ft_bonus();
			else
				printf("arg must be 'part1', 'part2' or 'bonus'");
			i++;
		}
	}
	return (0);
}
