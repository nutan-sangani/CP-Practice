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

void solve()
{
    int n;
    cin>>n;
    vecll b(n,0);
    ll y=0;
    forn(0,n){
        cin>>b[i];
        y+=b[i];
    }
    ll sum =0;
    if(n%2==0){
        sum = n/2;
        sum*=(n+1);
    }
    else{
        sum = (n+1)/2;
        sum*=n;
    }
    if(y%sum!=0){
        cout<<"NO"<<endl;
        return;
    }
    y=y/sum;
    vecll a(n,0);
    sum=0;
    forn(1,n){
        ll diff = b[i-1]-b[i];
        diff+=y;
        if(diff%n!=0){
            cout<<"NO"<<endl;
            return;
        }
        diff/=n;
        if(diff<=0){
            cout<<"NO"<<endl;
            return;
        }
        a[i]=diff;
        sum+=diff;
    }
    a[0]=y-sum;
    if(a[0]<=0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    forn(0,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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