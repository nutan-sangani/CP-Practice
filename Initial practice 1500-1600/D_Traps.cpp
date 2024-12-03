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

ll sumOfnNaturalNumbers(ll n){
    if(n%2==0){
        return (n/2LL)*(n+1);
    }
    return ((n+1LL)/2LL)*n;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vecll a(n,0);
    priority_queue<ll,vecll> pq;
    ll sum=0;
    forn(0,n){
        cin>>a[i];
        pq.push(a[i]-(n-(i+1)));
        sum+=a[i];
    }
    if(k==n){
        cout<<0<<endl;
        return;
    }
    int i=0;
    while(!pq.empty() && i<k){
        // if(pq.top()>=0){
            sum-=pq.top();
            pq.pop();
        // }
        // else break;
        i++;
    }
    int rem = n - pq.size();
    sum -= sumOfnNaturalNumbers(rem-1);
    cout<<sum<<endl;
}
//1,1,1,1,1,1,1,1,1,1
//-,-,-,-,-,-3,-2,-1,0,1
//sum = 10 - 0 - 1 = 7

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