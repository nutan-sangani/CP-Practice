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

void solve(){
    // ll n,k;
    // cin>>n>>k;
    // set<ll> num;
    // forn(1,n+1){
    //     num.insert(i);
    // }
    // ll level=1;
    // ll count=0;
    // while(num.size()>1){
    //     ll val = 1+pow(2,level-1);
    //     ll diff = pow(2,level);
    //     while(*(num.rbegin())>=val){
    //         cout<<val<<" ";
    //         num.erase(val);
    //         val+=diff;
    //         count+=1;
    //         if(count==k) return;
    //     }
    //     level+=1;
    //     cout<<endl;
    // }
    forn(0,30){
        cout<<pow(2,i)<<endl;
    }
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