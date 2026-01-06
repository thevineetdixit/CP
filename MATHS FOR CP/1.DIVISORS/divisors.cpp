#include<bits/stdc++.h>
using namespace std;


//there is many ways to find the dvisisors of a number
//first one is very basic like o(N), to check every number from 1 -> n which (n%i==0)

//second method is a better way by checkig only till square root of N, i.e 1 -> i*i<=N 
//here we have to cnt+=2 because (d,n/d) get two divisors and here we to check if (i*i !=n) becuase when adding half we should increase cnt by one only

//Now there is a advanced version related to divisors and their variations

// the first here is the Prime factorisation method
// the prime factorisation method is we can represent any number with its prime factors and then the power will define the count of divisors
// count  = (power+1) * ( power2 +1) ------------ for every prime factor there

void primefact(int n){
int ans =1;
int sum = 1;
int N = n;
for(long long i = 2; i * i <= n ; i++ )
{
    int cnt =0;//this will get the pwoer of a numberr 
    int currsum =1; //any no power zero already 1
    int p_sum =1;
    while(n % i == 0)
    {
        cnt++;
        n/=i;
        p_sum *= i;
        currsum += p_sum;
    }
    ans *= (cnt+1);
    sum *= currsum;
}

if(n > 1)ans *= 2; //this is a very important case where the nis left and this is becuas n is a prime no left so 
//ab us prime ki power bhi one hogi to end me ans*2  ( power +1 = 2)

cout<<"Number of Divisors by prime factorisation is "<<ans << endl;

//the sum of divisors 
if(n>1)sum *= (n+1);
cout<<"Sum of divisors of N "<<sum<<endl;
//to calcularte sum even yu have to compute the whole no of divisors algo;


//another catch here can be to find the product of divisors,
//the main logic is every piar will have the product of N,and since there will alway be even no of divisors of any no ,
//and since we will find the no till sqrt n means well go till that only,and well get the count of nos half and the rest half will be just doubled 
//so the N to the power half no is the ans that is the proudct of all the divisors

//since we have already alculated the count of it so we wont be calcualting it agan by loop
// we will just do half of count and then mulitply n that times 

int  prod = 1;
for(int i=0;i<ans/2;i++)
prod*=N;

cout<<"the product of N "<<prod<<endl;

}




int main()
{
    int n;
    cout<<"enter the value of N"<<endl;
    cin>>n;

    //getting the count of divisors through prime factorisation method
    primefact(n);

    return 0;
}