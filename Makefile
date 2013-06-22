CC=g++
CFLAGS=-c -wall
WARNING_MAGIC_CORE_QUANTUM=-DMAGICKCORE_QUANTUM_DEPTH=16
WARNING_MAGIC_HDRI=-DMAGICKCORE_HDRI_ENABLE=0
PATH_IMAGE_MAGICK_HEADER=-I/opt/ImageMagick/include/ImageMagick-6/
PATH_LIB_IMAGE_MAGICK=-L/opt/ImageMagick/lib
PATH_IMAGE_MAGICK_DYLIB=-lMagick++-6.Q16
GTK_INCLUDE=`pkg-config --libs --cflags gtk+-2.0`

#all: 
	g++ main.cpp PictureResizer.cpp PictureFileRetriever.cpp Utils.cpp -o picture-resizer -L/opt/ImageMagick/lib -I/opt/ImageMagick/include/ImageMagick-6/ -lMagick++-6.Q16 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0  `pkg-config --libs --cflags gtk+-2.0`
all:  picture-resizer

picture-resizer: main.o PictureResizer.o PictureFileRetriever.o Utils.o
	@$(CC) main.o PictureResizer.o PictureFileRetriever.o Utils.o $(PATH_IMAGE_MAGICK_DYLIB) $(PATH_LIB_IMAGE_MAGICK) $(PATH_IMAGE_MAGICK_HEADER) $(WARNING_MAGIC_CORE_QUANTUM) $(WARNING_MAGIC_HDRI) $(GTK_INCLUDE)


main.o: main.cpp
	@$(CC) $(CFLAGS) main.cpp $(PATH_IMAGE_MAGICK_DYLIB) $(PATH_LIB_IMAGE_MAGICK) $(PATH_IMAGE_MAGICK_HEADER) $(WARNING_MAGIC_CORE_QUANTUM) $(WARNING_MAGIC_HDRI) $(GTK_INCLUDE)
       
 
PictureResizer.o: PictureResizer.cpp
	@$(CC) $(CFLAGS) PictureResizer.cpp $(PATH_IMAGE_MAGICK_DYLIB) $(PATH_LIB_IMAGE_MAGICK) $(PATH_IMAGE_MAGICK_HEADER) $(WARNING_MAGIC_CORE_QUANTUM) $(WARNING_MAGIC_HDRI) $(GTK_INCLUDE)


PictureFileRetriever.o: PictureFileRetriever.cpp
	@$(CC) $(CFLAGS) PictureFileRetriever.cpp $(PATH_IMAGE_MAGICK_DYLIB) $(PATH_LIB_IMAGE_MAGICK) $(PATH_IMAGE_MAGICK_HEADER) $(WARNING_MAGIC_CORE_QUANTUM) $(WARNING_MAGIC_HDRI) $(GTK_INCLUDE)


Utils.o: Utils.cpp
	@$(CC) $(CFLAGS) Utils.cpp $(PATH_IMAGE_MAGICK_DYLIB) $(PATH_LIB_IMAGE_MAGICK) $(PATH_IMAGE_MAGICK_HEADER) $(WARNING_MAGIC_CORE_QUANTUM) $(WARNING_MAGIC_HDRI) $(GTK_INCLUDE)

clean:
	rm -rf *o picture-resizer
