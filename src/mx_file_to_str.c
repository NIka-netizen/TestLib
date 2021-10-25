#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {    
    int file2;
    char *result = NULL;
    int count = 0;
    char c;

    file2 = open(file, O_RDONLY);
    while (read(file2, &c, 1))
        count++;
    close(file2);
    file2 = open(file, O_RDONLY);
    result = mx_strnew(count);
    read(file2, result, count);
    close(file2);

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


    file2 = open(file, O_RDONLY);
    char *res = (char *)malloc(count + 1);

    n = read(file2, s, 1);

    for(int i = 0; i < count && n > 0; ++i) 
    {
        if (s[0] == '.' || s[0] == '#' || s[0] == '\n')
        {
            res[i] = s[0];
            ++i;
        }
        n = read(file2, s, 1);
        --i;
    }
    res[count] = '\0';
    close(file2);
    return res;
}
