// CSE240 SPRING 2023 Assignment 05
// Dean Prach

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 20
#define MAX_SONG_NAME_LENGTH 40
#define MAX_SINGER_NAME_LENGTH 40

typedef enum
{
    unclassified = 0,
    Pop,
    Rock,
    Reggae,
    Country,
    Blues,
    Balad,
} genreType; // enum type

struct musicRepository
{
    // struct for song details
    unsigned int ID;
    char songName[MAX_SONG_NAME_LENGTH];
    char singerName[MAX_SINGER_NAME_LENGTH];
    genreType genre;
    unsigned int year;
};

struct musicRepository list[MAX_SONGS]; // declare the list of songs
int numSongs = 0;                       // the number of songs currently stored in the list (initialized to 0)

// Given functions
void initializeRepository(struct musicRepository repo[], int size);
void printRepository(struct musicRepository repo[], int numSongs);
void flushSngIn();

// functions that need to be implemented by you
int addSong(struct musicRepository repo[], char *songName, char *singerName, char *genre, unsigned int year, int numSongs);
struct musicRepository *searchSong(struct musicRepository repo[], char *songName, int numSongs);
void printSong(struct musicRepository repo[], int ID);
int editSong(struct musicRepository *repo, int numSongs, char *songName);
int deleteSongByName(struct musicRepository *repo, char *songName, int numSongs);

// This function takes in an array of musicRepository structures and the size of the array as parameters. It then loops through each index of the array and sets the values of id, year, genre, name, and singer to their respective initial values.
// NOTE that strcpy is used to copy an empty string to name and singer, rather than setting them equal to "". This is because arrays in C are not assignable, so the strcpy function must be used to copy the empty string into the array.
void initializeRepository(struct musicRepository repo[], int size)
{
    for (int i = 0; i < size; i++)
    {
        repo[i].ID = 0;
        repo[i].year = 0;
        repo[i].genre = 0;
        strcpy(repo[i].songName, "");
        strcpy(repo[i].singerName, "");
    }
}

// This function takes in the musicRepository array and iterates through each element. If the ID of the song is not 0, it prints the details of the song.

void printRepository(struct musicRepository repo[], int numSongs)
{
    printf("\n--- Song Repository ---\n");
    for (int i = 0; i < numSongs; i++)
    {
        if (repo[i].ID != 0)
        {
            printf("ID: %d\n", repo[i].ID);
            printf("Name: %s\n", repo[i].songName);
            printf("Singer: %s\n", repo[i].singerName);
            if (repo[i].genre == 0)
                printf("Genre: unclassified\n");
            else if (repo[i].genre == 1)
                printf("Genre: Pop\n");
            else if (repo[i].genre == 2)
                printf("Genre: Rock\n");
            else if (repo[i].genre == 3)
                printf("Genre: Reggae\n");
            else if (repo[i].genre == 4)
                printf("Genre: Country\n");
            else if (repo[i].genre == 5)
                printf("Genre: Blues\n");
            else if (repo[i].genre == 6)
                printf("Genre: Balad\n");
            printf("Year: %d\n", repo[i].year);
            printf("\n");
        }
    }
}

