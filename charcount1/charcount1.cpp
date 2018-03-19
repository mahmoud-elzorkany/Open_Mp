// charcount1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <omp.h>  
#include <stdio.h>  
#include <stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{

	
	char *words = argv[1];	/*the input string*/
	const char *letters = "abcdefghijklmnopqrstuvwxyz"; /*alphabet letters*/
	const char *vowels="aeiou";/*vowels*/
	int recurence[26]; /*array to store the recurrence of each letter*/
	
	int nb_vowels = 0;
	int nb_cons = 0;
	int total=0;

	int i=0;
	int j=0;
	int k=0;

	char letter='a';

	/*initialize the recurrence array*/
#pragma omp parallel  for shared(recurence) private(i)
	
	for(i=0;i<26;i++)
	{
		recurence[i]=0;
	}
	/*pragma*/

	/*calculating the ocuurence of each letter and the total number of letters*/
	#pragma omp parallel for shared(recurence) private(i,j,letter) reduction(+:total)
	
	for ( i = 0; i < strlen(words); i++)
	{
		letter=words[i];
		total++;

		for( j=0;j<26;j++)
		{
			if(letter==letters[j])
				recurence[j]++;
				

		}/*for*/
	}/*for*/
		/*pragma*/

	/*calculating the number of vowels*/
	#pragma omp parallel for shared (recurence) private(i) reduction(+:nb_vowels)
	
	for ( i = 0 ; i < strlen(vowels) ; i++)
	{
		int code = vowels[i];
		nb_vowels += recurence[code % 97];
	}/*for*/
	/*pragma*/

	/*calculating the number of consonants*/
	nb_cons=total-nb_vowels;


	/*output*/
	for( k=0;k<26;k++)
	{
		printf("the letter %c occured %d times",letters[k],recurence[k]);
		printf("\n");
	}

	printf("the total number of vowels is %d \n",nb_vowels);
	printf("the total number of cons is %d \n",nb_cons);
	printf ("the total number of words is %d \n",total);


	return 0;
}
