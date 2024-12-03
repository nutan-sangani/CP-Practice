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

using namespace std;


void helper(vecll& b,vecll& g,ll n,ll m)
{
    ll ans=0;
    ll bSum=0;
    ll gSum=0;
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    if(b[n-1]>g[0]){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n-1;i++)
        bSum+=b[i];
    for(int i=0;i<m;i++)
        gSum+=g[i];
    ans=gSum+bSum*m;
    if(!binary_search(g.begin(),g.end(),b[n-1])){
        ans-=b[n-2];
        ans+=b[n-1];
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    ll n,m;
    cin>>n>>m;
    vecll b;
    vecll g;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        b.pb(a);
    }
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        g.pb(a);
    }
    helper(b,g,n,m);
    return 0;
}