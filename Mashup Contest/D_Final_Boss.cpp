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
        return a.first>b.first;
    }
};

void solve(){
    ll h,n;
    cin>>h>>n;
    ll sum=0;
    vecll a(n,0),b(n,0);
    priority_queue<pll,vector<pll>,MyComp> pq; // time : index
    forn(0,n){
        cin>>a[i];
        sum+=a[i];
    }
    forn(0,n){
        cin>>b[i];
        pq.push(mp(1+b[i],i));
    }
    if(sum>=h){
        cout<<1<<endl;
        return;
    }
    h-=sum;
    // cout<<h<<endl;
    ll turn = 1;
    while(h>0){
        pll temp = pq.top();
        pq.pop();
        turn = temp.first;
        h-=a[temp.second];
        temp.first = temp.first+b[temp.second];
        pq.push(temp);
    }
    cout<<turn<<endl;
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