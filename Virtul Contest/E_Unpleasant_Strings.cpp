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

void debug(){
    cout<<endl;
}

template<typename T,typename... Args>
void debug(T firstArg,Args... args){
    cout<<firstArg<<" ";
    debug(args...);
}

template<typename T>
void printArray(vector<T>& a){
    int n = a.size();
    forn(0,n) cout<<a[i]<<" ";
    cout<<endl;
}

template<typename T>
void printMatrix(vector<vector<T>>& a){
    int rows = a.size();
    forn(0,rows){
        printArray(a[i]);
    }
}

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

ll memoize(vecll& dp,int index,um<char,vecll>& alphabetIndices,int n,int k){
    if(index>n) return 0;
    else if(dp[index]!=-1) return dp[index];
    int maxIndex = index;
    forn(0,k){
        int alphabetIndex = *lower_bound(itr(alphabetIndices['a'+i]),index);
        maxIndex = max(maxIndex,alphabetIndex);
    }
    return dp[index] = 1 + memoize(dp,maxIndex+1,alphabetIndices,n,k);
}

ll findLastIndexInS(string& s,string& t,um<char,vecll>& alphabetIndices){
    int indexInS = -1;
    int indexInT = 0;
    while(indexInT<t.size()){
        if(lower_bound(itr(alphabetIndices[t[indexInT]]),indexInS+1)!=alphabetIndices[t[indexInT]].end())
            indexInS = *lower_bound(itr(alphabetIndices[t[indexInT]]),indexInS+1);
        else return indexInS;
        indexInT++;
    }
    return indexInS;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vecll dp(n+3,-1); //contains minimal addition from i to make unplesant subseq.
    dp[n+1]=dp[n+2]=0;
    dp[n]=1;
    um<char,vecll> alphabetIndices;
    forn(0,n){
        alphabetIndices[s[i]].pb(i);
    }
    forn(0,k){
        alphabetIndices['a'+i].pb(n+1);
    }
    forn(0,n){
        if(dp[i]==-1)
            memoize(dp,i,alphabetIndices,n,k);
    }
    int q;
    cin>>q;
    // printArray(dp);
    while(q--){
        string t;
        cin>>t;
        int indexInS = findLastIndexInS(s,t,alphabetIndices);
        cout<<dp[indexInS+1]<<endl;
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