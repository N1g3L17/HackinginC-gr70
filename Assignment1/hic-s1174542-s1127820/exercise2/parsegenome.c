#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool file_correct(char *filename, int counts[])
{
    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Could not open file %s\n", filename);
        return false;
    }
    char ch;
    int letter_count = 0;
    int line_count = 0;
    bool correct = true;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (letter_count == 100 && ch == '\n')
        {
            letter_count = 0;
            line_count++;
        }
        else if (letter_count == 100 && ch != '\n')
        {
            return false;
        }
        else if (ch != 'A' && ch != 'C' && ch != 'G' && ch != 'T')
        {
            return false;
        }
        else
        {
            if (ch == 'A') counts[0]++;
            if (ch == 'C') counts[1]++;
            if (ch == 'G') counts[2]++;
            if (ch == 'T') counts[3]++;
            letter_count++;
        }
    }
    fclose(fp);
    return line_count == 500;
}

int main(int argc, char *argv[])
{
    int counts[] = {0, 0, 0, 0}; // A, C, G, T
    bool correct = file_correct(argv[1], counts);
    printf("File correct: %d\n", correct);
    if (correct)
    {
        printf("A: %d\nC: %d\nG: %d\nT: %d\n", counts[0], counts[1], counts[2], counts[3]);
        return 0;
    }
    return 1;
}