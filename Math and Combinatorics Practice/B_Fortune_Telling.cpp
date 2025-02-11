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

bool isBitSetInY(ll index,ll y){
    ll val = 1LL<<index;
    // cout<<"this "<<val<<endl;
    // cout<<(val&y > 0LL)<<endl;
    val = val&y;
    if(val > 0LL) return true;
    return false;
}

//y = 9 = 8+1 = 1001
//0010 0111
//0010 1010

//7 = 0111
//10 = 1010

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    // cout<<isBitSetInY(0,2)<<endl;
    forn(0,63){
        ll numberWithThisBitSet = 0;
        for(int j=0;j<n;j++){
            if(isBitSetInY(i,a[j])) numberWithThisBitSet+=1;
        }
        bool setInX1,setInX2;
        setInX1 = isBitSetInY(i,x);
        setInX2 = isBitSetInY(i,x+3);
        ll x1Count = numberWithThisBitSet + (setInX1==true ? 1 : 0);
        ll x2Count = numberWithThisBitSet + (setInX2==true ? 1 : 0);
        // cout<<i<<" "<<x1Count<<" "<<x2Count<<" "<<numberWithThisBitSet<<endl;
        if(isBitSetInY(i,y)){
            
            if(x1Count%2!=0 && x2Count%2!=0){
                continue;
            }
            if(x1Count%2!=0){
                cout<<"Alice\n";
                return;
            }
            cout<<"Bob\n";
            return;
        }
        else{
            if(x1Count%2==0 && x2Count%2==0){
                continue;
            }
            if(x1Count%2==0){
                cout<<"Alice\n";
                return;
            }
            cout<<"Bob\n";
            return;
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