#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,pos=0;
		long long sum=0;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]>0)pos++;
		}
		int ans = pos;

		int rem_sum = sum-pos;


		if(rem_sum < n-1)
		{
			int diff = (n-1)- rem_sum;
			ans -= diff;
		}

		cout<<ans<<endl;
		
	}
}

