#include <iostream>
#include <list>
#include <iterator>
#include "hole.h"

#include function protoype.cpp

int first_fit(list <hole> &memory, int * sizelist, string * namelist,int NumberOFSgemnts,int ProcessNumber){

    list <hole> copy;

    int i = 0;

    copy = memory;
for(i ; i < NumberOFSgemnts; i++){
    int count = 0;
    for (list<hole>::iterator it = copy.begin();it != copy.end();it++){

        if(it->get_flag() == 0 &&
         (it->get_endAdress() - it->get_StartingAddress()) >= sizelist[i]){

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

            list<hole>::iterator it2 = copy.begin() //define a new iterator to insert a hole
            count++;
            advance(it2,count);
            copy.insert(it2,h);
            break; 
        }
    }
    if(it == copy.end())
        break;
}   
    //if it loops over all the segments it mean they were successfully fitted
    if(i == NumberOFSgemnts)
        return 1;

    else
        return -1;
    

