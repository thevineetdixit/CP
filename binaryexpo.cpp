//there exists a pow(a,b) function already here,it take a to the power b time comp
//it is a bad habbit to use pow function ,always declare your own

// Ab(even) = A[b/2]+A[b/2];
//Ab(odd) = A[b/2]+A[b/2]+A; // cause we take floor value (5/2 = 2)

#include<bits/stdc++.h>
using namespace std;

int power(int a,int b)
{
    if(b==0)return 1;

    int half_power = power(a,(b/2));

    if(b%2)
    return half_power * half_power * a;
    else
    return half_power * half_power;
}


int main()
{
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);

    return 0;
}