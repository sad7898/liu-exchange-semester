import time
import locale


locale.setlocale(locale.LC_ALL, "sv_SE.UTF8")
num = 1.9877
num = locale.format_string("%.5f", num)
currentDate = time.strftime("%a %d %b %Y %H:%M:%S")
print(num)
print(currentDate)