//  This function is used to add a song into the list. You can simply add the new song to the end of list (array of structs).
//  Do not allow the song to be added to the list if it already exists in the list. You can do that by checking song names OR IDs already in the list.
//  If the song already exists then return 0 without adding it to the list. If the song does not exist in the list then add the song at the end of the list and return 1.
//  If song list is full, then do not add new song to the list and return 2.
//  The list should be case sensitive. For instance, 'Case' and 'case' should be considered two different names.
int addSong(struct musicRepository repo[], char *songName, char *singerName, char *genre, unsigned int year, int numSongs){
    int i;
    //If the song name already exists in the list, the function will return 0, and print an error statement.
    for(i = 0; i < numSongs; i++){
        if(strcmp(repo[i].songName,songName)==0){
            printf("\nThis song name already exists\n");
            return 0;
        }
    }
    //If the list is full the function will return 2 and print an error statement.
    if(numSongs == MAX_SONGS){
        printf("\nSong list is full\n");
        return 2;
    }
    //Makes the added song's ID one more than the previous ID.
    repo[numSongs].ID = numSongs+1;
    repo[numSongs].year = year;
    //This checks what the value of the string is to see if it matches any of the designated genres; if so it updates the genre variable to it
    //Otherwise if a string does not match it will be assigned the unclassified genre.
    if(strcmp(genre,"Pop") == 0){
        repo[numSongs].genre = Pop;
    }
    else if(strcmp(genre,"Rock") == 0){
        repo[numSongs].genre = Rock;
    }
    else if(strcmp(genre,"Reggae") == 0){
        repo[numSongs].genre = Reggae;
    }
    else if(strcmp(genre,"Country") == 0){
        repo[numSongs].genre = Country;
    }
    else if(strcmp(genre,"Balad") == 0){
        repo[numSongs].genre = Balad;
    }
    else if(strcmp(genre,"Blues") == 0){
        repo[numSongs].genre = Blues;
    }
    else{
        repo[numSongs].genre = unclassified;
    }
    strcpy(repo[numSongs].songName,songName);
    strcpy(repo[numSongs].singerName,singerName);
    return 1;
    
    


};

//  This function takes in the name of a song as input and search for it in the musicRepository array. It returns a pointer to the musicRepository struct that contains information about the song.
//  NOTE that the input name of the song should match the name of the song in the array exactly, including any whitespace or special characters.
struct musicRepository *searchSong(struct musicRepository repo[], char *songName, int numSongs){
    struct musicRepository *search;
    //Iterates through the list until it finds a matching string for songName and returns the pointer.
    for(int i = 0; i<numSongs;i++){
        if(strcmp(repo[i].songName,songName) == 0){
            search = &repo[i];
            break;
        }
        else{
            search = NULL;
        }
    }
    return(search);
};

//  This function takes the ID of a song as input, which represents a single song in the repository. The function then prints out the details of the song, including its ID, name, singer, genre, and year. The genre is printed as a string, based on its corresponding enum value.
void printSong(struct musicRepository repo[], int songID){
    struct musicRepository *temp = repo;
    //Prints the song depending on which ID is input. Since the ID's are one value greater than their index the ID must be subtracted 1.
    while(temp != 0){
        if(songID == temp->ID - 1){
            printf("\nID: %d\nName: %s\nSinger: %s\n",temp->ID,temp->songName,temp->singerName);
        if(temp->genre == 1){
            printf("Genre: Pop\n");
        }
        else if(temp->genre == 2){
            printf("Genre: Rock\n");
        }
        else if(temp->genre == 3){
            printf("Genre: Reggae\n");
        }
        else if(temp->genre == 4){
            printf("Genre: Country\n");
        }
        else if(temp->genre == 5){
            printf("Genre: Balad\n");
        }
        else if(temp->genre == 6){
            printf("Genre: Blues\n");
        }
        else{
            printf("Genre: unclassified\n");
        }
            printf("Year: %d",temp->year);
            printf("\n");
            break;
        }
        temp++;
    }
};

