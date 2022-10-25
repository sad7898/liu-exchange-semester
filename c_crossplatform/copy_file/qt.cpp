#include <assert.h>
#include <QTextCodec>
#include <QFile>
int main(int argc, char** argv)
{
  /* Make sure we use UTF-8 for file names; this is needed for the IDA labs */
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
  // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); // Use this in Qt4
  assert(argc==2); /* argv[1] is the destination file */
  /* Your code here */
  QFile::copy("马Häst马.txt",argv[1]);
  return 0;
}
