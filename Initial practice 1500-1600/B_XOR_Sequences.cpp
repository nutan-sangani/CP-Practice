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

void helper(ll x,ll y)
{
    ll xoro = x ^ y;
    ll count=0;
    for(int i=0;i<35;i++){
        if(1<<i & xoro){
            break;
        }
        else{
            count+=pow(2,i);
        }
    }
    cout<<count+1<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x;
        cin>>y;
        helper(x,y);
    }
    return 0;
}