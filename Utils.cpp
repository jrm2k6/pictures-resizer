#include "Utils.h"
#include <string>
#include <cerrno>

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

