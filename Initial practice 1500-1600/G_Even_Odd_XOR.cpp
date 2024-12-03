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

void helper(ll n)
{
    vector<ll> ans;
    ll xorValue=0;
    for(int i=0;i<n-2;i++){
        ans.pb(i+1);
        xorValue^=(i+1);
    }
    if(xorValue==0){
        xorValue ^= ans[0];
        ans[0]=n+4;
        xorValue ^= n+4;
    }
    xorValue ^= INT_MAX;
    ans.pb(INT_MAX);
    ans.pb(xorValue);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return;
}
int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        helper(n);
    }
    return 0;
}
//last odd h, toh odd ko leke change kr, warna even ko leke kar
//want 0, have 1, toh 1
//want 0, have 0, toh 0
//want 1, have 1, toh 0
//want 1, have 0, toh 1