/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {
    //test the functions inside the Song class
    cout << "Test the Song class\n";
    cout << endl;

    Song e("Beatles", "Bohemian Rhapsody", 25);
    Song f();

    cout << "Test the set/get functions in the Song class\n";

    e.setTitle("Under Pressure");
    cout << "title is " << e.getTitle() << endl;

    e.setArtist("Queen");
    cout << "artist is " << e.getArtist() << endl;

    e.setSize(5);
    cout << "size is " << e.getSize() << endl;

    cout << endl;

    cout << "Test the operator == in the Song class\n";
    Song g("Queen", "Bohemian Rhapsody", 50);
    Song h("Queen", "Bohemian Rhapsody", 50);
    Song i("Queen", "Bohemian Rhapsody", 25);
    cout << "result is " << g.operator==(h) << endl;    //True
    cout << "result is " << g.operator==(i) << endl;    //False

    cout << "Test the operator > in the Song class\n";
    Song j("Queen", "Bohemian Rhapsody", 50);
    Song k("Queen", "Somebody to Love", 50);
    Song l("Queen", "Bohemian Rhapsody", 25);
    cout << "result is " << j.operator>(l) << endl;     //True
    cout << "result is " << j.operator>(k) << endl;     //False

    cout << "Test the operator < in the Song class\n";
    Song m("Queen", "Bohemian Rhapsody", 50);
    Song n("Queen", "Under Pressure", 50);
    Song o("Queen", "Bohemian Rhapsody", 25);
    cout << "result is " << m.operator<(n) << endl;     //True
    cout << "result is " << m.operator<(o) << endl;     //False

    cout << endl;

    cout << "Test the swap function in the Song class\n";
    Song p("Queen", "Under Pressure", 50);
    Song q("Queen", "Bohemian Rhapsody", 25);
    cout << "Before Swap\n";
    cout << "title is " << p.getTitle() << ", artist is " << p.getArtist() << ", size is " << p.getSize() << endl;
    cout << "title is " << q.getTitle() << ", artist is " << q.getArtist() << ", size is " << q.getSize() << endl;
    p.swap(q);
    cout << "After Swap\n";
    cout << "title is " << p.getTitle() << ", artist is " << p.getArtist() << ", size is " << p.getSize() << endl;
    cout << "title is " << q.getTitle() << ", artist is " << q.getArtist() << ", size is " << q.getSize() << endl;

    cout << endl;

    //test the default constructor
    cout << "Test the default constructor\n";
    UtPod t;
    cout << "The total memory is " << t.getTotalMemory() << endl;

    //test the second constructor
    cout << "Test the constructor with specific proper size\n";
    UtPod t1(300);
    cout << "The total memory is " << t1.getTotalMemory() << endl;

    cout << "Test the constructor with a size bigger than max_memory\n";
    UtPod t2(600);
    cout << "The total memory is " << t2.getTotalMemory() << endl;

    cout << "Test the constructor with an invalid negative size\n";
    UtPod t3(-4);
    cout << "The total memory is " << t3.getTotalMemory() << endl;

    cout << endl;

    //test extreme case
    cout << "Test every single function when the list is empty:\n "
            "(specific extreme cases for addSong and deleteSong will be tested later)\n";
    t.showSongList();
    cout << "The remaining memory is " << t.getRemainingMemory() << endl;
    cout << "The total memory is " << t.getTotalMemory() << endl;
    t.shuffle();
    t.sortSongList();
    t.clearMemory();
    t.showSongList();

    cout << endl;

    cout << "Test every single function when there is only one song in the list:\n";
    Song song("Beatles", "Hey Jude1", 4);
    int result = t1.addSong(song);
    cout << "add result = " << result << endl;
    t1.showSongList();
    cout << "The remaining memory is " << t1.getRemainingMemory() << endl;
    cout << "The total memory is " << t1.getTotalMemory() << endl;
    t1.shuffle();
    t1.sortSongList();
    t1.clearMemory();
    t1.showSongList();
    cout << "The remaining memory is " << t1.getRemainingMemory() << endl;
    cout << "The total memory is " << t1.getTotalMemory() << endl;

    cout << endl;

    //test add song functions
    cout << "Test addSong function\n";
    Song s1("Beatles", "Hey Jude1", 4);
    result = t.addSong(s1);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    //add a same song
    cout << "Add a same song to the list\n";
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    t.showSongList();

    //add a song such that it will exceed the storage space
    cout << "Add a song such that it will exceed the storage space\n";
    Song s6("Beatles", "Hey Jude6", 250);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    t.showSongList();

    cout << endl;

    cout << "Test removeSong function\n";

    cout << "Remove a duplicate song in the list, should only remove the first instance in the list\n";
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove the first song in the list\n";
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove the last song in the list\n";
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove a middle song in the list\n";
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove a song that is not in the list\n";
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove a song\n";
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove a song when there is only one song in the list\n";
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "Remove a song when there is no song in the list\n";
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();

    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    //test clearMemory

    cout << "test clear memory\n";

    t.clearMemory();

    t.showSongList();

    cout << endl;

    cout << "Add four songs to the list\n";
    result = t.addSong(s1);
    cout << "result = " << result << endl;

    result = t.addSong(s2);
    cout << "result = " << result << endl;

    result = t.addSong(s3);
    cout << "result = " << result << endl;

    result = t.addSong(s4);
    cout << "result = " << result << endl;

    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song ss1("Beatles", "Hey Jude4", 8);
    Song ss2("Queen", "Bohemian Rhapsody", 5);

    result = t.addSong(ss1);
    cout << "result = " << result << endl;

    result = t.addSong(ss2);
    cout << "result = " << result << endl;


    t.showSongList();

    cout << endl;

    cout << "Test shuffle function:\n";
    cout << "First shuffle:\n";
    t.shuffle();
    t.showSongList();

    cout << "Second shuffle:\n";
    t.shuffle();
    t.showSongList();

    cout << "Third shuffle:\n";
    t.shuffle();
    t.showSongList();

    cout << "Fourth shuffle:\n";
    t.shuffle();
    t.showSongList();

    cout << "Fifth shuffle:\n";
    t.shuffle();
    t.showSongList();

    cout << endl;

    //test sortSongLists
    cout << "Test sort song lists:\n";

    t.sortSongList();

    t.showSongList();

    cout << endl;

    // test getTotalMemory
    cout << "test get total memory\n";

    cout << "total memory = " << t.getTotalMemory() << endl;

    //test getRemainingMemory
    cout << "test get remaining memory\n";
    cout << "Remaining memory = " << t.getRemainingMemory() << endl;

    cout << endl << endl << endl;

    t.clearMemory();

    //test entire code
    cout << "More general testing on all of the functions: \n";
    cout << endl;

    cout << "Add songs\n";
    Song s20("Beatles", "Hey Jude1", 4);
    result = t.addSong(s20);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s7("Beatles", "Hey Jude1", 10);
    result = t.addSong(s7);
    cout << "result = " << result << endl;


    Song s8("Queen", "We Are the Champions", 32);
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s9("Queen", "We Will Rock You", 200);
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    t.showSongList();

    cout << endl;

    cout << "Remove songs\n";
    result = t.removeSong(s7);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s9);
    cout << "delete result = " << result << endl;

    t.showSongList();
    cout << endl;

    cout << "New Song List\n";
    Song s10("AC/DC", "Highway to Hell", 15);
    Song s11("David Bowie", "Life on Mars?", 15);
    t.addSong(s9);
    t.addSong(s10);
    t.addSong(s11);

    t.showSongList();

    cout << endl;

    cout << "Shuffle song lists\n";
    t.shuffle();
    t.showSongList();

    cout << endl;

    cout << "Sort song lists\n";
    t.sortSongList();
    t.showSongList();

    cout << endl;

    cout << "total memory = " << t.getTotalMemory() << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    cout << endl;

    cout << "Clear memory\n";
    t.clearMemory();
    t.showSongList();
    cout << "total memory = " << t.getTotalMemory() << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    // test destructor
    t.~UtPod();

}
