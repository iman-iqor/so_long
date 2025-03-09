#include"header.h"

void check_is_square(char** two_d,char* lines)
{
    int len;
    int i;
    i =0;
    len = ft_strlen(two_d[0]);
    while(two_d[i])
    {
        if(len != ft_strlen(two_d[i]))
        {
            write(2,"invalid map\n",12);
            ftt_free(two_d);
            free(lines);
            exit(1);
        }
        i++;
    }
}
