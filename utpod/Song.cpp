#include "Song.h"
using namespace std;

#include <string>


Song::Song()
{
    title = "";
    artist = "";
    size = 0;
}

Song::Song(string a, string t, int s)
{
    title = t;
    artist = a;
    size = s;
}

void Song::setTitle(string t)
{
    title = t;
}

void Song::setArtist(string a)
{
    artist = a;
}

void Song::setSize(int s)
{
    size = s;
}

string Song::getTitle() const
{
    return title;
}

string Song::getArtist() const
{
    return artist;
}

int Song::getSize() const
{
    return size;
}

bool Song::operator >(const Song &rhs)
{
    if(artist==rhs.artist){
        if(title==rhs.title){
            if(size==rhs.size){
                return 0;
            }
            else{
                return (size>rhs.size);
            }
        }
        else{
            return (title>rhs.title);
        }
    }
    else{
        return (artist>rhs.artist);
    }
}

bool Song::operator <(const Song &rhs)
{
    if(artist==rhs.artist){
        if(title==rhs.title){
            if(size==rhs.size){
                return 0;
            }
            else{
                return (size<rhs.size);
            }
        }
        else{
            return (title<rhs.title);
        }
    }
    else{
        return (artist<rhs.artist);
    }
}

bool Song::operator ==(const Song &rhs)
{
    return((artist==rhs.artist)&&(title==rhs.title)&&(size==rhs.size));
}

void Song::swap(Song &rhs){
    Song temp = rhs;
    rhs=*this;
    *this=temp;
}

Song::~Song()
{
}