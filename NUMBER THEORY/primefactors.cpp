#include<bits/stdc++.h>
using namespace std;

vector<int> factor(int n)
{
    vector<int>facts;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            facts.push_back(i);
            n/=i;
        }
    }
    if(n>1)facts.push_back(n);
    //while printing the factors we will use if(n!=1)cout<<n;
    
    return facts;
}

int main()
{
    int n;
    cin>>n;

    vector<int>ans = factor(n);
    for(auto&i:ans)cout<<i<<" is a factor"<<endl;

    return 0;
}