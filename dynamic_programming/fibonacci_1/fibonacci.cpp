#include <bits/stdc++.h>

using namespace std;

long fibo_recursion(int n);
long fibo_top_down(int n, long fib[]);
long fibo_bottom_up(int n);
long fibo_bottom_up_space_optimized(int n);

int main(){
    long result;
    int n = 1000;
    long fib[n+1] = {0};
   // cout<<"Memoization = "<<fibo_top_down(n, fib)<<endl;
//     cout<<"Tabulation = "<<fibo_bottom_up(n)<<endl;
    
     cout<<"Tabulation = "<<fibo_bottom_up_space_optimized(n)<<endl;
//     cout<<"Recursion = "<<fibo_recursion(n)<<endl;
}

long fibo_recursion(int n){ // recursive solution
    if(n==1 || n==2) return 1;
    return fibo_recursion(n-1) + fibo_recursion(n-2);
}

long fibo_top_down(int n, long fib[]){ // memoisation
    if(fib[n] != 0) return fib[n];
    
    long result;
    if(n==1 || n==2)
        result = 1;
    else 
        result = fibo_top_down(n-1, fib) + fibo_top_down(n-2, fib);
    
    fib[n] = result;
    return result;
}

long fibo_bottom_up(int n){ // tabulation
    long result;
    long fib[n+1] = {0};
    
    fib[1] = 1;
    fib[2] = 1;
    
    for(int i=3; i<=n; i++)
        fib[i] = fib[i-1] + fib[i-2]; 

    result = fib[n];
    return result;
}

long fibo_bottom_up_space_optimized(int n){ // tabulation
    long a=1, b=1, c;
    
    if(n ==1 || n==2)   return 1;
    
    for(int i=3; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

