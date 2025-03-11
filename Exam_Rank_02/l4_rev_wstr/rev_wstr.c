#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *des)
{
    int i = 0;
    while(des[i])
        i++;
    return i;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        char *data = av[1];
        int len = ft_strlen(data);
        len--;
        while(len > 0)
        {
            while(data[len] && (data[len] == 32 || data[len] == '\t'))
            {
                len--;
            }
            int last = len;
            while(data[len] && (data[len] != 32 && data[len] != '\t'))
            {
                len--;
            }
            int start = len;
            start++;
            while(start <= last)
            {
                write(1, &data[start], 1);
                start++;

            }
            while(data[len] && (data[len] == 32 || data[len] == '\t'))
            {
                write(1, &data[len], 1);
                len--;
            }
        }
    }
    write(1,"\n", 1);
}