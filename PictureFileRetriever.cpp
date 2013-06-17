#include "PictureFileRetriever.h"
#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>

using namespace std;



PictureFileRetriever::PictureFileRetriever() 
{
}

string PictureFileRetriever::EXTENSIONS[] = {"jpg", "png", "jpeg"};

void PictureFileRetriever::getContentFolder(std::string folderName)
{
    DIR *dp;
    struct dirent *dirp;
    
    dp = opendir(folderName.c_str());
    
    if (dp == NULL)
    {
        cout << "Error(" << errno << ") opening " << folderName << endl;
    }
    else
    {
        while ((dirp = readdir(dp)) != NULL)
        {
           string fileName = dirp->d_name;
           if (isAPicture(fileName))
           {
                pictures.push_back(dirp->d_name);
           }
        }
    }
}

vector<string> PictureFileRetriever::getPicturesFromContent() 
{
    return pictures;
}


void PictureFileRetriever::printContentFolder()
{
    for(std::vector<string>::iterator it = pictures.begin(); it != pictures.end(); ++it)
    {
        std::cout << *it << endl;
    }
}

string PictureFileRetriever::toLowerCase(string word)
{
    const int length = word.length();
    for(int i=0; i < length; ++i)
    {
	word[i] = tolower(word[i]);
    }
    
    return word;
}

bool PictureFileRetriever::isAPicture(string fileName)
{
    int foundDelimiter;
    
    int lengthArray = sizeof(EXTENSIONS)/sizeof(string);
    for (int i=0; i < lengthArray; i++)
    {
        foundDelimiter = toLowerCase(fileName).find(EXTENSIONS[i]);
        if (foundDelimiter != -1)
        {
            return true;
        }
    }
    
    return false;
    
}
