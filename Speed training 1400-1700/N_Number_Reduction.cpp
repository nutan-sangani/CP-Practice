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
    forn(0,n) cout<<a[i];
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

void solve(int tc){
    ll n;
    string s;
    cin>>s;
    ll k;
    cin>>k;
    n=s.size();
    vecll a(n);
    forn(0,n){
        a[i]=(s[i]-'0');
    }
    stack<ll> st;
    forn(0,n){
        while(!st.empty() && st.top()>a[i] && k>0){
            if(a[i]==0 && st.size()==1) break;
            else{
                k--;
                st.pop();
            }
        }
        st.push(a[i]);
    }
    vecll ans;
    while(!st.empty()){
        ans.pb(st.top());
        st.pop();
    }
    if(ans.size()>1 && ans[ans.size()-2]==0){
        int countOfFirstPlusAllZeros = 1;
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i]!=0) break;
            countOfFirstPlusAllZeros++;
        }
        if(k>=countOfFirstPlusAllZeros){
            reverse(itr(ans));
            ll x=0,y=countOfFirstPlusAllZeros;
            while(y<ans.size()){
                if(ans[x]>ans[y]){
                    reverse(itr(ans));
                    while(countOfFirstPlusAllZeros){
                        ans.pop_back();
                        countOfFirstPlusAllZeros--;
                        k--;
                    }
                    reverse(itr(ans));
                    break;
                }
                else if(ans[x]<ans[y]) break;
                else{
                    continue;
                }
            }
            reverse(itr(ans));
        }
    }
    reverse(itr(ans));
    while(k>0){
        ans.pop_back();
        k--;
    }
    printArray(ans);
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    int i = 1;
    while(i<=t)
    {
        solve(i);
        i++;
    }
    return 0;
}