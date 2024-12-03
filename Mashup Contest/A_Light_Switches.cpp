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

bool intersects(pll& range1,pll& range2){
    if((range1.first<=range2.second && range1.first>=range2.first) ||
       (range1.second<=range2.second && range1.second>=range2.first) )
        return true;
    return false;
}

pll join(pll& r1,pll& r2){
    pll resultantRange(max<ll>(r1.first,r2.first),min<ll>(r1.second,r2.second));
    return resultantRange;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    sort(itr(a));
    pll range(a[n-1],a[n-1]+k-1);
    forn(0,n){
        ll diff = a[n-1] - a[i];
        ll r = (diff%(2*k)==0) ? (diff/(2*k)) : (diff/(2*k)+1);
        ll newStart = a[i]+r*2*k;
        if(newStart>range.second){
            newStart-=(2*k);
        }
        pll newR(newStart,newStart+k-1);
        if(intersects(range,newR)){
            range = join(range,newR);
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    cout<<range.first<<endl;
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