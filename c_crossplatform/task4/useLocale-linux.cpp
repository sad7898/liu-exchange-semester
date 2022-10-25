
#include <stdio.h>
#include <locale>
 #include <locale.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>


int main()
{
     char *newlocale, *targetLocale = "sv_SE.utf8";
setenv("LANGUAGE", targetLocale);
setenv("LANG", targetLocale);
setenv("LC_MESSAGES", targetLocale);

    pthread_t swedishProg;
    pthread_create(&swedishProg,NULL,RunSwedishProgram,NULL);
    pthread_join(swedishProg,(void*)NULL);

    // unsigned aID;
    // threads[0] = (HANDLE)_beginthreadex(
    //     NULL, 0, RunSwedishProgram, NULL, 0, &aID);

    // unsigned bID;
    // threads[1] = (HANDLE)_beginthreadex(
    //     NULL, 0, RunThreadB, NULL, 0, &bID);

    // WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    // printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
    // printf_s("[Thread main] CRT locale is set to \"%s\"\n",
    //     setlocale(LC_ALL, NULL));
    // printf_s("[Thread main] locale::global is set to \"%s\"\n",
    //     locale().name().c_str());

    // CloseHandle(threads[0]);
    // CloseHandle(threads[1]);
    return 0;
}
void RunSwedishProgram(void *params)
{
    const char* dateFormat = "%a %b %d %H:%M:%S %Y";
    double d = atof("1.2345");
    const char *dateString = "Fri Jul 5 05:04:02 2019";
    struct tm tm;
    std::istringstream ss(dateString);
    ss >> std::get_time(&tm, dateFormat);
    char buffer[100];

    std::locale swedish("sv_SE.utf8");
    std::locale::global(swedish);
    strftime(buffer,sizeof(buffer),dateFormat,&tm);
    printf("[THREAD SW] locale %s\n",setlocale(LC_ALL,NULL));
    printf("%.2f",3.14);
    printf("%s",buffer);
}