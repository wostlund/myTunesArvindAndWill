typedef struct song_node {
	char name[256];
	char artist[256];
	struct song_node* next;
} song_node;


song_node* insertFront(song_node* start, char* song, char* artist);
song_node* insertSorted(song_node* start, char* song, char* artist);
void printlist(song_node* start);
song_node* findSong(song_node* start);
song_node* findArtistSong(song_node* start);
song_node* randomSong(song_node start);
song_node* removeNode(song_node previous, song_node removing);
song_node* freeList(song_node start);