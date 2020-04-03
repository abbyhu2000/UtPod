#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>
using namespace std;

//Song class declaration
class Song
{
private:
    string title;
    string artist;
    int size;

public:
    //constructor
    Song();
    Song(string a,string t,int s);

    //mutators

    /* FUNCTION - void setArtist
  * stores the artist inside the class
  *
  * input parms - artist that will be in the class
  *
  * output parms - none
  */
    void setArtist(string a);

    /* FUNCTION - void setTitle
   * stores the title inside the class
   *
   * input parms - title that will be stored in the class
   *
   * output parms - none
   */
    void setTitle(string t);

    /* FUNCTION - void setSize
   * stores the size inside the class
   *
   * input parms - size that will be stored in the class
   *
   * output parms - none
   */
    void setSize(int s);

    //accessors

    /* FUNCTION - string getTitle
  * returns the title inside the class
  *
  * input parms - none
  *
  * output parms - title inside the class
  */
    string getTitle() const;

    /* FUNCTION - string getArtist
  * returns the artist inside the class
  *
  * input parms - none
  *
  * output parms - artist in the class
  */
    string getArtist() const;

    /* FUNCTION - int getSize
  * returns the size inside the class
  *
  * input parms - none
  *
  * output parms - size inside the class
  */
    int getSize() const;

    //operators

    /* FUNCTION - bool operator ==
   * Returns true if songs are the same (artist, title, AND size is the same)
   * Returns false if artist, title, OR size is not the same
   * input parms - song that is going to be compared with
   *
   * output parms - True if the same, False if not the same
   */
    bool operator ==(const Song &rhs);

    /* FUNCTION - bool operator <
   * Returns true if songs artist, title or size is less than or earlier in the alphabet
   * Returns false if songs artist, title, or size is not less than or earlier in the alphabet
   * input parms - song that is going to be compared with
   *
   * output parms - True if less than, False if not less than
   */
    bool operator <(const Song &rhs);

    /* FUNCTION - bool operator >
   * Returns true if songs artist, title or size is greater than or later in the alphabet
   * Returns false if songs artist, title, or size is not greater than or later in the alphabet
   * input parms - song that is going to be compared with
   *
   * output parms - True if greater than, False if not greater than
   */
    bool operator >(const Song &rhs);

    /* FUNCTION - void swap
     * swap two songs
     *
     * input parms - none
     *
     * output parms - none, swap two songs
     */

    void swap(Song &rhs);

    //destructor
    ~Song();
};

#endif