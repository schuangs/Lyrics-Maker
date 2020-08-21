# Lyrics_Maker

A routine for making .lrc file.

Supports:

1. g++ compiler
2. makefile support



## Compile

enter the top folder, just make:

> $make

then executable ***play*** and ***tap*** will be generated in **bin/**. ***play*** is used for displaying .lrc file. ***tap*** is used for making .lrc file.



## Make new lyrics file

1. Copy ( Or write all on yourself if u wish... ) raw lyrics lines of the song into a temporary file, named as you like.

2. Using ***tap*** program:

   > ./tap <raw lyrics file>

3. Answer some basic informations:  song name,  author, album name, your signature

4. Ready to calibrate the time of each line.  Press ENTER as soon as the start of the song, then the program will launch internal time counting and the first line of lyrics will be displayed at console. Once you press ENTER again, this first line of lyrics will be marked as at the time you press ENTER, and second line will be displayed. 

5. Continue pressing ENTER when the latest displayed line is to be sung out till the end.

6. A normative .lrc file named by the song's name is generated, which is what we want.



## Play .lrc file

1. Using ***play*** routine:

   > ./play <.lrc file> offset

   <.lrc file> is the file you want to display

   All lines of lyrics will be delayed (or advanced if it's negative) for offset milliseconds.

   If no offset is entered, there will be no delay or advance.



