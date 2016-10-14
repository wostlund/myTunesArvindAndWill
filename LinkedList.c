#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

song_node* insertFront(song_node start, char* song, char* artist)
{
	song_node* newStart = (song_node*) malloc(sizeof(song_node));
	newStart->name = song;
	newStart->artist = artist;
	newStart->next = start;
	return newStart;
}

int main ()
{

}