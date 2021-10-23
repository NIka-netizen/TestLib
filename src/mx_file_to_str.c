#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {    
    int file;
    char *result = NULL;
    int count = 0;
    char c;

    file = open(filename, O_RDONLY);
    while (read(file, &c, 1))
        count++;
    close(file);
    file = open(filename, O_RDONLY);
    result = mx_strnew(count);
    read(file, result, count);
    close(file);

    char s[1];
    int n;
    int i = 0;
    while(result[i + 1] != '\0') 
    {
        if (result[i] == '#' || result[i] == '.' || result[i] == '\n' || result[i] == ',' || result[i] == '"'){
            if (result[i] != ',' || result[i] != '"')
                ++count;
        }
        else{
            mx_printerr("map error.\n");
            exit(0);
        }
        i++;
    }


    file = open(filename, O_RDONLY);
    char *res = (char *)malloc(count + 1);

    n = read(file, s, 1);

    for(int i = 0; i < count && n > 0; ++i) 
    {
        if (s[0] == '.' || s[0] == '#' || s[0] == '\n')
        {
            res[i] = s[0];
            ++i;
        }
        n = read(file, s, 1);
        --i;
    }
    res[count] = '\0';
    close(file);
    return res;
}
