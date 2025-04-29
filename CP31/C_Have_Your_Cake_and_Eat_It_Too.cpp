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

bool checkOrder(vecll& first,vecll& second,vecll& third,ll target,string order){
    map<char,pll> sortedMap;
    int i=0;
    int n = first.size();
    ll sum=0;
    pll firstKa,secondKa,thirdKa;
    firstKa.first=0;
    while(i<n && sum<target){
        sum+=first[i];
        i++;
    }
    if(sum<target) return false;
    firstKa.second=i-1;
    secondKa.first=i;
    sum=0;
    while(i<n && sum<target){
        sum+=second[i];
        i++;
    }
    if(sum<target) return false;
    secondKa.second=i-1;
    thirdKa.first=i;
    sum=0;
    while(i<n && sum<target){
        sum+=third[i];
        i++;
    }
    if(sum<target) return false;
    thirdKa.second = max(n-1,i-1);
    sortedMap[order[0]]=firstKa;
    sortedMap[order[1]]=secondKa;
    sortedMap[order[2]]=thirdKa;
    for(auto entry : sortedMap){
        cout<<entry.second.first+1<<" "<<entry.second.second+1<<" ";
    }
    cout<<endl;
    return true;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n),b(n),c(n);
    ll total = 0;
    forn(0,n){
        cin>>a[i];
        total+=a[i];
    }
    forn(0,n) cin>>b[i];
    forn(0,n) cin>>c[i];
    ll target = ceil(float(total)/3.f);
    if(checkOrder(a,b,c,target,"abc")){
        return;
    }
    if(checkOrder(a,c,b,target,"acb")){
        return;
    }
    if(checkOrder(b,c,a,target,"bca")){
        return;
    }
    if(checkOrder(b,a,c,target,"bac")){
        return;
    }
    if(checkOrder(c,b,a,target,"cba")){
        return;
    }
    if(checkOrder(c,a,b,target,"cab")){
        return;
    }
    cout<<-1<<endl;
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