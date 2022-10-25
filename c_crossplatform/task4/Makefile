

useLocale-win32.exe: useLocale.cpp
	x86_64-w64-mingw32-g++ -o $@ -std=c++17 useLocale.cpp -static -lstdc++fs

useLocale-win32-run: useLocale-win32.exe 
	wine $< $@

useLocale-linux: useLocale-linux.cpp
	clang++ -Wall -std=c++17 -o $@ $< -lstdc++fs