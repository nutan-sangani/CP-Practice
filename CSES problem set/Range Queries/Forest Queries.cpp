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
//13:51 ko start
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<vecll> ps1(n,vecll (n,0));
    forn(0,n){
        string s;
        cin>>s;
        ll sum=0;
        for(int j=0;j<n;j++){
            if(s[j]=='*'){
                sum+=1;
            }
            ps1[i][j]=sum;
        }
    }
    vector<vecll> ps2(n,vecll (n,0));
    for(int j=0;j<n;j++){
        ll sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=ps1[i][j];
            ps2[i][j]=sum;
        }
    }
    while(q--){
        ll row1,row2,col1,col2;
        cin>>row1>>col1>>row2>>col2;
        row1-=1;
        col1-=1;
        row2-=1;
        col2-=1;
        ll a,b,c,d;
        a=ps2[row1][col2];
        b=col1>0 ? ps2[row1][col1-1] : 0;
        d=row2+1<n ? ps2[row2+1][col2] : 0;
        c=(row2+1<n && col1-1>=0) ? ps2[row2+1][col1-1] : 0;
        ll val=a-b-d+c;
        cout<<val<<endl;
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}