#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "../../libft/includes/libft.h"

char	**ft_split_quote(char *str, char *charset);


void test(char *src, char *charset)
{
	char **splitted;

    ft_putstr_fd("\n\n\n [ test ]\n\n", 1);
    ft_putstr_fd("src:               ", 1);
    ft_putstr_fd(src, 1);
    ft_putstr_fd("\n\nresult:               ", 1);
	splitted = ft_split_quote(src, charset);
    ft_putstr2(splitted);
    ft_freestrarr(splitted);
}


int main()
{


	test("voici\"; \"le; texte; à ;split", ";");
	test("voici\"; \"le\"; texte; à ;split\"", ";");
	test("\"voici;\" le ; texte; à ;split", ";");
	test("\"voici; le ; texte; à ;split\"", ";");


	ft_putstr_fd("\n----------------------------\n", 1);
    test("voici'; 'le; texte; à ;split", ";");
    test("voici'; 'le'; texte; à ;split'", ";");
    test("'voici;' le ; texte; à ;split", ";");
    test("'voici; le ; texte; à ;split'", ";");


	ft_putstr_fd("\n----------------------------\n", 1);
    test("voici'\"; 'le; texte; à ;split", ";");


	ft_putstr_fd("\n----------------------------\n", 1);
    test("voici'; le; texte; à ;split", ";");

	return (0);
}
