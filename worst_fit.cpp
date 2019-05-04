#include <iostream>
#include <list>
#include <iterator>
#include "hole.h"

using namespace std;

int get_the_largest_hole_in_the_list (list <hole> &copy) {
    int largestHole = 0  ;
    int largestHole_ID ;
    for(list<hole>::iterator it = copy.begin() ; it != copy.end() ;it++)
    {
        int iteratorHole = it->get_endAdress() - it->get_StartingAddress();
        if( iteratorHole > largestHole) 
        {
            largestHole = iteratorHole ; 
            largestHole_ID = it->get_ID() ;  
        }
    }

    return largestHole_ID ;
}

int worest_fit(list <hole> &memory, int * sizelist, string * namelist, int ProcessNumber) {

    return  0 ;
}




// For Testing get_the_largest_hole_in_the_list function ()
/* 

    hole h1,h2,h3,h4 ;
    h1.set_ID(10);
    h1.set_StartingAddress(0);
    h1.set_endAdress(20);
    h2.set_ID(12);
    h2.set_StartingAddress(500);
    h2.set_endAdress(700);
    h3.set_ID(110);
    h3.set_StartingAddress(100);
    h3.set_endAdress(200);
    h4.set_ID(9);
    h4.set_StartingAddress(400);
    h4.set_endAdress(1000);

    list <hole> list1 ;
    list1.push_front(h1);
    list1.push_front(h2);
    list1.push_front(h3);
    list1.push_front(h4);

    // expecting : 9 :: hole_ID
    cout << "largest hole is " << get_the_largest_hole_in_the_list(list1) << endl;

*/