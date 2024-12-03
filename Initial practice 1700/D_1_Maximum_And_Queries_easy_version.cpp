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
    int n,q;
    cin>>n>>q;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    forn(0,q){
        ll k;
        cin>>k;
        ll ans = 0;
        vecll b=a;
        for(int j=61;j>=0;j--){
            ll cost=0;
            for(int z=0;z<n;z++){
                if(a[z] & 1LL<<j){
                    continue;
                }
                ll costForThis = ((1LL<<j) - a[z]);
                // cout<<costForThis<<" "<<(1LL<<j)<<" "<<a[z]<<endl;
                cost+=costForThis;
                if(cost>k){
                    break;
                }
            }
            // cout<<cost<<" "<<k<<endl;
            bool isUsed = false;
            if(k>=cost){
                k-=cost;
                isUsed=true;
                ans = ans | 1LL<<j;
            }
            for(int z=0;z<n;z++){
                if(a[z] & 1LL<<j){
                    a[z] -= 1LL<<j;
                    //unsets this bit from this number.
                }
                else if(isUsed){ //if set nhi h,than this no will become zero for further processing
                    a[z]=0;
                }
            }
        }
        a=b;
        cout<<ans<<endl;
    }
}

int main()
{
    FASTIO
    
    // int t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}