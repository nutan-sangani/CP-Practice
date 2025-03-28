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

vector<bool> isPrime(100002,true);

void addNumbersAroundPrime(vecll& ans,umll& used,int prime,int n){
    int i=prime-1;
    int j=prime+1;
    ans.pb(prime);
    used[prime]=1;
    while(i>=1 && j<=n){
        ans.pb(i);
        used[i]=1;
        ans.pb(j);
        used[j]=1;
        i-=1;
        j+=1;
    }
}

void solve(){
    ll n;
    cin>>n;
    vecll ans;
    umll used;
    ll needed = n/3-1;
    forn(2,n+1){
        if(isPrime[i]){
            ll mini = min<ll>(i-1,n-i);
            ll available = 2*mini+1;
            if(available>=needed){
                addNumbersAroundPrime(ans,used,i,n);
                break;
            }
        }
    }
    forn(1,n+1){
        if(used[i]==0){
            ans.pb(i);
        }
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    forn(2,100002){
        ll multiple=2;
        while(multiple*i<100002){
            isPrime[multiple*i]=false;
            multiple+=1;
        }
    }
    while(t--)
    {
        solve();
    }
    return 0;
}