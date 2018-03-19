// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>  
#include <stdlib.h>  



int main (int argc, char* argv[])
{

	//thread number//
	int id=0;

	//get the number of threads from the comand line arguments//
	int nb=atoi(argv[1]);

	//creating the threads//
	omp_set_num_threads(nb);

#pragma omp parallel private(id)
	{
		id=omp_get_thread_num();

	printf("Hello World from thread %d \n",id);

	//thread 0 is responsible for printing the total number of threads//
	if(id==0)
	{
		printf("we are a group of %d threads. \n", nb);
	}
	}

	
	return 0;
}

