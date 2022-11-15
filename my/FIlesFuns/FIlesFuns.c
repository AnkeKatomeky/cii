#include <stdio.h>

void FileFun(int value)
{
    FILE *file;
    char hello[] = "hello world! Number is %d";
    char *fileName = "D:/cii/bin/text.txt";

    int n = sizeof(hello) / sizeof(hello[0]);

    Write(fileName, hello, value);
    Read(fileName);
}

int Write(char *filename, char message[], int n)
{
    FILE *fp;
    if ((fp = fopen(filename, "w")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    
    fprintf(fp, message, n);

    fclose(fp);
    return 0;
}

int Read(char *filename)
{
    FILE *fp;
    char c;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // после записи считываем посимвольно из файла
    while ((c = getc(fp)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}