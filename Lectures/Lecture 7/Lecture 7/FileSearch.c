#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//			 File pointer	 Move steps	 Where to start
	void fseek(FILE * FileNameP, long offset, int origin);

	/*	ORIGIN OPTIONS
	SEEK_SET - From the start of the file (Also can be just 0) ->
	SEEK_CUR - From the last position in the file (Also can be 1) <- ->
	SEEK_END - From the end of the file (alse can be 2) <-
	*/
	
	// EOF (-1) end of file

}	
