#include "../inc/libmx.h"

int mx_max(int a, int b, int c){
    if(a < b){
        if(a > c){
            return a;
        }
        else if(b > c){
            return c;
        }
        else{
            return b;
        }
    }
    else if(a < c){
        return a;
    }
    else {
        return b;
    }
}

