#include<stdio.h>
long long int const MAX = 2000000;

int checkPrime(long long int n){
    long long int range = n;
    long long int i=2;
    for (i = 2; i< range; i++){
        if (n%i == 0){
            return 0;
        }
        range = n / i;
    }
    return 1;
}

unsigned long long int solution(){
    unsigned long long int sum = 0;
    long long int i=2;
    for (i = 2; i < MAX; i++){
        if (checkPrime(i) == 1){
            sum += i;
        }
    }
    return sum;
}

int main(void){
	printf("Sum of primes upto 2 million is %lld",solution());
}
