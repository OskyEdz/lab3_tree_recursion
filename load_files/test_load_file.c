#include <stdio.h>

#include "load_file.h"

int testLoad( char* argv[] )
{
	const char* fName = argv[0];
	
	int* a = load_file(fName);

	int size = a[0];
	for ( int i = 1 ; i <= size ; i++ ) // note this loops from 1 <= i <= size
	{
		printf("%d ", a[i]);
	}
	return 0;
}
