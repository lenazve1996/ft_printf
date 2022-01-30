#include "stdio.h"
#include <stdlib.h>
#include <limits.h>
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

    a =  printf("% dh\n", 1);
    b =  ft_printf("% dh\n", 1);
    printf("%d\n", a);
    printf("%d\n", b);
	a = printf(" %u \n", LONG_MAX);
	b = ft_printf(" %u \n", LONG_MAX);
    printf("%d\n", a);
    printf("%d\n", b);
	a = printf(" %u \n", LONG_MIN);
	b = ft_printf(" %u \n", LONG_MIN);
    printf("%d\n", a);
    printf("%d\n", b);
	a = printf(" %u \n", ULONG_MAX);
	b = ft_printf(" %u \n", ULONG_MAX);
	printf("%d\n", a);
    printf("%d\n", b);
	a = printf(" %u \n", 9223372036854775807LL);
	b = ft_printf(" %u \n", 9223372036854775807LL);
	printf("%d\n", a);
    printf("%d\n", b);
    // str = (char *)malloc(5 * sizeof(char));
    // str = "hell";
    // standart = printf(".9s\n", NULL);
    // printf("%d\n", standart);
    // my = ft_printf(".9s\n", NULL);
    // printf("%d\n", my);
}