
#ifndef PICTUREFILERESIZER_H
#define	PICTUREFILERESIZER_H

#include <Magick++.h>
#include <string>
#include <vector>

using namespace std;
using namespace Magick;

class PictureResizer
{
        static string PICTURE_SIZE;
        
        private:
            vector<string> toBeResized;
            vector<string> resizedPictures;
            string folderName;
            bool newDirectoryNeeded;
        public:
            PictureResizer(vector<string> _toBeResized, bool newDirectoryNeeded);
            void setFolder(string _folderName);
            void resizePicture(string namePicture);
            void resizePictures();
};


#endif	/* PICTUREFILERESIZER_H */

