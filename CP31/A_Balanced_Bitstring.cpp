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

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    forn(0,k){
        int j = i;
        bool hasOne=false,hasZero=false,hasQuestionmark=false;
        while(j<n){
            if(s[j]=='1') hasOne=true;
            else if(s[j]=='0') hasZero=true;
            else hasQuestionmark=true;
            j+=k;
        }
        if(hasOne==true && hasZero==true){ //means multiple trues are there
            cout<<"NO"<<endl;
            return;
        }
        else if(hasQuestionmark && (hasZero || hasOne)){
            j=i;
            while(j<n){
                if(hasOne){
                    s[j]='1';
                }
                else s[j]='0';
                j+=k;
            }
        }
        //means all are the same so continue;
    }
    ll oneCount=0,zeroCount=0,questionmarkCount=0;
    forn(0,k){
        if(s[i]=='1') oneCount+=1;
        else if(s[i]=='0') zeroCount+=1;
        else questionmarkCount+=1;
    }
    ll diff = max(zeroCount,oneCount) - min(zeroCount,oneCount);
    if(diff==0 || (diff<=questionmarkCount)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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