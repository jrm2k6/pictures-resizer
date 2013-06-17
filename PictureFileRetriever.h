#ifndef PICTUREFILERETRIEVER_H
#define	PICTUREFILERETRIEVER_H

#include <Magick++.h>
#include <string>
#include <vector>

using namespace std;
using namespace Magick;

class PictureFileRetriever
{   
    static string EXTENSIONS[3];
    
    private:
        vector<string> pictures;
        bool isAPicture(string fileName);
    public:
        PictureFileRetriever();
        void getContentFolder(string folderName);
        vector<string> getPicturesFromContent();
        void printContentFolder();
        string toLowerCase(string word);
};

#endif	

