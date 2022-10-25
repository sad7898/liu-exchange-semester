#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#include <windows.h>
#endif

/*!
  Opens a file

  \param str a UTF8-encoded filename
  \param mode the mode argument of fopen
*/
FILE* my_fopen(char *str, char *mode)
{
#if defined(_MSC_VER) || defined(__MINGW32__)
  wchar_t utf16FileName[32];
  wchar_t utf16Mode[32];
    int len1 = MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), NULL, 0);
    if (len1 > 0)
    {
        MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), &utf16FileName[0], len1);
    }
    int len2 = MultiByteToWideChar(CP_UTF8,0,mode,strlen(mode),NULL,0);
    if (len2 > 0) {
      MultiByteToWideChar(CP_UTF8,0,mode,strlen(mode),&utf16Mode[0],len2);
    }
  /* Hint: You want to modify this code */
  return _wfopen(&utf16FileName, &utf16Mode);
#else
  /* Linux handles UTF-8 by default */
  return fopen(str, mode);
#endif
}

int main(int argc, char **argv)
{
  FILE *f0, *f1, *f2;
  char *name1 = "teståäö", *name2 = NULL, *str = "Test\n";
  char buffer[256] = {0};
  size_t n;
  f0 = fopen("fileWithFileName", "r");
  assert(f0);
  assert(fgets(buffer, 255, f0));
  if (buffer[strlen(buffer)-1] == '\n') {
    buffer[strlen(buffer)-1] = '\0';
  }
  /* Should contain UTF-8 "马Häst马.txt" and no possibility to become a UTF-16 string by accident */
  name2 = strdup(buffer);
  fclose(f0);
  f1 = my_fopen(name1, "w");
  assert(f1);
  assert(fputs(str, f1) >= 0);
  fclose(f1);
  printf("%s now contains the string:\n%s", name1, str);

  f2 = my_fopen(name2, "r");
  if (!f2) {
    fprintf(stderr, "Failed to open file %s: %s\n", name2, strerror(errno));
    return 1;

  }
  n = fread(buffer, 1, 256, f2);
  printf("Read %ld units of 1 byte\n", (long) n);
  assert(n == 109);
  assert(0 == strncmp("Häst", buffer, 4));
  puts("The test file starts with the string \"Häst\"");
  return 0;
}
