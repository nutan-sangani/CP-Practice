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
    ll row,col;
    cin>>row>>col;
    ll maxi;
    ll ans=-1;
    maxi=max<ll>(row,col);
    ll prevSpiralNumber = (maxi-1LL)*(maxi-1LL);
    pll nextRange(prevSpiralNumber+1,(maxi*maxi));
    bool ulta=false;
    if(maxi%2==0){
        ulta=true;
    }
    if(col<row){
        if(ulta){
            ans=nextRange.second+1LL-col;
        }
        else{
            ans=nextRange.first-1LL+col;
        }
    }
    else{
        if(ulta){
            ans=nextRange.first+row-1LL;
        }
        else{
            ans=nextRange.second-row+1LL;
        }
    }
    // cout<<nextRange.first<<" "<<nextRange.second<<endl;
    // cout<<(maxi-1LL)*(maxi-1LL)<<endl;
    // cout<<static_cast<ll>(pow(maxi-1LL,2LL))<<endl;
    cout<<ans<<endl;
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