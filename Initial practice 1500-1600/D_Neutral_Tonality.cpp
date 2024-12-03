#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

void helper()
{
    
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vecll a(n,0);
        vecll b(m,0);
        forn(0,n) cin>>a[i];
        forn(0,m) cin>>b[i];
        sort(itr(b),greater<ll>());
        vecll ans;
        while(!a.empty() && !b.empty()){
            ll lastA = a[a.size()-1];
            ll lastB = b[b.size()-1];
            if(lastA>=lastB){
                ans.pb(lastB);
                b.pop_back();
                continue;
            }
            else{
                ans.pb(lastA);
                a.pop_back();
            }
        }
        while(!b.empty()){
            ll lastB = b[b.size()-1];
            ans.pb(lastB);
            b.pop_back();
        }
        while(!a.empty()){
            ll lastB = a[a.size()-1];
            ans.pb(lastB);
            a.pop_back();
        }
        reverse(itr(ans));
        for(ll x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}