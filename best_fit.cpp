int best_fit(list <hole> &memory, int * sizelist, string * namelist, int NumberOFSegments, char ProcessNumber)
{

	list<hole> copyMemory;
	list<hole>::iterator myit;


	/*Parse The holes*/
	for (myit = memory.begin(); myit != memory.end(); myit++)
	{

		if ((*myit).get_flag() == 0)
			copyMemory.push_back(*myit);

	}


	/*Sort the parsed holes*/
	copyMemory.sort(hole_size);



	/*Allocate the proper segments*/
	for (int i = 0; i<NumberOFSegments; i++)
	{

		int allocated_flag = 0;
		int current_endAddress, current_id;
		string hole_name;

		for (myit = copyMemory.begin(); myit != copyMemory.end(); myit++)
		{

			if ((sizelist[i] <= (*myit).get_size()) && (*myit).get_flag() == 0)
			{

				allocated_flag = 1;

				/*Now we can allocate*/
				/*********************/


				/*Set the allocate flag for the hole*/
				(*myit).set_flag(1);


				/*Save the current end address and the ID of the hole*/
				current_endAddress = (*myit).get_endAdress();
				current_id = (*myit).get_ID();


				/*Modify the end address*/
				(*myit).set_endAdress(((*myit).get_StartingAddress()) + sizelist[i]);

				/*Modify the hole name*/
				/*this is the new format also I called jilil to convert it to char*/
				hole_name = ProcessNumber + ":" + namelist[i];
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

					//pushing the new hole in the copyMemory list
					copyMemory.push_back(new_one);
				}

				/*make all changes in copyMemoey to real memory*/
				/* m4 mt5yl hn3mlo 2zay ya samir*/
				

			}


		}


		/*We cannot allocate any hole for this segment , Terminate the function*/
		if (allocated_flag == 0) return -1;


	}

	/* return 1 if all works well*/
	return 1;
}


