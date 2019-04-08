int const MAX = 2000000;

int checkPrime(int n){
    int range = n;
    for (int i = 2; i < range; i++){
        if (n%i == 0){
            return 0;
        }
        range = n / i;
    }
    return 1;
}

int solution(){
    double sum = 0;
    for (int i = 2; i < MAX; i++){
        if (checkPrime(i) == 1){
            sum += i;
        }
    }
    return sum;
}
