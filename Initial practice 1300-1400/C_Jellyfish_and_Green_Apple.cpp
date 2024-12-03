#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPowerOf2(ll i){
    return i>0 && (i & (i-1))==0;
}
void helper(ll n,ll m)
{
    if(n==m || n%m==0){
        cout<<0<<endl;
        return;
    }
    n = n%m;
    ll GCD = gcd(m,n);
    if(isPowerOf2(m/GCD)){ // if m can also be a multiple of 2^i, since n=21 and m=24 me n=7 and m=8 hojata and chalta.   
        int realN = n/GCD;
        ll onesInN = std::bitset<64>(realN).count();
        cout<<(1LL*m*onesInN-n)<<endl; //since m*count no banane h, aur 1 operation se ek no banega aur n no.s already h apne pass.
        return;
    }
    else{
        cout<<-1<<endl;
        return;
    }
}
int main()
{
    FASTIO
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        int a=7;
        // cout<<bitset<128>(a).count()<<endl;
        helper(n,m);
    }
    return 0;
}