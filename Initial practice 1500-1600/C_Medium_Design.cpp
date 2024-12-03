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
    bool operator()(const pll& a,const pll& b){ //for max heap and descending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else a.second<b.second;
    }
};

class MyComp1{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and descending sort in vector
        if(a.second!=b.second)
            return a.second>b.second;
        else a.first>b.first;
    }
};

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pll> ranges;
    forn(0,n){
        ll a,b;
        cin>>a>>b;
        ranges.pb(mp(a,b));
    }
    sort(itr(ranges),MyComp());
    ll ans=0;
    ll oneCount=0;
    ll mCount=0;
    priority_queue<pll,vector<pll>,MyComp1> minHeapForUpperRange;
    forn(0,n){
        while(!minHeapForUpperRange.empty() && minHeapForUpperRange.top().second<ranges[i].first){
            pll top = minHeapForUpperRange.top();
            if(top.first==1) oneCount-=1;
            minHeapForUpperRange.pop();
        }
        minHeapForUpperRange.push(ranges[i]);
        if(ranges[i].first==1) oneCount+=1;
        if(ranges[i].second==m) mCount+=1;
        ll mini = min<ll>(oneCount,mCount);
        ll maxi = minHeapForUpperRange.size();
        ll temp = maxi - mini;
        ans = max<ll>(ans,temp);
        //min from 1 and m milega
        //will get max from current kitne chalu h, ie from minHeap ka size.
    }
    cout<<ans<<endl;
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