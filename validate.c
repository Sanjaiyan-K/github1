#include "apc.h"
#include <ctype.h>

int validate(int argc, char ** argv){

    if(argc != 4){
        return FAILURE;
    }

    int i = 0;
    int j = 0;

    while(argv[1][i]){
        if(!isdigit(argv[1][i])){
            return FAILURE;
        }
        i++;
    }

    while(argv[3][j]){
        if(!isdigit(argv[3][j])){
            return FAILURE;
        }
        j++;
    }

    if(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/' ){
        return FAILURE;
    }

    return SUCCESS;
}