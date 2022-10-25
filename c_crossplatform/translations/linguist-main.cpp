#include <stdio.h>
#include <QCoreApplication>
#include <QTranslator>
#include <libintl.h>
extern "C" void setuplocale();
class TestTranslation : public QCoreApplication /* an application without GUI */
{
public:
  TestTranslation(int argc, char** argv) : QCoreApplication(argc, argv)
  {
    QTranslator translator;
    if (translator.load("example_sv.qm")) {

    
    this->installTranslator(&translator);
    /* Install a translator */
    /* Mark strings for translation and use linguist to create translation files.
     * Output the translated strings
     *  */
    puts(QObject::tr("The current language is the default (C/POSIX)\n").toUtf8());
    puts(QObject::tr("The horse can run.\n").toUtf8());
    puts(QObject::tr("How fast can the horse run?\n").toUtf8());
    puts(QObject::tr("It typically runs at speed of less than 50 km/h.\n").toUtf8());
    }
  }
};

int main(int argc, char** argv)
{
  setuplocale();
  TestTranslation test(argc, argv);
  return 0;
}
