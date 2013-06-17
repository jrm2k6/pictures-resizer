pictures-resizer
================

Without a makefile : g++ main.cpp PictureResizer.cpp PictureFileRetriever.cpp Utils.cpp -o picture-resizer -L/opt/ImageMagick/lib -I/opt/ImageMagick/include/ImageMagick-6/ -lMagick++-6.Q16 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0
