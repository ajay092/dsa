#include <iostream>
#include <cmath>

using namespace std;

unsigned long long power(int x, unsigned int n);

int main(){
    int x = 2, n = 5;
    int xn = power(x, n);
    cout <<xn<<endl;
}

unsigned long long power( int x, unsigned int n){
    if (n==0)
        return 1;
    unsigned long long temp = power(x, n/2);
    if(n%2==0)
        return temp*temp;
    else
        return x*temp*temp;
}