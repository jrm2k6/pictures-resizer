#include "PictureResizer.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Magick;

string PictureResizer::PICTURE_SIZE  = "800x600";

PictureResizer::PictureResizer(vector<string> _toBeResized, bool _newDirectoryNeeded) 
{
    toBeResized = _toBeResized;
    newDirectoryNeeded = _newDirectoryNeeded;
}

void PictureResizer::setFolder(string _folderName)
{
    folderName = _folderName;
}

void PictureResizer::resizePicture(string namePicture)
{
    string newPictureName = namePicture + PICTURE_SIZE;
    Magick::Image picture(namePicture);
    Magick::Image result = picture;
    
    result.resize(PICTURE_SIZE);
    result.write(newPictureName);
    
}

void PictureResizer::resizePictures()
{
    for(std::vector<string>::iterator it = toBeResized.begin(); it != toBeResized.end(); ++it) resizePicture(folderName + *it);
}