#include <stdio.h>

/* Sums all multiples of 3 */ 
int sumOne (int x, int num) 
{
	int sumNum = 0;
	int count = 1;
	while (num * count < x)
	{
		sumNum += count * num;
		count++;
	}
	return sumNum; 
}

/* Sums all multiples of 5 */ 
int sumTwo (int x, int num) 
{
	int sumNum = 0;
	int count = 1;
	while (num * count < x)
	{
		sumNum += count * num;
		count++;
	}
	return sumNum; 
}

/* Sums all multiples of 15 */ 
int sumOneTwo (int x, int num1, int num2) 
{
	int sum = 0;
	int count = 1;
	while (num1 * num2 * count < x)
	{
		sum += count * num1 * num2;
		count++;
	}
	return sum; 
}

/* Sums multiples of 3 and 5 under 1000 */
int main (int argn, char** argv) 
{
	// printf("%d", sum3s(16));
	// printf(" ");
	// printf("%d", sum5s(16));
	// printf(" ");
	// printf("%d", sum15s(16));
	// printf(" ");
	int numTo = atoi(argv[1]);
	int numOne = atoi(argv[2]);
	int numTwo = atoi(argv[3]);
	int sum = sumOne(numTo, numOne) + sumTwo(numTo, numTwo) - sumOneTwo(numTo, numOne, numTwo);
	printf("%d", sum);
}
