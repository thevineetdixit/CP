#include<bits/stdc++.h>
using namespace std;


void sieve(int n)
{
    vector<bool>prime(n+1,1);
    prime[0]=prime[1]=0; 
    //to exclude 0,1

    //THE TOTAL T.C O(N LOG(LOG(N))) WHICH IS ALMOST EQUAL TO O(N);

    for(int i=2;i<n;i++)//o(N)
    {
        if(prime[i]){
            cout<<i<<" is a prime no "<<endl;
            for(int j=i*2;j<n+1;j+=i)
            prime[j]=0;
        }
    }
    return;
}
int main(){
    int n ;
    cin>>n;
    sieve(n);

    return 0;
}