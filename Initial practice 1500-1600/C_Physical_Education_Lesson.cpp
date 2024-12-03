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

void helper(ll n,ll x)
{
    ll firstLimit = n-x;
    ll count=0;
    for(int i=1;i<=sqrt(firstLimit);i++){
        if(firstLimit%i==0){
            ll kWala = firstLimit/i;
            if((kWala+2)%2==0){
                count++;
            }
        }
    }
    cout<<count<<endl;
    for(int i=1;i<=sqrt(firstLimit);i++){
        if((i+2)%2==0 && firstLimit%i==0){
            count++;
        }
    }
    cout<<count<<endl;
    ll secondLimit=n-x-2;
    for(int i=1;i<sqrt(secondLimit);i++){
        if(secondLimit%i==0){
            ll kWala = secondLimit/i;
            if((kWala+2)%2==0){
                count++;
            }
        }
    }
    cout<<count<<endl;
    for(int i=1;i<sqrt(secondLimit);i++){
        if((i+2)%2==0 && secondLimit%i==0) count++;
    }
    // cout<<count<<endl;
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        helper(n,x);
    }
    return 0;
}