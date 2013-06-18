#include "PictureFileRetriever.h"
#include "Utils.h"
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

void PictureFileRetriever::getContentFolder(string folderName)
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

bool PictureFileRetriever::isAPicture(string fileName)
{
    int foundDelimiter;
    Utils* utils = new Utils();
    
    int lengthArray = sizeof(EXTENSIONS)/sizeof(string);
    for (int i=0; i < lengthArray; i++)
    {
        foundDelimiter = utils->toLowerCase(fileName).find(EXTENSIONS[i]);
        if (foundDelimiter != -1)
        {
            return true;
        }
    }
    
    return false;
    
}
