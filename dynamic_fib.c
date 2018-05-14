#include <stdio.h>
static int Fib(int n)
{
	if(n==0) return 0; 
	if(n==1) return 1;
	int prevPrev = 0;
 	int prev = 1;
 	int result = 0;
 	int i;
 	for(i = 2; i <= n; i++){
 		result = prev + prevPrev;
 		prevPrev = prev; 
		prev = result;
 	} 	
	return result;
 } 

int main() { 
	FibonacciIterative(1);
	return 0; 
}