//  This function takes the name of a song as input, searches for the song, and allows the user to modify any field of the song except for the ID field. The function should prompt the user for the new values of the fields and update the corresponding fields of the song. If the song is not found, the function should return -1 to indicate failure, otherwise it should return 1 to indicate success.
int editSong(struct musicRepository *repo, int numSongs, char *songName){
    struct musicRepository *temp = searchSong(repo,songName,numSongs);
    char song_input[MAX_SONG_NAME_LENGTH], singer_input[MAX_SINGER_NAME_LENGTH];
    char genre_input[20];
    unsigned int year_input = 0;
    unsigned int add_output = 0;
    //This function will scan the inputs from the user and assign them to variables. After, if the addSong returns a 1, it will add a new song
    //in place of where the pointer the searchSong method returned.
    printf("Enter new song name: ");
    fgets(song_input, sizeof(song_input), stdin);
    song_input[strlen(song_input) - 1] = '\0';
    flushSngIn();
    printf("Enter new singer name: ");
    fgets(singer_input, sizeof(singer_input), stdin);
    singer_input[strlen(singer_input) - 1] = '\0';
    flushSngIn();
    printf("Enter new genre name: ");
    fgets(genre_input, sizeof(genre_input), stdin);
    genre_input[strlen(genre_input) - 1] = '\0';
    flushSngIn();
    printf("Enter new year released: ");
    scanf("%d",&year_input);
    flushSngIn();
    add_output = addSong(repo,song_input,singer_input,genre_input,year_input,temp->ID-1);
    if(add_output != 1){
        printf("Unable to edit song");
        return -1;
    }
    return 1;
    
};

//  This function takes the name of a song as input, searches for the song, and deletes the song by setting all its fields to default values. If the song is not found, the function should return -1 to indicate failure, otherwise it should return 1 to indicate success.
int deleteSongByName(struct musicRepository *repo, char *songName, int numSongs){
    struct musicRepository *temp = repo;
    //This function receives the location of the song it wants to delete, then it will move the list by replacing the current node and then incrementing.
    int i = (searchSong(repo,songName,numSongs)->ID - 1);
    if(temp[i].ID!=0){
    while(i < numSongs){
        temp[i] = temp[i+1];
        temp[i].ID = temp[i].ID-1;
        ++i;
    }
    return(1);
    }
    else{
    return(-1);
    }
    };


// struct to hold information about a song
struct Song
{
    int id;
    char name[MAX_SONG_NAME_LENGTH];
    char singer[MAX_SINGER_NAME_LENGTH];
    genreType genre;
    int year;
    struct Song *next;
};

// Function declarations
struct Song *createSong(int id, char *name, char *singer, char *genre, int year);
void printPlaylist(struct Song *playlist);

void add_song(struct Song **playlist, struct Song *newSong);
struct Song *search_song(struct Song *playlist, char *name);
int edit_song(struct Song *playlist, char *name, char *singer, char *genre, int year);
int delete_song(struct Song *playlist, char *name);

// function to create a new song
struct Song *createSong(int id, char *name, char *singer, char *genre, int year)
{
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    newSong->id = id;
    strcpy(newSong->name, name);
    strcpy(newSong->singer, singer);
    if (strcmp(genre, "Pop") == 0)
        newSong->genre = 1;
    else if (strcmp(genre, "Rock") == 0)
        newSong->genre = 2;
    else if (strcmp(genre, "Reggae") == 0)
        newSong->genre = 3;
    else if (strcmp(genre, "Country") == 0)
        newSong->genre = 4;
    else if (strcmp(genre, "Blues") == 0)
        newSong->genre = 5;
    else if (strcmp(genre, "Balad") == 0)
        newSong->genre = 6;
    else
        newSong->genre = 0;
    newSong->year = year;
    newSong->next = NULL;
    return newSong;
}

// function to print the playlist
void printPlaylist(struct Song *playlist)
{
    struct Song *current = playlist;
    while (current != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%d\n", current->id, current->name, current->singer, current->genre, current->year);
        current = current->next;
    }
}

// function to add a song to the end of the playlist
void add_song(struct Song **playlist, struct Song *newSong)
{
    struct Song **head = playlist;
    //This if statement initializes the linked list; if the first spot of the list is empty it will assign newSong to the null space.
    if(*head == NULL){
        *head = newSong;
        return;
    }
    //This while loops checks until the next spot is NULL and then it will allocate memory and assign that memory to the struct newSong.
    while((*head)->next != NULL){
        head = &(*head)->next;
    }
    (*head)->next = malloc(sizeof(struct Song));
    *(*head)->next = *newSong;
}


