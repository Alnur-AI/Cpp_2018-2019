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

    int ftlush (FILE *fp) - ���������� ���. ����� �������� � ����.

    int fscanf(FILE *fp,"....",������ �����);
    int fprint(FILE *fp,"....",������ ������);

    int fgetc(FILE *fp);   - - -  int getchar();
    int fputc(int c, FILE *fp);  - - - int putchar(int c);
    char* fgets(char* s, int n, FILE *fp);
    char* fputs(char* s, FILE *fp);
    size_t fread(void *p, size_t sizeobj, size_t nobj, FILE *f);
    size_t fwrite(void *buf, size_t sizeObj, size_t nObj, FILE *f);
    ��� �������� �-�.
    long fiell(FILE *fp);
    ���. ������� � ������ �-��.
        fseek(FILE *fp, long offset, int from);
        from:   SEEK_CUR
                SEEK_END
                SEEK_SET
                        ��������
    rewind (f) - ������ �� ������
    return 0;
}
