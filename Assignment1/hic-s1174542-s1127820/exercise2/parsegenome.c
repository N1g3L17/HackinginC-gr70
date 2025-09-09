#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool file_correct(filename)
{
    FILE* fp = fopen(filename, "r");
    char ch;
    bool correct = true;
    while ((ch = fgetc(fp) != '/n' && ch != EOF))
    {
        if (ch != 'A' && ch != 'C' && ch != 'G' && ch != 'T')
        {
            correct = false;
            return correct;
        }
    }
}

int main()
{
    return 0;
}