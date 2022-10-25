#include <windows.h>
#include <assert.h>

int main(int argc, char **argv)
{
  assert(argc==1);
  LPCWSTR dest = L"win32.txt";
  CopyFileW(L"马Häst马.txt",dest,FALSE);
  /* Your code here. */
  return 0;
}
