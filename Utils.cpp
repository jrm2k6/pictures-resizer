#include "Utils.h"
#include <string>
#include <cerrno>
#include <sys/types.h>
#include <sys/stat.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define GetCurrentDir getcwd

using namespace std;

Utils::Utils() {}

string Utils::getCurrentWorkingDirectory()
{
    char currentPathBuffer[FILENAME_MAX];

    if (!GetCurrentDir(currentPathBuffer, sizeof(currentPathBuffer)))
    {
        return " " + errno;
    }

    currentPathBuffer[sizeof(currentPathBuffer) - 1] = '\0';
    return currentPathBuffer;
}

string Utils::toLowerCase(string word)
{
    const int length = word.length();
    for(int i=0; i < length; ++i)
    {
	word[i] = tolower(word[i]);
    }
    
    return word;
}

void Utils::createFolder(string name)
{
	mkdir(name.c_str(), 0777);
}
