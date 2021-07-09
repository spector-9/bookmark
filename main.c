#include "clipboard.h"
#include "stdio.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "string.h"
int main()
{
    char* result;
    FILE* file;
    Bool INPUT_SAFE = False;

    result = clip();
    file = fopen("bookmark.tsv", "a+");
    char line[33];
    int lineSizeMax = sizeof(line)-2;

    int c;

    while (INPUT_SAFE != True)
    {
        printf("Enter the name for your bookmark: ");
        fgets(line, sizeof(line), stdin);
        if (strlen(line) > lineSizeMax)
        {
            printf("Name cannot be longer than 30 characters.\n");
            if (line[lineSizeMax] != '\n')
            {
                while ( (c = getchar()) != '\n' && c != EOF ) {}
            }
        }

        else
        {
            INPUT_SAFE = True;
        }
    }
    line[strlen(line)-1] = 0;
    fprintf(file, "%s\t%s\n", line, result);
    fclose(file);
=======
=======
#include "string.h"
>>>>>>> f020f5e (Can put dat in tsv now)
int main()
{
    char* result;
    FILE* file;
    Bool INPUT_SAFE = False;

    result = clip();
<<<<<<< HEAD
    printf("%s\n", result);
>>>>>>> bc91f40 (Initial commit)
=======
    file = fopen("bookmark.tsv", "a+");
    char line[33];
    int lineSizeMax = sizeof(line)-2;

    int c;

    while (INPUT_SAFE != True)
    {
        printf("Enter the name for your bookmark: ");
        fgets(line, sizeof(line), stdin);
        if (strlen(line) > lineSizeMax)
        {
            printf("Name cannot be longer than 30 characters.\n");
            if (line[lineSizeMax] != '\n')
            {
                while ( (c = getchar()) != '\n' && c != EOF ) {}
            }
        }

        else
        {
            INPUT_SAFE = True;
        }
    }
    line[strlen(line)-1] = 0;
    fprintf(file, "%s\t%s\n", line, result);
    fclose(file);
>>>>>>> f020f5e (Can put dat in tsv now)
}
