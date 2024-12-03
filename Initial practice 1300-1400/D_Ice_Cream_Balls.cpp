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

ll calculate(ll n){
    if(n%2==0){
        return (n/2LL)*(n-1)*1ll;
    }
    else{
        return ((n-1)/2LL)*n*1LL;
    }
}

void helper(ll n)
{
    ll low,high;
    low=0;
    high=min<ll>(2*n,(2e9));
    while(low<high){
        ll mid=(low+high)/2;
        ll sum = calculate(mid);
        if(sum<n){
            low=mid+1;
        }
        else if(sum>n){
            high = mid-1;
        }
        else if(sum==n){
            cout<<mid<<endl;
            return;
        }
    }
    ll term = low-1;
    ll val = calculate(term);
    ll diff = n - val;
    term+=diff;
    cout<<term<<endl;
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
        // cout<<calculate()<<endl;
    }
    return 0;
}
//1000000000000000000