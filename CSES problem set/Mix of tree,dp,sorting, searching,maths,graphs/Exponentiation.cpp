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

ll getExponent(ll a,ll b){
    //a ko b bar multiply krna h.
    if(b==0) return 1LL;
    ll ans=1;
    ll currentPower=a;
    while(b){
        if(b & 1LL){
            ans*=currentPower;
            ans%=mod;
        }
        currentPower*=currentPower;
        currentPower%=mod;
        b/=2;
    }
    return ans;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    cout<<getExponent(a,b)<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}