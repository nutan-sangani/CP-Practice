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

bool isValid(vecll& a,ll mid,ll parts){
    ll partsCreated=1;
    ll prevSum=0;
    forn(0,a.size()){
        ll currSum = prevSum+a[i];
        if(a[i]>mid) return false;
        if(currSum<=mid){
            prevSum = currSum;
        }
        else{
            partsCreated+=1;
            prevSum = a[i];
        }
    }
    if(partsCreated<=parts) return true;
    return false;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vecll a(n,0);
    ll sum=0;
    forn(0,n){
        ll val;
        cin>>val;
        sum+=val;
        a[i]=val;
    }
    ll low = sum/n;
    ll high = sum;
    while(low<=high){
        ll mid = (low+high)/2;
        if(isValid(a,mid,k)){
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<low<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}