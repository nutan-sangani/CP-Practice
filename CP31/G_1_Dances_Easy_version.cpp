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

bool isValid(vecll& a,vecll& b,int mid){
    sort(itr(a));
    sort(itr(b));
    int n = a.size();
    // a ke sabse bada and b ke sabse chota mid numbers delete kar
    vecll a_dash(n-mid),b_dash(n-mid);
    forn(0,n-mid){
        a_dash[i]=a[i];
    }
    forn(0,n-mid){
        b_dash[i] = b[i+mid];
    }
    forn(0,n-mid){
        if(a_dash[i]>=b_dash[i]) return false;
    }
    return true;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vecll a(n),b(n);
    a[0]=1;
    forn(1,n){
        cin>>a[i];
    }
    forn(0,n) cin>>b[i];
    int low = 0;
    int high = n;
    while(low<=high){
        ll mid = (low+high)/2;
        if(isValid(a,b,mid)){
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<low<<endl;
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