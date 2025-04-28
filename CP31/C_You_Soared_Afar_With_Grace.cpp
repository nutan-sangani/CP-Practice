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

void swapi(vecll& c,int i,int j){
    if(c[i]!=-1)
        c[c[i]]=j;
    if(c[j]!=-1)
        c[c[j]]=i;
    ll temp = c[i];
    c[i]=c[j];
    c[j]=temp;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n),b(n);
    forn(0,n) cin>>a[i];
    forn(0,n) cin>>b[i];
    map<pll,ll> index;
    vecll c(n,-1);
    ll sameCount = 0;
    ll paired = 0;
    forn(0,n){
        pll nn(b[i],a[i]);
        if(a[i]==b[i]){
            sameCount+=1;
            continue;
        }
        if(a[index[nn]]==b[i] && b[index[nn]]==a[i]){
            c[index[nn]] = i;
            c[i] = index[nn];
            paired+=2;
        }
        else index[mp(a[i],b[i])]=i;
    }
    vector<pll> moves;
    if(n%2!=0 && sameCount==1 && paired==n-1){
        ll mid = n/2;
        forn(0,n){
            if(c[i]==-1 && mid!=i){
                moves.pb(mp(mid,i));
                swapi(c,mid,i);
                break;
            }
        }
        forn(0,n/2){
            ll neededOn = n-1-i;
            if(neededOn!=c[i]){
                moves.pb(mp(neededOn,c[i]));
                swapi(c,neededOn,c[i]);
            }
        }
    }
    else if(n%2==0 && paired==n){
        forn(0,n/2){
            ll neededOn = n-1-i;
            if(neededOn!=c[i]){
                moves.pb(mp(neededOn,c[i]));
                swapi(c,neededOn,c[i]);
            }
        }
    }
    else{
        cout<<-1<<endl;
        return;
    }
    cout<<moves.size()<<endl;
    forn(0,moves.size()){
        cout<<moves[i].first+1<<" "<<moves[i].second+1<<endl;
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