// function to search for a song by name
struct Song *search_song(struct Song *playlist, char *name)
{
    struct Song *head = playlist;
    //This will go through the entire linked list and search for the corresponding name value using the strcmp function.
    while(head->next != NULL){
        if(strcmp(head->name,name)==0){
            return(head);
        }
        head = head->next;
    }
}

// function to edit a song by name
int edit_song(struct Song *playlist, char *name, char *singer, char *genre, int year)
{
    //This function will go through the list until it finds the name of the song the user wants to edit and then it will modify the values at
    //that struct with the parameters.
    struct Song *head = playlist;
    while(head != NULL){
        if(strcmp(head->name,name)==0){
            strcpy(head->name,name);
            strcpy(head->singer,singer);
            if(genre = "Pop"){
                head->genre = Pop;
            }
            else if(genre = "Rock"){
                head->genre = Rock;
            }
            else if(genre = "Blues"){
                head->genre = Blues;
            }
            else if(genre = "Balad"){
                head->genre = Balad;
            }
            else if(genre = "Country"){
                head->genre = Country;
            }
            else if(genre = "Reggae"){
                head->genre = Reggae;
            }
            else{
                head->genre = unclassified;
            }
            head->year = year;
        }
        head = head->next;
    }
}

// function to delete a song by name
int delete_song(struct Song *playlist, char *name)
{
    struct Song *head = playlist;
    while(head != NULL){
        if(strcmp(head->name,name)==0){
            while(head->next!=NULL){
                *head = *(head)->next; 
                head = head->next;
            }
        }
        head = head->next;
    }
}

void flushSngIn()
{
    char c;
    do
        c = getchar();
    while (c != '\n' && c != EOF);
}

