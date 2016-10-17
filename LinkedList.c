#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

  char name[256];
  char artist[256];
  struct node* next;
  
};

void printlistH(struct node* start)
{
	if(start == NULL)
	{
		printf("]");
		return;
	}
	printf("%s by %s", start->name, start->artist);
  if(start->next) printf(",");
  printf(" ");

	printlistH(start->next);
}

void printlist(struct node* start)
{
	printf("[ ");
	printlistH(start);
	printf("\n");
}

void printNode(struct node* k)
{
  printf("====#%s by %s\n", k->name, k->artist);
}

struct node* findSong(char* song, struct node* now){
  struct node* k = now;
  while(k){
    //printNode(k);
    if(strcmp(k->name, song) == 0){
      return k;
    }
    k = k->next;
  }
  return NULL;
}

struct node* findArtistSong(char* art, struct node* now){
  struct node* k = now;
  while(k){
    if(strcmp(k->artist, art) == 0){
      return k;
    }
    k = k->next;
  }
  return NULL;
}

struct node* findRandom(struct node* now, int listLen){
  int r = rand() % listLen;
  struct node* k = now;
  while(r){
    if(k == NULL){
      k = now;
    }else{
      k = k->next;
    }
    r--;
  }
  if(k == NULL){
    return now;
  }
  return k;
}

struct node* insertFront(struct node* startI, char *n, char *a)
{
	struct node *newStart = (struct node*) malloc(sizeof(struct node));
  strcpy(newStart->name, n);
	strcpy(newStart->artist, a);
  newStart->next = startI;
	return newStart;
}

/////////////////insert order/////////////////
/*
old version
void insertOrderOldVersion(struct node* start, char *a, char *n){
  int i;
  for(i = 0; i < strlen(n); i++){
    if(*(n+i) > 64 && *(n+i) < 91){
      n+=32;
    }
  }
  struct node *new = (struct node*)calloc(1,sizeof(struct node));
  insertFront(new, a, n);
  if(strcmp(a, start->name) < 0){
    insertOrderH(NULL, new, start);
  }
}


void insertOrderHOldVersion(struct node* last, struct node* new, struct node* k){
  if(strcmp(new->name, k->name) > 0){
    return;
  }
  if(last != NULL){
    last->next = k;
  }
  struct node *j = k->next;
  k->next = new;
  insertOrderH(k, new, j);
}
*/

//returns node at head of linked list
struct node* insertOrderH(struct node* start, char *n, char* a)
{
    if(start == NULL || strcmp(n, start->name) < 0) //base case: n comes alphabetically before the song at start
    {
        start = insertFront(start, n, a);
        return start;
    }
    start->next = insertOrderH(start->next, n, a); //n has to go after the song at start
    return start;
}

struct node* insertOrder(struct node* start, char *n, char* a)
{
    int i;
    for(i = 0; i < strlen(n); i++){
      if(*(n+i) > 64 && *(n+i) < 91){
        n+=32;
     }
    }

    start = insertOrderH(start, n, a);
    return start;
}

//////////////////////////////////////////////

struct node* freeList(struct node* start)
{
	if(start->next == NULL)
	{
		free(start);
		return NULL;
	}
	freeList(start->next);
	free(start);
	return NULL;
}

struct node* removeNode(struct node* start, struct node* remove){
  struct node* now = start;
  if(start == remove){
    struct node* ans = start->next;
    free(start);
    return ans;
  }
  struct node* originalStart = start;
  while(start->next){
    if(start->next == remove){
      start->next = remove->next;
      free(remove);
    }
    start = start->next;
  }
  return originalStart;
}

int testLinkedList () {

    printf("================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================\n");
    printf("============================Insert Order Test============================\n");

    struct node* start = insertFront(NULL, "song", "Arvind M");
    start = insertOrder(start, "song2", "Arvind M2");
    start = insertOrder(start, "sang", "WOSTLUND3");
    start = insertOrder(start, "wijrijrw", "ieijirje");
    start = insertOrder(start, "abcde", "jrngjenrg"); //specialcase
    printf("after inserting the songs \"song\", \"song2\", \"sang\", \"wijrijrw\", and \"abcde\":\n");
    printlist(start);
    printf("\n\n");

    printf("============================Find Song Test============================\n");
    //this test will search for a song and print the entire linked list starting at that song
    printf("original list: ");
    printlist(start);
    printf("\n");

    char* songs[7] = {"song", "song2", "sang", "wijrijrw", "abcde", "out1", "out2"};
    int c = 0;
    for(; c < 7; c++)
    {
      printf("searching for %s: \n", songs[c]);
      printlist(findSong(songs[c], start));
      printf("\n");
    }
    printf("\n\n");

    printf("============================Find Artist Song Test============================\n");
    //this test will search for a song and print the entire linked list starting at that song
    printf("inserting more songs:\n");
    start = insertOrder(start, "song3", "Arvind M");
    start = insertOrder(start, "ff", "Arvind M");
    start = insertOrder(start, "ee", "Arvind M");
    start = insertOrder(start, "dd", "WOSTLUND3");
    start = insertOrder(start, "cc", "WOSTLUND3");
    printf("new List: ");
    printlist(start);
    printf("\n");

    printf("first song of Arvind M2: \n");
    printlist(findArtistSong("Arvind M2", start));
    printf("first song of Arvind M: \n");
    printlist(findArtistSong("Arvind M", start));
    printf("first song of WOSTLUND3: \n");
    printlist(findArtistSong("WOSTLUND3", start));
    printf("first song of WOSTLUND: \n");
    printlist(findArtistSong("WOSTLUND", start));
    printf("\n\n");

    printf("============================Random Song Test============================\n");
    printf("list: ");
    printlist(start);

    c = 0;
    for(; c < 10; c++)
    {
      printf("random song: ");
      printNode(findRandom(start, 10));
      printf("state of list: ");
      printlist(start);
      printf("\n");
    }

    printf("============================Remove Node Test============================\n");
    struct node* removing = start->next->next->next;
    printf("removing the node: ");
    printNode(removing);
    start = removeNode(start, removing);
    printlist(start);

    removing = start;
    printf("removing the node: ");
    printNode(removing);
    start = removeNode(start, removing);
    printlist(start);

    removing = start;
    printf("removing the node: ");
    printNode(removing);
    start = removeNode(start, removing);
    printlist(start);

    removing = start->next->next;
    printf("removing the node: ");
    printNode(removing);
    start = removeNode(start, removing);
    printlist(start);


    return 0;
}
