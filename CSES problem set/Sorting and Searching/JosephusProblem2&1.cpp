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

ll doModulus(ll a,ll b){
    if(a==0 || b==0) return 0;
    else return a%b;
}

void solve(){
    ll n,k;
    cin>>n>>k; //for josephus problem 1
    cin>>n;
    // k=1; //for jp 2
    ordered_set set;
    forn(1,n+1){
        set.insert(i);
    }
    k+=1;
    ll p = doModulus(max<ll>(0,k-1),set.size());
    while(!set.empty()){
        auto itr = set.find_by_order(p);
        cout<<(*(itr))<<" ";
        set.erase(itr);
        cout.flush();
        p=doModulus(max<ll>(p+k-1,0),set.size());
    }
    return;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}