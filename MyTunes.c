#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

struct node* songs[26];

struct node* addSong(char* n, char* a)
{
	char firstChar = *n;
	songs[firstChar - 97] = insertOrder(songs[firstChar - 97], n, a);
	return songs[firstChar - 97];
}

struct node* searchSong(char* n, char* a)
{
	char firstChar = *n;
	return findSong(n, songs[firstChar - 97]);
}

struct node* searchArtist(char* artName)
{
	int i = 0;
	for(; i < 26; i++)
	{
		struct node* firstArtistSong = findArtistSong(artName, songs[i]);
		if(firstArtistSong) return firstArtistSong;
	}
	return NULL;
}

void printLetter(char letter)
{
	printlist(songs[letter - 97]);
}

void printAllSongs(char* artName)
{
	int i = 0;
	for(; i < 26; i++)
	{
		struct node* current = songs[i];
		while(current)
		{
			if(strcmp(current->artist, artName) == 0) printNode(current);
			current = current->next;
		}
	}
}

void printLibrary()
{
	int i = 0;
	for(; i < 26; i++)
	{
		printf("%c: ", 97+i);
		printlist(songs[i]);
		printf("\n");
	}
}

void shuffle(int count)
{
	for(; count; count--)
	{
		int randomLetter = rand() % 26;
		while(songs[randomLetter] == 0) randomLetter = rand() % 26;
		if(songs[randomLetter])
		{
			printNode(findRandom(songs[randomLetter], 200));
		}
	}
}

struct node* findNode(char *n, struct node* start)
{
	if(start == NULL) return start;
	if(strcmp(start->name, n) == 0) return start;
	return findNode(n, start->next);
}

struct node* deleteSong(char* n, char* a)
{
	char firstChar = *n;
	struct node* removing = findNode(n, songs[firstChar - 97]);
	songs[firstChar - 97] = removeNode(songs[firstChar - 97], removing);
	return songs[firstChar - 97];
}

void clearLibrary()
{
	int i = 0;
	for(; i < 26; i++) songs[i] = freeList(songs[i]);
}

int main () {


	return 0;
}