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
    ll n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    ll count=0;
    int i,j;
    j=n/2;
    if(n%2==0){
        i=j-1;
        if(a[i]==a[j]) count+=1;
    }
    else{
        i=j-1;
        j=j+1;
        if(a[i]==a[n/2]) count+=1;
        if(a[n/2]==a[j]) count+=1;
    }
    ll prevI=a[i],prevJ=a[j];
    i-=1;
    j+=1;
    while(i>=0 && j<n){
        ll countBefore=0;
        if(a[i]==prevI) countBefore+=1;
        if(a[j]==prevJ) countBefore+=1;
        ll temp = a[i];
        a[i]=a[j];
        a[j]=temp;
        ll countAfter=0;
        if(a[i]==prevI) countAfter+=1;
        if(a[j]==prevJ) countAfter+=1;
        if(countBefore<countAfter){
            ll temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            countAfter=countBefore;
        }
        else countBefore=countAfter;
        count+=countAfter;
        prevI=a[i];
        prevJ=a[j];
        i-=1;
        j+=1;
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