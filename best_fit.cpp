/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include "hole.h"

using namespace std;
int best_fit(list <hole> &memory, int * sizelist, string * namelist, int ProcessNumber);

bool hole_size(hole,hole);



int main()
{

 list<hole> memory;
 
 hole h1,h2,h3,h4,h5;
 string x="SS";
 int y=3;
 
 
 h1.set_ID(1);
 h1.set_StartingAddress(100);
 h1.set_endAdress(150);
 h1.set_name("hole1");
 h1.set_flag(0);


 h2.set_ID(2);
 h2.set_StartingAddress(200);
 h2.set_endAdress(225);
 h2.set_name("hole2");
 h2.set_flag(0);


 h3.set_ID(3);
 h3.set_StartingAddress(300);
 h3.set_endAdress(400);
 h3.set_name("hole3");
 h3.set_flag(1);



 h4.set_ID(4);
 h4.set_StartingAddress(400);
 h4.set_endAdress(800);
 h4.set_name("hole4");
 h4.set_flag(0);


 h5.set_ID(5);
 h5.set_StartingAddress(300);
 h5.set_endAdress(400);
 h5.set_name("hole5");
 h5.set_flag(1);

memory.push_back(h1);

memory.push_back(h2);

memory.push_back(h3);

memory.push_back(h4);

memory.push_back(h5);

//best_fit(memory,&y,&x,2);


    return 0;
}


int best_fit(list <hole> &memory, int * sizelist, string * namelist,int NumberOFSegments,int ProcessNumber)
{
    
    list<hole> copyMemory;
    list<hole>::iterator myit;
    list<hole>::iterator myitMemory;
    

/*Parse The holes*/    
    for(myit=memory.begin();myit!=memory.end();myit++)
    {
        
        if((*myit).get_flag()==0)
                copyMemory.push_back(*myit);
        
    }


/*Sort the parsed holes*/
copyMemory.sort(hole_size);



/*Allocate the proper segments*/
for(int i=0;i<NumberOFSegments;i++)
{
    
    int allocated_flag=0,insert_flag=0;
    int current_endAddress,current_id;
    string hole_name;
    
    for(myit=copyMemory.begin();myit!=copyMemory.end();myit++)
    {
        
        if( (sizelist[i]<= (*myit).get_size()) && (*myit).get_flag()==0 )
        {
            
            allocated_flag=1;
            
            /*Now we can allocate*/
            /*********************/
            
            
            /*Set the allocate flag for the hole with the ProcessNumber*/
            (*myit).set_flag(ProcessNumber);
            
            
            /*Save the current end address and the ID of the hole*/
            current_endAddress = (*myit).get_endAdress();
            current_id=(*myit).get_ID();
            
            
            /*Modify the end address*/
            (*myit).set_endAdress( ((*myit).get_StartingAddress())+ sizelist[i] );
            
            /*Modify the hole name*/
            hole_name="P"+namelist[i]; //NOTE::::::
            (*myit).set_name(hole_name);
            
            
            
            
            /*Now we insert in the Copy memory New hole*/
            //create a new hole if the currently end address of segment != current_endAddress
				if ( (*myit).get_endAdress() != current_endAddress)
				{
					//create new hole
					hole new_one;

					//set its id
					new_one.set_ID(current_id);

					//set its flag to 0 'means it is free'
					new_one.set_flag(0);

					//set start & end addresses
					new_one.set_StartingAddress( (*myit).get_endAdress() );
					new_one.set_endAdress(current_endAddress);

					//Insert the new hole after the current hole with the new specs
				
					advance(myit,1); // Add the new hole after this current hole
					copyMemory.insert(myit,new_one); // insert the new hole
					myit--; // decrement the iterator to point to the new hole next iteration
					
					
				}

            
            
            /*We don't need to keep searching we already found a proper hole*/
                    break;
        }
        
        
        
        
    }
    
    
    /*We cannot allocate any hole for this segment , Terminate the function*/
    if(allocated_flag==0) return -1;
    
}



        /*Copy the state of the copyMemory to the RealMemory*/
        for(myit=copyMemory.begin();myit!=copyMemory.end();myit++)
        {
    
    insert_flag=0;
    
            
            for(myitMemory=memory.begin();myitMemory!=memory.end();myitMemory++)
            {
                
                
                
                //loop till you find the hole with the same starting address
                if(myit->get_StartingAddress() == myitMemory->get_StartingAddress())
                {
                    
                    //Copy the info from the hole to the memory even if it is not adjusted
                    myitMemory->set_ID(myit->get_ID());
                    myitMemory->set_name(myit->get_name());
                    myitMemory->set_flag(myit->get_flag());
                    

                if(myit->get_endAdress() != myitMemory->get_endAdress() )
                    {
                        insert_flag=1;
                    }
                    
                    

                    myitMemory->set_endAdress(myit->get_endAdress());




                if(flag==1)
                {
                    
                    myitMemory++;
                    myit++;
                    
                 memory.insert(myitMemory,(*myit));

                }
                    
                    
                    
                    
                    //we find the hole no need to continue for this hole
                    break;
                }
                
                
                
            }
    
            
            
        }
    
        /********/


    /*Allocation Succeeded*/
        return 1;


}





bool hole_size(hole h1, hole h2)
{
	return ( (h1.get_endAdress() - h1.get_StartingAddress()) < (h2.get_endAdress() - h2.get_StartingAddress() ) );
}
