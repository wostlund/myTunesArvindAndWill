#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct node {
  char name[256];
  char artist[256];
  struct node* next;
  
};
#endif

void printlistH(struct node* start);
void printlist(struct node* start);
void printNode(struct node* k);
struct node* findSong(char* song, struct node* now);
struct node* findArtistSong(char* art, struct node* now);
struct node* findRandom(struct node* now, int listLen);
struct node* insertFront(struct node* startI, char *n, char *a);
struct node* insertOrderH(struct node* start, char *n, char* a);
struct node* insertOrder(struct node* start, char *n, char* a);
struct node* findNode(char *n, struct node* start);
struct node* freeList(struct node* start);
struct node* removeNode(struct node* start, struct node* remove);



