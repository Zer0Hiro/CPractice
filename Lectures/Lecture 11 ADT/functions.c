// There is 2 types of functions (SPECIFIC, GENERAL)

// SPECIFIC function - works on specific type
void name_Of_SpFunc(void* r)
{
    
    /* SHOULD USE ONLY 1 TYPE OF DATA for example (int) only
    1. Can use casting
    */
   
   // AS LESS CODE AS YOU CAN
   
   int a;
   a = *(int*)r; // Have to use casting
   
}
// MAIN FUNCTION IS ALWAYS (SPECIFIC) FUNCTION !!!

//------------------------------------------------------------//

// GENERAL function - works only with general type 
void name_Of_GenFunc(void*, void*)
{
    /* Only general info CAN'T USE:
    1. Prototypes
    2. Casting
    */

    // MOST OF THE CODE SHOULD BE INSIDE GENERAL FUNC


    // CAN CALL ANOTHER GENERAL FUNCTION
    
}

