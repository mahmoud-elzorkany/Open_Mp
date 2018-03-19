// Eratosthene's Sieve.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <omp.h>  
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include<math.h>



int main(int argc, char* argv[])

{

	/*get the number from the command line arguments*/
	int n = atoi(argv[1]);

	/*prime number counter*/
	int counter = 0;

	/*creating an array of booleans*/
	bool *primes=(bool *) malloc(n*sizeof(bool)+1);

	/*for the loops*/
	int i = 0;
	int j = 0;

	/*initializing the boolean array with true for all elements*/
#pragma omp parallel shared(primes) private(i)
	{
#pragma omp for schedule (dynamic)
		for (i = 0; i <= n; i++)
		{
			primes[i] = true;
		}/*for*/

	}/*pragma*/



	/*eratosthene's algorithm*/
#pragma omp parallel shared(primes) private(i,j)
	{
/*#pragma omp for schedule (dynamic)*/
		for (i = 2; i*i <= n; i++)
		{
			if (primes[i] == true)
			{
				for (j = i * 2; j <= n; j += i)
				{
					primes[j] = false;

				}/*for*/
			}/*if*/
		}/*for*/
	}/*pragma*/

	/*counting the number of primes in the array*/
#pragma omp parallel shared(primes) private(i,j)

	{
#pragma omp for schedule (dynamic)
		for (i = 2; i <= n; i++)
		{
			if (primes[i] == true)
			{
		#pragma omp  critical

				counter++;
			}/*if*/
		}/*for*/
	}/*pragma*/

	printf("%d \n", counter);

	return 0;
}/*main*/

