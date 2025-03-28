#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct MyComp{
    bool operator()(const pair<pll,ll>&a, const pair<pll,ll>& b) const {
        ll sum1=a.second;
        ll sum2=b.second;
        if(sum1!=sum2){
            return sum1<sum2;
        }
        else if(a.first.first!=b.first.first) return a.first.first<b.first.first;
        else return a.first.second<b.first.second;
    }
};

void addAvailableSpace(set<pair<pll,ll>,MyComp>& q,int x,int y){
    q.insert(mp(mp(x,y),x+y));
    q.insert(mp(mp(x,y+1),x+y+1));
    q.insert(mp(mp(x+1,y),x+y+1));
    q.insert(mp(mp(x+1,y+1),x+y+2+2));
}

void addDiagonalToAvailable(set<pair<pll,ll>,MyComp>& q,int x,int y,set<pair<pll,ll>,MyComp>& empty){
    ll end = y;
    while(x<=end){
        addAvailableSpace(q,x,y);
        empty.insert(mp(mp(x,y),x+y));
        x+=3;
        y-=3;
    }
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    set<pair<pll,ll>,MyComp> available;
    set<pair<pll,ll>,MyComp> empty;
    map<pll,ll> isEmpty;
    ll xEmpty = 1,yEmpty=1;
    ll sqrti = sqrt(2*n)+5;
    forn(0,sqrti){
        addDiagonalToAvailable(available,xEmpty,yEmpty,empty);
        yEmpty+=3;
    }
    forn(0,n){
        if(a[i]==1){
            pair<pll,ll> nn = *(available.begin());
            cout<<nn.first.first<<" "<<nn.first.second<<endl;
            available.erase(nn);
            if(empty.find(nn)!=empty.end()){
                empty.erase(nn);
            }
        }
        else{
            pair<pll,ll> nn = *(empty.begin());
            cout<<nn.first.first<<" "<<nn.first.second<<endl;
            empty.erase(nn);
            if(available.find(nn)!=available.end()){
                available.erase(nn);
            }
        }
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