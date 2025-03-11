#include<unistd.h>
#include"header.h"

void is_closed_walls(char** two_d,char* lines)
{
    int len;
    int i;
    int j;
    i = 0;
    len  = 0;
    while(two_d[len])
    {
        len ++;
    }
    len--;
    while(two_d[0][i])
    {
        if(two_d[0][i] != '1' || two_d[len][i] != '1')
        {
            write(1,"invalid map not closed\n",23);
            free(lines);
            ftt_free(two_d);
            exit(1);
        }
        i++;
    }
    i = 0;
    j = ft_strlen(*two_d);
    while(len > i)
    {
        // if(two_d[i][0] == '1' || two_d[i][j] == '1')
        // {
        //     printf("this is two_d[i][0] %c\n",two_d[i][0]);
        //     printf("this is two_d[i][j] %c\n",two_d[i][j]);
        //     write(1,"invalid map not closed second while\n",35);
        //     free(lines);
        //     ftt_free(two_d);
        //     exit(1);
        // }
        printf("this is two_d[i][0] %c\n",two_d[i][0]);
        printf("this is two_d[i][j] %c\n",two_d[i][j]);
        printf("i%i\n",i);
        printf("j%i\n",j);
        printf()
        i++;
    }
    
    (void)lines;
    printf("%i\n",len);
}


int main(int argc,char** argv)
{
    char** two_d;
    char* lines;

    check_argc(argc);
    check_extention(argv[1]);
    check_if_file_exist(argv[1]);
   
    lines  = join_lines(argv[1]);
    two_d = split_lines(lines,'\n');
    check_is_square(two_d,lines);
    check_player(two_d,lines);
    check_exit(two_d,lines);
    check_coins(two_d,lines);
    is_closed_walls(two_d,lines);

    free(lines);
    ftt_free(two_d);
    return 0;
}
