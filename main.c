#include"header.h"

int check_extention(char *argv)
{
    int len;
    len  = ft_strlen(argv);
    if(!(ft_strncmp(argv+len-4,".ber",4)))
        return 1;
    return 0;
}
void check_argc(int argc)
{
    if(argc == 1)
    {
        write(1,"u should add the file that contains the map\n",44);
        exit(1);
    } 
}

int main(int argc,char** argv)
{
    check_argc(argc);

    if(check_extention(argv[1]))
    {
        printf("good extention\n");
    }
    else
    {
        printf("bad extention\n");
    }
    return 0;
}