#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen ( "filename", "mode");
    mode:   "r" - read only;
            "w" - write only;
            "a" - append only;
            "r+" - read and write; should be exist
            "w+" - write and read;
            "a+" -

    if ((fp = fopen (fname, "r"))==NULL)
        fprint (strerr, "%s not open!\n", filename);
        exit(1);
    fclose (fp);

    int ftlush (FILE *fp) - Содержимое буф. будет записано в файл.

    int fscanf(FILE *fp,"....",символ ввода);
    int fprint(FILE *fp,"....",символ вывода);

    int fgetc(FILE *fp);   - - -  int getchar();
    int fputc(int c, FILE *fp);  - - - int putchar(int c);
    char* fgets(char* s, int n, FILE *fp);
    char* fputs(char* s, FILE *fp);
    size_t fread(void *p, size_t sizeobj, size_t nobj, FILE *f);
    size_t fwrite(void *buf, size_t sizeObj, size_t nObj, FILE *f);
    для бинарных ф-в.
    long fiell(FILE *fp);
    тек. позиция в открыт ф-ле.
        fseek(FILE *fp, long offset, int from);
        from:   SEEK_CUR
                SEEK_END
                SEEK_SET
                        смещение
    rewind (f) - встать на начало
    return 0;
}
