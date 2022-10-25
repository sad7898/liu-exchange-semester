/* In case the C++-compiler is too old for std::filesystem */
#include <fstream>
#if defined(_MSC_VER) || defined(__MINGW32__)
#include <windows.h>
#endif
#include <iostream>
using namespace std;
#if __has_include(<filesystem>)
#include <filesystem>
namespace filesystem = std::filesystem;
#else
#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;
#endif
#include <assert.h>
#if defined(_MSC_VER) || defined(__MINGW32__)
std::wstring ToUtf16(std::string str)
{
    std::wstring ret;
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
    if (len > 0)
    {
        ret.resize(len);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &ret[0], len);
    }
    return ret;
}
#endif

int main(int argc, char** argv)
{
  assert(argc==2); /* argv[1] is the destination file */
   string line;
    #if defined(_MSC_VER) || defined(__MINGW32__)
    ifstream ini_file{
        L"马Häst马.txt"
    }; 
    #else
       ifstream ini_file{
        "马Häst马.txt"
    };
    #endif
    ofstream out_file{ argv[1]};
    if (ini_file && out_file) {
        while (getline(ini_file, line)) {
            #ifdef _MSC_VER
            out_file << ToUtf16(line) << "\n";
            #else
            out_file << line << "\n";
            #endif
        }
        cout << "Copy Finished \n";
    }
    else {
        // Something went wrong
        printf("Cannot read File");
    }
    // Closing file
    ini_file.close();
    out_file.close();
    return 0;
}