int main()
{
    int choice = 0;
    int songCount = 0;
    char songName_input[MAX_SONG_NAME_LENGTH], singerName_input[MAX_SINGER_NAME_LENGTH];
    char genre_input[20];
    unsigned int year_input, add_result = 0;
    struct musicRepository music[20];
    struct musicRepository *song = NULL;

    initializeRepository(music, 20); 
    music[0].ID = numSongs + 1; numSongs++;
    strcpy(music[0].songName,"Shape of You");
    strcpy(music[0].singerName,"Ed Sheeran");
    music[0].genre=1;
    music[0].year=2017;
    songCount++;

    music[1].ID = numSongs + 1; numSongs++;
    strcpy(music[1].songName,"Despacito");
    strcpy(music[1].singerName,"Luis Fonsi");
    music[1].genre=1;
    music[1].year=2017;
    songCount++;

    music[2].ID = numSongs + 1; numSongs++;
    strcpy(music[2].songName,"Uptown Funk");
    strcpy(music[2].singerName,"Mark Ronson ft. Bruno Mars");
    music[2].genre=1;
    music[2].year=2014;
    songCount++;

    printf("Number of Songs: %d", songCount);

    do
    {
        printf("\n");
        printf("1. Add a song to the repository\n");
        printf("2. Search song by name\n");
        printf("3. Print a song\n");
        printf("4. Edit a song\n");
        printf("5. Delete a song\n");
	printf("6. Print full list of songs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushSngIn();

        switch (choice)
        {
        case 1:
            printf("\nEnter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            flushSngIn();
            //printf("Song name: %s\n", songName_input);
            printf("Enter singer name: ");
            fgets(singerName_input, sizeof(singerName_input), stdin);
            singerName_input[strlen(singerName_input) - 1] = '\0';
            flushSngIn();
            printf("Enter genre ( Pop , Rock , Reggae , Country , Blues , Balad  or unclassified ):");
            fgets(genre_input, sizeof(genre_input), stdin);
            genre_input[strlen(genre_input) - 1] = '\0';
            flushSngIn();
            printf("Enter release year: ");
            scanf("%d", &year_input);
            //flushSngIn();

            add_result = addSong(music, songName_input, singerName_input, genre_input, year_input, songCount);
            if (add_result == 1)
            {
                printf("Song added successfully\n");
                songCount++;
                printf("Number of Songs: %d", songCount);
                flushSngIn();
                printRepository(music, songCount);
                break;
            }
            break;

        case 2:
            printf("Enter song name: ");
            
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            flushSngIn();
            song = searchSong(music, songName_input, songCount);
            printf("Song found: %s, %s, %d, %d", song->songName, song->singerName, song->genre, song->year);
            flushSngIn();
            break;
        case 3:
            if (songCount > 0)
            {
                int songIndex;
                printf("\nEnter the ID of the song to print (0 to %d): ", songCount - 1);
                scanf("%d", &songIndex);
                flushSngIn();
                printSong(music, songIndex);
                flushSngIn();
                break;
            }
        case 4:
            printf("Enter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            flushSngIn();
            editSong(music, songCount, songName_input);
            break;
        case 5:
            printf("Enter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            flushSngIn();
            deleteSongByName(music, songName_input, songCount);
            songCount--;
            printRepository(music, songCount);
            break;
        case 6:
	    printRepository(music, songCount);
	    break;
	case 7:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 7);

    // Problem 2
    // create some sample songs
    struct Song *s1 = createSong(1, "Shape of You", "Ed Sheeran", "Pop", 2017);
    struct Song *s2 = createSong(2, "Despacito", "Luis Fonsi", "Pop", 2017);
    struct Song *s3 = createSong(3, "Uptown Funk", "Mark Ronson ft. Bruno Mars", "Pop", 2014);

    // create the playlist and add the sample songs
    struct Song *playList = NULL;
    add_song(&playList, s1);
    add_song(&playList, s2);
    add_song(&playList, s3);

    // print the playlist
    printf("Initial Playlist:\n");
    printPlaylist(playList);

    // add a new song to the playlist
    struct Song *s4 = createSong(4, "Sorry", "Justin Bieber", "Pop", 2015);
    printf("\nAdding new song to playlist:\n");
    add_song(&playList, s4);
    printPlaylist(playList);

    // delete a song from the playlist
    printf("\nDeleting a song from the playlist:\n");
    struct Song *sToDelete = search_song(playList, "Despacito");
    if (sToDelete != NULL)
    {
        delete_song(playList, sToDelete->name);
        printf("Playlist after deletion:\n");
        printPlaylist(playList);
    }
    else
    {
        printf("Song not found in playlist.\n");
    }

    // search for a song that doesn't exist in the playlist
    printf("\nSearching for a song that doesn't exist in the playlist:\n");
    struct Song *searchResult = search_song(playList, "Non-existent Song");
    if (searchResult != NULL)
    {
        printf("Found song:\n");
        printf("Song ID: %d, Song Name: %s, Singer Name: %s, Genre: %s, Year: %d", searchResult->id, searchResult->name, searchResult->singer, searchResult->genre, searchResult->year);
    }
    else
    {
        printf("Song not found in playlist.\n");
    }

    // search for a song that exists in the playlist
    printf("\nSearching for a song that exists in the playlist:\n");
    searchResult = search_song(playList, "Uptown Funk");
    if (searchResult != NULL)
    {
        printf("Found song:\n");
        printf("Song ID: %d, Song Name: %s, Singer Name: %s, Genre: %s, Year: %d", searchResult->id, searchResult->name, searchResult->singer, "Pop", searchResult->year);
    }
    else
    {
        printf("Song not found in playlist.\n");
    }

    // edit a song in the playlist
    printf("\nEditing a song in the playlist:\n");
    int editResult = edit_song(playList, "Shape of You", "Ed Sheeran", "Pop", 2018);
    if (editResult == -1)
    {
        printf("Song not found in playlist.\n");
    }
    else
    {
        printf("Playlist after edit:\n");
        printPlaylist(playList);
    }

    return 0;
}
