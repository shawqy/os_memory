#include <iostream>
#include <list>
#include <iterator>
#include "hole.h"

/* INPUT :: List  */
/* FN :: get the largest hole in the list  */
/* RETURN :: HOLE_ID */
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



int worest_fit(list <hole> &memory, int * sizelist, string * namelist, int ProcessNumber){
    list <hole> copy;

    int i = 0;

    copy = memory;
for(i ; i < NumberOFSgemnts; i++){
    int count = 0;
    int WorstHole;

    WorstHole = get_the_largest_hole_in_the_list (copy);
    for (list<hole>::iterator it = copy.begin();it != copy.end();it++){
       // el id equal el id
        if(it->get_id() == WorstHole){
            
            // w lazm at2kd enha fadya mfhash 7aga
            if(it->get_flag() == 0){
                //make sure en el size fit
                if((it->get_endAdress() - it->get_StartingAddress()) >= sizelist[i]){

                    int temp_endAdress = it->get_endAdress(); 
                    it->set_StartingAddress(it->get_StartingAddress());
                    it->set_endAdress(it->get_StartingAddress() + sizelist[i]);
                    it->set_flag(ProcessNumber);
                    it->set_name("P" + ProcessNumber + ":" + namelist[i]);
                    hole h;
                    //accessing a new hole and set it's attributes
                    h.set_ID(it->get_ID());
                    h.set_name("empty");
                    h.set_flag(0);
                    h.set_StartingAddress(it->get_endAdress());
                    h.set_endAdress(temp_endAdress);

                    list<hole>::iterator it2 = copy.begin(); //define a new iterator to insert a hole
                    count++;
                    advance(it2,count);
                    copy.insert(it2,h);
                    break; 
                }
                //if size not fit then this segmant can't be fitted
                else
                {
                    return -1;
                }
            }
        }
    }
    if(it == copy.end())
        break;
  }   
    //if it loops over all the segments it mean they were successfully fitted
    if(i == NumberOFSgemnts){
        memory = copy;
        return 1;
    }
    else
        return -1;
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