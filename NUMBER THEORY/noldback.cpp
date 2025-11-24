#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n,k;
    cin>>n>>k;

    vector<int>prime;
    for(int i=2;i<=n;i++)
    {
        bool flag = 1;
        for(int j=2;j<=sqrt(i);j++)
        if(i%j==0)flag =0;

        if(flag)
        prime.push_back(i);
    }

    int ans=0;
    for(int i=0;i<prime.size()-1;i++)
    {
        int num = prime[i]+prime[i+1]+1;
        if(num<=n && find(prime.begin(),prime.end(),num) !=prime.end())
        ans++;
    }

    if(ans>=k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}