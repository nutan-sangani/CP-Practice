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

void helper()
{
    
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        if(x==0 && y==0){
            cout<<0<<endl;
            continue;
        }
        // ll xmoves = ceil((float(x)/(float)k));
        // ll ymoves = ceil((float(y)/(float)(k)));
        ll xm,ym;
        xm=x/k;
        ym=y/k;
        if(x%k!=0LL) xm++;
        if(y%k!=0LL) ym++;
        ll count=0;
        if(xm>ym){
            count = xm+(xm-1);
        }
        else count = ym*2;
        cout<<count<<endl;
    }
    return 0;
}