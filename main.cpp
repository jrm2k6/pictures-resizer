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
    cout << "Enter the folder containing the pictures to resize: (relatively to your current working directory)" << endl;
    cout << "DO NOT FORGET THE TRAILING /" << endl;
}

void showPromptCreateNewFolder()
{
    cout << "Put resized pictures in new directory? yes/no?" << endl;
}

bool needNewDirectory(string newDirectory, Utils utils)
{
    string positive = "yes";

    return positive.compare(utils.toLowerCase(newDirectory)) == 0;
}

int main(int argc, char** argv) {
        InitializeMagick(*argv);
        Utils* utils = new Utils();

        char nameFolder[1024], newDirectory[1024];
        bool createNewDirectory;

        showPromptOriginFolder();
        
        cin >> nameFolder;
        
        showPromptCreateNewFolder();
        
        cin >> newDirectory;

        createNewDirectory = needNewDirectory(newDirectory, *utils);

        PictureFileRetriever* pfr = new PictureFileRetriever();

        string name =  utils->getCurrentWorkingDirectory();

        pfr->getContentFolder(nameFolder);
        pfr->printContentFolder();

        vector<string> pictures = pfr->getPicturesFromContent();

        PictureResizer* pr = new PictureResizer(pictures, createNewDirectory);
        pr->setFolder(nameFolder);
        pr->resizePictures();

        return 0;
}

