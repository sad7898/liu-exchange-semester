// multithread_locale_1.cpp
// compile with: /EHsc /MD
#include <clocale>
#include <stdio.h>
#include <cstdio>
#include <locale>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h> 
#include <process.h>
#include <windows.h>

#define NUM_THREADS 2
using namespace std;

unsigned __stdcall RunSwedishProgram(void *params);
unsigned __stdcall RunThreadB(void *params);

BOOL localeSet = FALSE;

int main()
{
      char *newlocale, *targetLocale = "sv_SE.utf8";
SetEnvironmentVariable("LANGUAGE", targetLocale);
SetEnvironmentVariable("LANG", targetLocale);
SetEnvironmentVariable("LC_MESSAGES", targetLocale);
    HANDLE threads[NUM_THREADS];

    unsigned aID;
    threads[0] = (HANDLE)_beginthreadex(
        NULL, 0, RunSwedishProgram, NULL, 0, &aID);

    unsigned bID;
    threads[1] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadB, NULL, 0, &bID);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread main] locale::global is set to \"%s\"\n",
        locale().name().c_str());

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    return 0;
}
unsigned __stdcall RunSwedishProgram(void *params)
{
    const char* dateFormat = "%a %b %d %H:%M:%S %Y";
    double d = atof("1.2345");
    const char *dateString = "Fri Jul 5 05:04:02 2019";
    struct tm tm;
    istringstream ss(dateString);
    ss >> std::get_time(&tm, dateFormat);
    char buffer[100];

    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
    locale swedish("sv_SE.utf8");
    locale::global(swedish);
    localeSet = TRUE;
    // strftime(buffer,sizeof(buffer),dateFormat,&tm);
    printf_s("[THREAD SW] locale %s\n",setlocale(LC_ALL,NULL));
    printf_s("%.2f",3.14);
    printf_s("%s",buffer);
    return 0;
}

unsigned __stdcall RunThreadB(void *params)
{
    while (!localeSet)
        Sleep(100);

    
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());

    return 0;
}