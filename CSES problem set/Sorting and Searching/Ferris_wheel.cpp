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
    ll n,x;
    cin>>n>>x;
    multiset<ll> set;
    forn(0,n){
        ll a;
        cin>>a;
        set.insert(a);
    }
    ll bucketCount=0;
    while(set.size()>1){
        auto it = set.end();
        --it;
        ll val = *(it);
        ll target = x-val; //target se chota ya equal chalega, thus lower_bound
        set.erase(it);
        auto lb = set.lower_bound(target);
        bucketCount+=1;
        if((*lb)==target){
            set.erase(lb);
        }
        else if(lb==set.begin()){
            continue;
        }
        else{
            --lb;
            set.erase(lb);
        }
    }
    if(set.size()==1) bucketCount+=1;
    cout<<bucketCount<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}