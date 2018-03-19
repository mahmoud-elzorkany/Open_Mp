// Matrix Multiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>  
#include <stdio.h>  
#include <stdlib.h>  



int main(int argc, char* argv[])
{

	/*assigning the size of the square matrices from the command line arguments*/
	int size = atoi(argv[1]);

	int i = 0;
	int j = 0;
	int k = 0;

	/*creating and the n*n matrices using dynamic memory allocation*/
	int **m1 = (int **)malloc(size*sizeof(int));
	int **m2 = (int **)malloc(size*sizeof(int));
	int **m3 = (int **)malloc(size*sizeof(int));

	
	omp_set_num_threads(4); /*setting the number of threads*/

#pragma omp parallel shared(m1,m2,m3) private(i)
	{
#pragma omp for schedule (dynamic)
		for (i = 0; i < size; i++)
		{
			m1[i] = (int*)malloc(size*sizeof(int));
			m2[i] = (int*)malloc(size*sizeof(int));
			m3[i] = (int*)malloc(size*sizeof(int));
		}/*for*/
	}/*pragma*/
	


	/*filling the matrices randomly*/
	/*setting the seed for the random generator*/
	srand(time(0));
	#pragma omp parallel shared(m1,m2,m3) private(i,j)
	{
#pragma omp for schedule (dynamic)
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				m1[i][j] = rand()%100;
				m2[i][j] = rand()%100;
			}/*for*/

		}/*for*/

	}/*pragma*/

/*The multiplication procedure*/
#pragma omp parallel shared(m1,m2,m3) private(i,j,k)
	{
#pragma omp for schedule (dynamic)
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				m3[i][j]=0;

				for(k=0;k<size;k++)
				{
					m3[i][j]+=m1[i][k]*m2[k][j];
				}/*for*/
			}/*for*/
		}/*for*/
	}/*pragma*/


/*printing the array "m3" which holds the results of m1*m2*/
	for(i=0;i<size;i++)
	{
		printf("%d \t",m3[i][0]);

		for(j=1;j<size;j++)
		{
			printf("%d \t",m3[i][j]);
		}/*for*/
		printf("\n");
	}/*for*/

	return 0;
}/*for*/

