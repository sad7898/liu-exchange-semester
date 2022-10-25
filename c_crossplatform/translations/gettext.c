#include <libintl.h>
void setup()
{
  /* Your code here. Setup a domain for gettext. */
  /* bindtextdomain(...); */
  /* textdomain(...); */
  /* Use UTF-8 or gettext prints question marks for your Swedish letters */
  /* bind_textdomain_codeset(... , "utf8"); */
  bindtextdomain("horse","/home/sirko805/tdde45-lab3-l11n-i18n-cross-platform/translations/");
  bind_textdomain_codeset("horse","UTF-8");
  textdomain("horse");
}

