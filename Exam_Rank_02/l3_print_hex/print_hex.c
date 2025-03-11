#include <unistd.h>

void hex(int sayi)
{
    if(sayi > 16)
    {
        hex(sayi / 16);
        sayi = sayi % 16;
    }
    
    char yaz;
    if(sayi > 9)
    {
        yaz = ((sayi % 10) + 'a');  
    }
    else
    {
        yaz = (sayi + '0');
    }
    
    write(1, &yaz, 1);
}
int ft_strlen(char* sa)
{
    int i = 0;
    while(sa[i])
        i++;
    
    return i;

}
int atoi(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    
    int sayi = 0;
    while(str[i])
    {
        sayi *= 10;
        sayi += str[i] - '0';   
        i++;
    }
   
    return sayi;
}
int main(int ac, char** av)
{
    if(ac == 2)
    {
        char *data = av[1];
        int sa = atoi(data);
        hex(sa);
    }
    write(1, "\n", 1);
}