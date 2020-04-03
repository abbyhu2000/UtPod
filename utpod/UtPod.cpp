#include "UtPod.h"
#include <ctime>
#include <cstdlib>

using namespace std;

UtPod::UtPod()
{
    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size)
{
    songs = NULL;
    if((size>MAX_MEMORY)||(size<=0)){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
}

int UtPod::getRemainingMemory()
{
    int total = 0;
    SongNode* pointer = songs;
    while(pointer!=NULL){
        total = total + pointer->s.getSize();
        pointer = pointer->next;
    }
    return memSize-total;
}

int UtPod::addSong(const Song &s)
{
    int remain = getRemainingMemory();
    if(s.getSize()>remain){
        return NO_MEMORY;
    }
    else{
        SongNode *newSong = new SongNode; //new and delete function are for struct, subs malloc and free
        newSong->s = s;
        SongNode* pointer = songs;
        songs = newSong;
        newSong->next = pointer;
        return SUCCESS;
    }
}

int UtPod::removeSong(Song const &s)
{
    SongNode* pointer = songs;
    SongNode* previous = songs;

    //if the list is empty
    if(songs==NULL){
        return NOT_FOUND;
    }
    //if deleting the first node

    else if(songs->s==s){
        songs=songs->next;
        delete(pointer);
        return SUCCESS;
    }
    else {
        //delete a song in the middle of the list
        while (pointer != NULL) {
            if (pointer->s == s) {
                previous->next=pointer->next;
                delete(pointer);
                return SUCCESS;
            }
            previous = pointer;
            pointer = pointer->next;
        }
        //the song is not in the list
        previous = NULL;
        return NOT_FOUND;
    }
}

void UtPod::showSongList()
{
    SongNode* pointer = songs;
    while(pointer != NULL){
        cout<<pointer->s.getTitle()<<", "<<pointer->s.getArtist()<<", "<<pointer->s.getSize()<<endl;
        pointer=pointer->next;
    }
}

void UtPod::clearMemory()
{
    while(songs!=NULL){
        SongNode* pointer = songs;
        songs=songs->next;
        delete(pointer);
    }
}

void UtPod::shuffle() {
    if (songs!=NULL) {
        int totalNum = 0;
        SongNode *counter = songs;
        while (counter != NULL) {
            totalNum++;
            counter = counter->next;
        }
        unsigned int currentTime = (unsigned) time(0);
        srand(currentTime);
        for (int i = 0; i < 100; i++) {
            SongNode *pointer1 = songs;
            SongNode *pointer2 = songs;
            long die1 = (rand() % totalNum);
            long die2 = (rand() % totalNum);
            while (die1 != 0) {
                pointer1 = pointer1->next;
                die1--;
            }
            while (die2 != 0) {
                pointer2 = pointer2->next;
                die2--;
            }
            pointer1->s.swap(pointer2->s);
        }
    }
}
void UtPod::sortSongList() {
    if (songs != NULL) {
        SongNode *smallest = songs;
        while (smallest->next != NULL) {
            SongNode *pointer = smallest->next;
            while (pointer != NULL) {
                if (smallest->s > pointer->s) {
                    smallest->s.swap(pointer->s);
                }
                pointer = pointer->next;
            }
            smallest = smallest->next;
        }
    }
}

UtPod::~UtPod()
{
    clearMemory();
}