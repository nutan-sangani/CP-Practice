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

ll findKMexFor(ll k,umll& isPresentInSet){
    ll multiple = 1;
    while(isPresentInSet[multiple*k]!=0){
        multiple++;
    }
    return multiple*k;
}

ll findKMexFrom(ll k,ll prev,umll& isPresentInSet){
    ll multiple = prev/k+1;
    while(isPresentInSet[multiple*k]!=0) multiple++;
    return multiple*k;
}

void solve(){
    ll q;
    cin>>q;
    umll isPresentInSet;
    umll cachedMEX;
    vecll op;
    forn(0,q){
        char ops;
        cin>>ops;
        if(ops=='+'){
            ll val;
            cin>>val;
            isPresentInSet[val]=1;
        }
        else{
            ll k;
            cin>>k;
            if(cachedMEX[k]==0){
                ll ans = findKMexFor(k,isPresentInSet);
                op.pb(ans);
                cachedMEX[k]=ans; //wapis k aya toh answer we know.
            }
            else{
                if(isPresentInSet[cachedMEX[k]]==0){
                    op.pb(cachedMEX[k]);
                    continue;
                }
                else{
                    ll ans = findKMexFrom(k,cachedMEX[k],isPresentInSet);
                    op.pb(ans);
                    cachedMEX[k]=ans;
                    continue;
                }
            }
        }
    }
    forn(0,op.size()){
        cout<<op[i]<<"\n";
    }
}

int main()
{
    FASTIO
    solve();
    return 0;
}