#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>

#include "PictureFileRetriever.h"
#include "PictureResizer.h"
#include "Utils.h"
#include <gtk/gtk.h>

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

void createAndShowUI(int _argc, char** _argv)
{
   GtkWidget *window;
   GtkWidget *button;
   GtkWidget *fixed;

   gtk_init(&_argc, &_argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window), "Picture resizer v 0.1");
   gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
   gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

   fixed = gtk_fixed_new();
   gtk_container_add(GTK_CONTAINER(window), fixed);
   button = gtk_button_new_with_label("Quit");

   gtk_fixed_put(GTK_FIXED(fixed), button, 50, 50);
   gtk_widget_set_size_request(button, 80, 35);
   
   gtk_widget_show_all(window);

   gtk_main(); 
}

int main(int argc, char** argv) 
{
        InitializeMagick(*argv);
        // Utils* utils = new Utils();

        // char nameFolder[1024], newDirectory[1024];
        // bool createNewDirectory;

        // showPromptOriginFolder();
        
        // cin >> nameFolder;
        
        // showPromptCreateNewFolder();
        
        // cin >> newDirectory;

        // createNewDirectory = needNewDirectory(newDirectory, *utils);

        // PictureFileRetriever* pfr = new PictureFileRetriever();

        // string name =  utils->getCurrentWorkingDirectory();

        // pfr->getContentFolder(nameFolder);
        // pfr->printContentFolder();

        // vector<string> pictures = pfr->getPicturesFromContent();

        // PictureResizer* pr = new PictureResizer(pictures, createNewDirectory);
        // pr->setFolder(nameFolder);
        // pr->resizePictures();

        createAndShowUI(argc, argv);

        return 0;
}

