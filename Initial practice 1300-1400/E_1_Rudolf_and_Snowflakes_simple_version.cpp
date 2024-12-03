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

bool isValidK(ll k,ll n){
    ll sum=1;
    ll prod = k;
    int count=0;
    while(sum<n){
        sum+=prod;
        prod*=k;
        count++;
    }
    if(sum==n && count>=2){
        return true;
    }
    return false;
}

void helper(ll n) //3 -> 1+2=3 
{
    for(int i=2;i<n;i++){
        if((1+i+i*i)>n)
            break;
        if(isValidK(i,n)){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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