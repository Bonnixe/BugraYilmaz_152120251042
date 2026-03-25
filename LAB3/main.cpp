#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;
};

void add(Song*& head, string title, string artist, int r1, int r2, int r3){
Song* newSong = new Song;
newSong->title = title;
newSong->artist = artist;
newSong->ratings[0] = r1;
newSong->ratings[1] = r2;
newSong->ratings[2] = r3;

    if(head == NULL){
        head = newSong;
        return;
    }

    Song* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newSong;
    newSong->prev = temp;
}

void showList(Song* head, Song* current){
Song* temp = head;

while(temp != NULL){
    if(temp == current){
        cout << "-> ";
    }
    cout << temp->title << " (" << temp->artist << ") | Ratings: ";
    for(int i = 0; i < 3; i++){
        cout << temp->ratings[i] << " ";
    }

    cout << endl;
    temp = temp->next;
}
}

void nextSong(Song*& current){
    if(current != NULL && current->next != NULL){
        current = current->next;
    }
}

void prevSong(Song*& current){
    if(current != NULL && current->prev != NULL){
        current = current->prev;
    }
}


int main(){
add(head, "Song1", "Artist1", 8, 9, 7);
add(head, "Song2", "Artist2", 6, 8, 9);
add(head, "Song3", "Artist3", 10, 9, 8);
current = head;
return 0;
}
