#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "../../libft/includes/libft.h"

char	**ft_split_quote(char *str, char *charset);


void test(char *src, char *charset)
{
	int multi;

    ft_putstr_fd("\n\n\n [ test ]\n\n", 1);
    ft_putstr_fd("src:               ", 1);
    ft_putstr_fd(src, 1);
    ft_putstr_fd("\n\nresult:               ", 1);
	multi = ft_check_multilines(src, charset);
    ft_putstr_fd(multi ? "Multilines" : "Ok", 1);
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