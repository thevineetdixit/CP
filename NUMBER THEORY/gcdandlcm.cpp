#include <bits/stdc++.h>
using namespace std;


// euclidean method to find gcd of two numbers efficiently
// gcd(a,b)= gcd(b%a,a);
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

//the firmula is lcm(a,b)=a X b/gcd(a,b);
int lcm(int a,int b)
{
    return (a* b)/gcd(a,b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);

    return 0;
}