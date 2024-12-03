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
    string s;
    cin>>s;
    int n = s.size();
    vecll a(n,0);
    forn(0,n){
        if(s[i]=='0') a[i]=-1;
        else a[i]=1;
    }
    um<ll,pll> map; //sum : <last_occurence_index,count>
    umll occured;
    ll sum=0;
    ll ans = 0;
    forn(0,n){
        sum+=a[i];
        ll index = i;
        ll larger = n-i;
        if(occured[sum]!=0){
            ll prevIndex = map[sum].first;//0
            ll prevCount = map[sum].second;//0
            ll newStart = prevIndex+1;//1
            ll newCount = newStart+prevCount+1;//2
            ans+=(newCount*larger);//2*6
            ans%=mod;
            pll nn(index,newCount);
            map[sum]=nn;
        }
        else{
            ll smallerCount = i+1;
            occured[sum]=1;
            pll nn(index,0);
            if(sum==0)
                nn.second=1;
            map[sum]=nn;
            if(sum==0)
                ans+=(larger*1LL);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
//-1,1,-1,1,-1,1,-1,1
//-1,0,-1,0,-1,0,-1,0
//map={-1:(2,2),0:(1,2)}
//ans=7+12+

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