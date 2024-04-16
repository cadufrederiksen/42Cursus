#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char *str, int* resultlen)
{
    if (!str)//se nao houver str, str  = (null)
        str ="(null)";
    while (*str)
    {
       resultlen += write(1, str, 1);
       str++;
    }
}

void    ft_putdigit(long long nbr, int base, int *resultlen)//long long int
{
    char *str = "0123456789abcdef";
    if (nbr < 0)
    {
        nbr *= -1;
        *resultlen += write(1, "-", 1);
    }
    if (nbr >= base)//putnbr normal
    {
        ft_putdigit((nbr / 10), base, resultlen);
        nbr %= base;
    }
    *resultlen += write(1, &str[nbr], 1); 
}

int ft_printf(const char *str, ...)
{
    int resultlen;//total de caracteres escritos
    va_list args; //args

    resultlen = 0; 
    va_start (args, str); //inicializa los args
    while (*str)
    {
        if (*str == '%' && (*(str + 1) == 'c' || *(str + 1) == 'd' || *(str + 1) == 'x'))// si la posicion es un % busca a seguinte
        {
            str++;//avança para a letra e filtra
            if (*str == 's')
                ft_putstr(va_arg(args, char *), &resultlen); //putstr normal
            if (*str == 'd')
                ft_putdigit(va_arg(args, long long int), 10, &resultlen);//putnbr que serve para os dois 
            if (*str == 'x')      
                ft_putdigit(va_arg(args, long long int), 16, &resultlen);
        }
        else 
            resultlen += write(1, str, 1); //se nao so escreve
        str++;
    }  
    va_end(args); //termina os argumentos
    return (resultlen);
}