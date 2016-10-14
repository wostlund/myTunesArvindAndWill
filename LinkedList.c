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
	printf("%s by %s, ", start->name, start->artist);
	printlistH(start->next);
}

void printlist(struct node* start)
{
	printf("[ ");
	printlistH(start);
	printf("\n");
}

struct node* findSong(char* song, struct node* now){
  struct node* k = now;
  while(k){
    if(strcmp(now->name, song) == 0){
      return now;
    }
    k = k->next;
  }
  return NULL;
}

struct node* findArtistSong(char* art, struct node* now){
  struct node* k = now;
  while(k){
    if(strcmp(k->artist, art) == 0){
      return now;
    }
    k = k->next;
  }
  return NULL;
}

struct node* findRandom(struct node* now){
  int r = rand() % 1000;
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

struct node* insertFront(struct node* startI, char *a, char *n)
{
	struct node *newStart = (struct node*) malloc(sizeof(struct node));
	strcpy(newStart->artist, a);
	strcpy(newStart->name, n);
	return newStart;
}

void insetOrder(struct node* start, char *a, char *n){
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

void insertOrderH(struct node* last, struct node* new, struct node* k){
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
    free(start);
    return NULL;
  }
  while(start->next){
    if(start->next == remove){
      start->next = remove->next;
      free(remove);
    }
    start = start->next;
  }
}

int main () {

  /*struct node *start = (struct node*) malloc(sizeof(struct node));
	start->i = 10;
	start->next = NULL;

	printf("===========================printlist and insertFront test===========================\n");
	printlist(start);

	start = insertFront(start, 20);
	printf("inserted 20:\n");
	printlist(start);
	//printlist(start->next);
	printf("\n");

	start = insertFront(start, 30);
	printf("inserted 30:\n");
	printlist(start);
	//printlist(start->next);
	//printlist(start->next->next);
	//printlist(start->next->next->next);
	printf("\n");

	printf("===========================freeList test===========================\n");
	start = freeList(start);
	printf("start freed:\n");
	printlist(start);*/
}
