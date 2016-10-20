#include "LinkedList.h"

void initSongs();
struct node* addSong(char* n, char* a);
struct node* searchSong(char* n, char* a);
struct node* searchArtist(char* artName);
void printLetter(char letter);
void printAllSongs(char* artName);
void printLibrary();
void shuffle(int count);
struct node* deleteSong(char* n, char* a);
void clearLibrary();
