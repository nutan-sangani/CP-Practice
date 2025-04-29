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

ll query(ll i,ll j){
    cout<<"? "<<i<<" "<<j<<endl;
    cout.flush();
    ll ans;
    cin>>ans;
    return ans;
}

void giveAns(string a){
    cout<<"! "<<a<<endl;
    cout.flush();
}

void solve(){
    ll n;
    cin>>n;
    vecll x(n);
    umll map;
    ll largest=LLONG_MIN,smallest=LLONG_MAX;
    forn(0,n){
        cin>>x[i];
        map[x[i]]++;
        if(x[i]>largest) largest=x[i];
        if(x[i]<smallest) smallest=x[i];
    }
    ll firstIndex,lastIndex;
    ll missing = -1;
    forn(0,n){
        if(x[i]==smallest){
            firstIndex=i+1;
        }
        if(x[i]==largest){
            lastIndex=i+1;
        }
        if(map[i+1]==0){
            missing = i+1;
        }
    }
    if(missing!=-1){
        ll other = missing==1 ? 2 : 1;
        ll op = query(missing,other);
        if(op==0){
            giveAns("A");
        }
        else{
            giveAns("B");
        }
        return;
    }
    ll op = query(firstIndex,lastIndex);
    if(op>(largest-smallest)){
        giveAns("B");
    }
    else if(op<(largest-smallest)){
        giveAns("A");
    }
    else{
        ll op2 = query(lastIndex,firstIndex);
        if(op2==(largest-smallest)){
            giveAns("B");
        }
        else giveAns("A");
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