#include"header.h"




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
    free(lines);
    ftt_free(two_d);
    return 0;
}
