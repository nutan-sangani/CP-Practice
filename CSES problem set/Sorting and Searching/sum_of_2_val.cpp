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
    ll n,target;
    cin>>n>>target;
    vector<pll> data;
    forn(0,n){
        ll a;
        cin>>a;
        data.pb(mp(a,i));
    }
    sort(itr(data),MyComp());
    int i,j;
    i=0;
    j=n-1;
    while(i<j){
        ll sum = data[i].first + data[j].first;
        if(sum==target){
            cout<<data[i].second+1<<" "<<data[j].second+1<<endl;
            return;
        }
        else if(sum<target){
            i++;
        }
        else --j;
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}