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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<pll> a;
    forn(0,n){
        ll k;
        cin>>k;
        a.pb(mp(k,i));
    }
    vecll ans(n,0);
    ll sum=0;
    sort(itr(a),MyComp());
    ll first = a[0].first;
    forn(0,n){
        sum+=(a[i].first-first+1);
    }
    ans[a[0].second]=sum;
    forn(1,n){
        ll diff = i>0 ? (a[i].first-a[i-1].first) : (a[i].first);
        ll prePrevCount,nextCount;
        nextCount = n-i-1;
        prePrevCount = max((i+1) - 2,0);
        sum+=(prePrevCount*diff);
        sum-=(nextCount*diff);
        ans[a[i].second]=sum;
    }
    forn(0,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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