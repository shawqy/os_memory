
int first_fit(list <hole> &memory, int * sizelist, string * namelist,int NumberOFSgemnts,int ProcessNumber);
//sizelist is a dynamic array of segments sizes of . its size equal to NumberOFSgemnts
// namelist is a dynamic array of segments names 
//use them as a normal arrays
int best_fit(list <hole> &memory, int * sizelist, string * namelist, int ProcessNumber);
int worest_fit(list <hole> &memory, int * sizelist, string * namelist, int ProcessNumber);