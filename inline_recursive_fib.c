#include <stdio.h> 
#include <sys/time.h> 
int inline Fib(int n) {
 	if (n==0)
 		return 0;
 	else if (n==1)
 		return 1;
 	else 		
		return (Fibonacci(n-1) + Fibonacci(n-2)); 
} 

int main(){
	Fib(1);
	return 0;
}
