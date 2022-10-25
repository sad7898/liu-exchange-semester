#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace std {

static void getline(char *line, FILE *fin)
{
  int c = '\0', cur = 0;
  while (c != '\n' && (c = fgetc(fin)) != EOF) {
    line[cur++] = c;
  }
  line[cur] = '\0';
}

}

using namespace std;

int main(int argc, char **argv)
{
  int cur = 0;
  char *lines[31500]; //set more for safety
  char line[1000];
  // Fix num lines, num columns, strdup-1
  FILE *fin = fopen("bible.txt", "r");
  while (!feof(fin)) {
    getline(line, fin);
    lines[cur] = (char*) malloc(strlen(line)+1);
    strcpy(lines[cur], line);
    cur++;
  }
  fclose(fin);
  FILE *fout = fopen("copy.txt", "w");
  for (int i=0; i<cur; i++) {
    fputs(lines[i], fout);
  }
  fclose(fout);
  return 0;
}
