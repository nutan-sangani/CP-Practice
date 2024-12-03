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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

int main()
{
    FASTIO
    
    ll k;
    cin>>k;
    if(k==0){
        cout<<1<<" "<<1<<endl;
        cout<<300<<endl;
    }
    else{
        ll x = pow(2,(int)log2(2*k));
        cout<<3<<" "<<2<<endl;
        ll combined = x | k;
        cout<<combined<<" "<<k<<endl;
        cout<<x<<" "<<combined<<endl;
        cout<<0<<" "<<k<<endl;
    }
    return 0;
}