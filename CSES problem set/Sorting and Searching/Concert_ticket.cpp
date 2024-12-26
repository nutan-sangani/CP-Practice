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
    ll n,m;
    cin>>n>>m;
    multiset<ll> set;
    vecll a(m,0);
    vecll ans(m,-1);
    forn(0,n){
        ll ticketPrice;
        cin>>ticketPrice;
        set.insert(ticketPrice);
    }
    forn(0,m){
        cin>>a[i];
    }
    forn(0,m){
        if(!set.empty()){
            ll ticketBid = a[i];
            auto lb = set.lower_bound(ticketBid);
            if((*lb==ticketBid || lb!=set.begin() || lb==set.end())){
                if(lb==set.end() || *lb>ticketBid){
                    --lb;
                }
                ans[i]=(*lb);
                set.erase(lb);
            }   
        }
        cout<<ans[i]<<endl;
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}