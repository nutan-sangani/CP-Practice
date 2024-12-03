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

// ll dp(vecll& noOfWays,ll rem){
//     if(rem==0){
//         return 1;
//     }
//     else if(rem<0) return 0;
//     else if(noOfWays[rem]!=-1) return noOfWays[rem];
//     ll ways=0;
//     forn(1,7){
//         ways+=dp(noOfWays,rem-i);
//         ways%=mod;
//     }
//     return noOfWays[rem]=ways;
// }

void solve(){
    ll n;
    cin>>n;
    vecll noOfWays(n+1,0);
    noOfWays[0]=1;
    forn(1,n+1){
        for(ll j=1;j<=6;j++){
            ll rem = i-j;
            if(rem>=0){
                noOfWays[i]+=noOfWays[rem];
                noOfWays[i]%=mod;
            }
        }
    }
    cout<<noOfWays[n];
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}