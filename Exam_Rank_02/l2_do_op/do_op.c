#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if(ac == 4)
    {
        char op = av[2][0];
        if(op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
            return printf("\n");

        int s1 = atoi(av[1]);
        int s2 = atoi(av[3]);
        
        if(op == '+')
            printf("%d", (s1+s2));
        else if(op == '-')
            printf("%d", (s1-s2));
        else if(op == '*')
            printf("%d", (s1*s2));
        else if(op == '/')
            printf("%d", (s1/s2));
        else if(op == '%')
            printf("%i", (s1%s2));
        else
            printf("\n");
    }
    
    printf("\n");


}