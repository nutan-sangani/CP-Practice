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

ll findOps(ll a){
    if(a<=2) return 1;
    ll b = a/3;
    return 1+findOps(b);
}

void helper(ll l,ll r)
{
    ll sum=0;
    int reach = 0;
    ll a = findOps(l); //1
    sum+=2*a; //2
    reach = pow(3,a)-1; //2
    ll prev = a; //1
    ll i = l+1; //2
    while(i<=r){
        int maxi = min<ll>(reach,r);
        sum+= (prev)*(maxi-i+1);
        i=reach+1;
        reach = pow(3,prev+1)-1;
        prev+=1;
    }
    cout<<sum<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        helper(l,r);
    }
    return 0;
}