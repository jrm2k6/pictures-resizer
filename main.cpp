#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>

#include "PictureFileRetriever.h"
#include "PictureResizer.h"
#include "Utils.h"

using namespace std;
using namespace Magick;

void showPromptOriginFolder()
{
    cout << "===============================" << endl;
    cout << "   Picture resizer - v 0.0.1" << endl;
    cout << "===============================" << endl;
    cout << "===============================" << endl;
    cout << "     ======================    " << endl;
    cout << "Enter the folder containing the pictures to resize: (relatively to your current working directory" << endl;
}

void showPromptCreateNewFolder()
{
    cout << "Put resized pictures in new directory? yes/no?" << endl;
}

int main(int argc, char** argv) {
        InitializeMagick(*argv);
        Utils* utils = new Utils();

        char nameFolder[1024];
        char newDirectory[1024];

        showPromptOriginFolder();
        
        cin >> nameFolder;
        
        showPromptCreateNewFolder();
        
        cin >> newDirectory;
        
        

        PictureFileRetriever* pfr = new PictureFileRetriever();

        string name =  utils->getCurrentWorkingDirectory();

        pfr->getContentFolder(nameFolder);
        pfr->printContentFolder();

        vector<string> pictures = pfr->getPicturesFromContent();

        PictureResizer* pr = new PictureResizer(pictures);
        pr->setFolder(nameFolder);
        pr->resizePictures();

        return 0;
}

