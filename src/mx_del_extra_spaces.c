#include "../inc/libmx.h"

static int count(char *trimstr)
{
    int count = 0;
     for (int i = 0; i < mx_strlen(trimstr); i++) 
	 {
        if (mx_isspace(trimstr[i]) && !mx_isspace(trimstr[i + 1])) 
		{
            count++;
        } else if(!mx_isspace(trimstr[i])){
            count++;
        }
    }
    return count;
}

char *mx_del_extra_spaces(const char *str)
{
    char *trimstr = mx_strtrim(str);
    int j = 0;
    int quantity = count(trimstr);
    char *str2 = mx_strnew(quantity);
    for (int i = 0; i < mx_strlen(trimstr); i++) {
        if (mx_isspace(trimstr[i]) && !mx_isspace(trimstr[i + 1])) {
            str2[j++] = ' ';
        } else if(!mx_isspace(trimstr[i])){
            str2[j++] = trimstr[i];
        }
    }
    mx_strdel(&trimstr);
    return str2;
}
