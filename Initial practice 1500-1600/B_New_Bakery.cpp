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

ll getSum(ll n){
    if(n%2==0){
        return (n/2)*(n+1);
    }
    return ((n+1)/2)*n;
}

void helper(int n,ll a,ll b)
{
    ll profit=0;
    if(a>=b){
        profit = n*a*1LL;
    }
    else{
        ll diff = b-a;
        ll lunga = min<ll>(n,diff);
        ll temp = getSum(b) - getSum(b-lunga);
        profit = (temp + (n*1LL-lunga+0LL)*a);
    }
    cout<<profit<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll a,b;
        cin>>n>>a>>b;
        helper(n,a,b);
    }
    return 0;
}