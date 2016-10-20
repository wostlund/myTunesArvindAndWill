#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <time.h>

struct node* songs[26];

void initSongs()
{
  int i;
  for(i = 0; i < 26; i++) songs[i] = NULL;
}

struct node* addSong(char* n, char* a)
{
	printf("adding %s by %s\n", n, a);
	char firstChar = *n;
	songs[firstChar - 97] = insertOrder(songs[firstChar - 97], n, a);
	return songs[firstChar - 97];
}

struct node* searchSong(char* n, char* a)
{
	printf("searching for %s by %s\n", n, a);
	char firstChar = *n;
	return findSong(n, songs[firstChar - 97]);
}

struct node* searchArtist(char* artName)
{
	printf("searching for the first song of %s\n", artName);
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
	printf("printing all songs of %s:\n", artName);
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
	printf("Library:\n");
	for(; i < 26; i++)
	{
		printf("Songs starting with '%c': ", 97+i);
		printlist(songs[i]);
	}
}

void shuffle(int count)
{
	printf("%d random songs\n", count);
	srand(time(NULL));
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

struct node* deleteSong(char* n, char* a)
{
	printf("==deleting %s by %s==\n", n, a);
	char firstChar = *n;
	struct node* removing = findNode(n, songs[firstChar - 97]);
	songs[firstChar - 97] = removeNode(songs[firstChar - 97], removing);
	printLibrary();
	return songs[firstChar - 97];
}

void clearLibrary()
{
	int i = 0;
	for(; i < 26; i++)
	{
		printf("freeing %c\n", i + 97);
		songs[i] = freeList(songs[i]);
	}
}
