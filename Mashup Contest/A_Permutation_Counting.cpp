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

void solve(){
    ll n,k;
    cin>>n>>k;
    priority_queue<ll,vecll,greater<ll>> pq;
    forn(0,n){
        ll a;
        cin>>a;
        pq.push(a);
    }
    ll i=1;
    ll limiting = pq.top();
    ll count=0;
    ll extra = 0;
    while(i<=n){
        ll top = pq.top();
        pq.pop();
        ll next = -1;
        if(!pq.empty())
            next = pq.top();
        if(next==top){
            ++i;
            continue;
        }
        if(next!=-1){
            ll needed = (next-top)*(i);
            if(needed<=k){
                k-=needed;
                limiting = next;
            }
            else{
                ll given = k/i;
                limiting = top + given;
                k -= (i*given);
                extra +=k;
                break;
            }
        }
        else{
            ll given = k/i;
            limiting = top+given;
            k -= (i*given);
            extra += k;
            break;
        }
        ++i;
    }
    count = (limiting)*(n) - (n-1LL);
    count+=extra;
    if(!pq.empty()){
        count+=(pq.size());
    }
    cout<<count<<endl;
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