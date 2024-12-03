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

void helper(ll n,ll m)
{
    vector<pll> ans;
    ll prev_sum=0;
    int copy=m;
    ans.pb(mp(1,n));
    m--;
    for(int i=2;i<n;i++){
        m--;
        ans.pb(mp(i,i+1));
    }
    if(m>0){
        for(int i=2;i<n;i++){
            if(m>0){
                ans.pb(mp(1,i));
                m--;
            }
            else break;
        }
        for(int i=2;i<n;i++){
            if(m>0){
                for(int j=i+2;j<=n;j++){
                    if(m>0){
                        ans.pb(mp(i,j));
                        m--;
                    }
                    else break;
                }
            }
            else break;
        }
    }
    if(n==2){
        cout<<2<<" "<<2<<endl;
        cout<<1<<" "<<2<<" "<<2<<endl;
        return;
    }
    int sp=2;
    ll mstw=0;
    if((n-1)==2){
        mstw=7;
    }
    else mstw=1e9+7;
    cout<<sp<<" "<<mstw<<endl;
    for(int i=0;i<ans.size();++i){
        ll weight = 0;
        if(i==0){
            weight=2;
            prev_sum+=weight;
            cout<<ans[i].first<<" "<<ans[i].second<<" "<<weight<<endl;
        }
        else if(i==1){
            weight=5;
            prev_sum+=weight;
            cout<<ans[i].first<<" "<<ans[i].second<<" "<<weight<<endl;
        }
        else if(i<n-2){
            weight=5;
            prev_sum+=weight;
            cout<<ans[i].first<<" "<<ans[i].second<<" "<<weight<<endl;
        }
        else if(i==n-2 && i!=1){
            weight = mstw-prev_sum;
            cout<<ans[i].first<<" "<<ans[i].second<<" "<<weight<<endl;
        }
        else{
            // prev_sum+=5;
            cout<<ans[i].first<<" "<<ans[i].second<<" "<<1000000000LL<<endl;
        }
    }
}

int main()
{
    FASTIO
    
    ll n,m;
    cin>>n>>m;
    helper(n,m);
    return 0;
}