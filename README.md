
Exercise 1: Hello world
Write a code where every thread prints Hello World in parallel on the screen. Each thread
should also print its reference number (id) in the pool of threads. One of these threads should
also print the total number of threads that are working in parallel.


Exercise 2: Matrix Multiplication
Write a code implementing the multiplication, in parallel, of two squared integer matrices of size
n*n. The value of n is supposed to be given to your program through an input argument, and
the real matrices should be randomly generated.


Exercise 3: Eratosthene's Sieve
Eratosthene's Sieve is a general and simple method for the identification of prime numbers.
Consider an array of Boolean variables bi (for instance by using the stdbool library), where
bi = true marks i as prime, while bi = false marks it as non-prime. Starting from an array
where every element is true, Eratosthene's Sieve's main idea is to iteratively mark as non-prime
all multiples of each prime, starting with the multiples of 2. Recall that no number can have as
a divisor a number greater than its square root.
Write a parallel code implementing Eratosthene's Sieve for computing the first prime numbers
up to N. 

Exercise 4: Char count
Write a parallel code for counting the total number of characters in a table of words. Your code
should implement the three following steps:
1. compute the recurrence of each letter in the text;
2. compute the number of vowels and consonants from the result of step 1;
3. compute the total number of letters.