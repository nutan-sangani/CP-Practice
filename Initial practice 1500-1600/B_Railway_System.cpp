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

ll query(string s){
    cout<<"? "<<s<<endl;
    cout.flush();
    ll z;
    cin>>z;
    return z;
}

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap
        return a.first<b.first;
    }
};

void solve(){
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    string allZero ="";
    string allOne="";
    priority_queue<pll,vector<pll>,MyComp> pq;
    forn(0,m){
        allZero+="0";
        allOne+="1";
    }
    forn(0,m){
        allZero[i]='1';
        ll cost = query(allZero);
        sum+=cost;
        allZero[i]='0';
        pq.push(mp(cost,i));
    }
    ll reducedCost = query(allOne);
    ll temp=0;
    while(pq.size()>1){
        pll top = pq.top();
        pq.pop();
        ll val = top.first;
        allOne[top.second]='0'; //ie max nikala toh kuch change horha kya?
        ll newCost = query(allOne);
        ll expectedCost = reducedCost - val;
        if(newCost>expectedCost){
            temp+=val;
        }
        reducedCost=newCost;
    }
    cout<<"! "<<sum-temp<<endl;
    cout.flush();
}

int main()
{
    FASTIO
    
    // int t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}