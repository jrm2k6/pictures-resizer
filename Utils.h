#ifndef UTILS_H
#define	UTILS_H

#include <string>

using namespace std;

class Utils
{
        public:
            Utils();
            string getCurrentWorkingDirectory();
            void createFolder(string name);
            string toLowerCase(string word);
};

#endif	/* UTILS_H */

