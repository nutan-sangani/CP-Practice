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

ll findBasic(ll n,ll m){
    while(n%m==0){
        n/=m;
    }
    return n;
}

bool isPowerOfM(ll n,ll m){
    ll val = m;
    while(val<n){
        val*=m;
    }
    if(val==n) return true;
    return false;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    ll n2;
    cin>>n2;
    vecll b(n2,0);
    forn(0,n2) cin>>b[i];
    ll i,j;
    i=j=0;
    vector<ll> data(n,-1);
    ll prevBasic = 0;
    ll prevRem = 0;
    while(i<n && j<n2){
        if(prevBasic==0 && a[i]==b[j]){
            i++;
            j++;
            continue;
        }
        if(data[i]==-1){
            ll newBasic = findBasic(a[i],m);
            if(prevBasic==newBasic || prevBasic==0){
                prevRem += (a[i]/newBasic);
                prevBasic=newBasic;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
            data[i]=0;
        }
        if(prevBasic*prevRem<b[j]){
            i++;
            continue;
        }
        ll bKaBasic = findBasic(b[j],m);
        if(prevBasic==bKaBasic){
            ll req = b[j]/bKaBasic;
            if(req==1 || isPowerOfM(req,m)){
                prevRem-=req;
                j++;
                if(prevRem==0){
                    prevRem=0;
                    prevBasic=0;
                    i++;
                }
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    if(i==n && j==n2){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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