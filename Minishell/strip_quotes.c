#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    i[1] => ascii of opening quote
    i[2] => position of opening quote
    i[3] => ascii of current quote
    i[4] => position of current quote
    i[5] => number of similar quotes
*/

char    *remove_quotes(char *str)
{
    int     i[6] = {0, 0, 0, 0, 0, 0};
    int     j = -1;
    int     k = 0;
    int    quote_state = 0; //change to boolean
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));
    if (!new_str)
        return NULL;
    while (str[++j])
    {
        //copy all strings to new one if you havent seen a quote or if the quote state is true
        while ((str[j] != '\"' && str[j] != '\'' ) || quote_state == 1)
        {
            if (str[j] == '\"' || str[j] == '\'' && str[j] == i[1] && j != i[2])
                break;
            new_str[k++] = str[j++]; 
        }
        if (str[j] == '\"' || str[j] == '\'')
        {
            if (!(quote_state))
            {
                i[1] = str[j];
                i[2] = j;
                quote_state = 1;
            }
            i[3] = str[j];
            i[4] = j;
        }
        if (i[3] == i[1] && i[4] != i[2])
            quote_state = 0;
    }
    return (new_str);
}


int main() 
{
    char* input = "This is a \"test 'string'\" with 'multiple' quotes and \" charac'>'ters.\"";
    char* output = remove_quotes(input);
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    free(output);
    return 0;
}
