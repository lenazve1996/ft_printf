#include "stdio.h"
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
    // char *str;
    // int standart;
    // int my;

    int a;
    int b;

    a = 0;
    b = 0;
    a = printf("this %i number\n", -267);
    b = ft_printf("this %i number\n", -267);
    printf("%d\n", a);
    printf("%d\n", b);
    // str = (char *)malloc(5 * sizeof(char));
    // str = "hell";
    // standart = printf(".9s\n", NULL);
    // printf("%d\n", standart);
    // my = ft_printf(".9s\n", NULL);
    // printf("%d\n", my);
}