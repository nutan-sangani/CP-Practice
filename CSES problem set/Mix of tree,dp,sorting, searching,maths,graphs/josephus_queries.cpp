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

ll pow2(ll n){
    ll ans=1;
    while(n){
        ans*=2;
        n-=1;
    }
    return ans;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    pll range;
    range.first=1;
    range.second=n;
    ll level=1;
    bool deleteFromFirst = false;
    while(1){
        if(range.first==range.second){
            cout<<range.first<<endl;
            return;
        }
        ll halfGap = pow2(level-1LL);
        ll gap = pow2(level);
        ll firstDeleted = deleteFromFirst ? range.first : (range.first+halfGap);
        ll lastDeleted = (range.second - firstDeleted)%gap==0 ? range.second : (range.second - halfGap);
        ll numberDeleted = ((lastDeleted-firstDeleted)/gap)+1;
        if(lastDeleted==range.second){
            deleteFromFirst=false;
        }
        else deleteFromFirst=true;
        range.first = (firstDeleted==range.first) ? (range.first+halfGap) : range.first;
        range.second = (lastDeleted==range.second) ? (range.second-halfGap) : range.second;
        level+=1;
        if(k<=numberDeleted){
            k-=1;
            ll kthDeleted = firstDeleted+(k*gap);
            cout<<kthDeleted<<endl;
            return;
        }
        else k-=numberDeleted;
    }
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