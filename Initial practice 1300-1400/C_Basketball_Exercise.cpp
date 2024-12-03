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

ll recurse(ll dp[][2],vecll& a,vecll& b,int i,int j){
    if(i<0){
        return 0;
    }
    else if(dp[i][j]!=-1) return dp[i][j];
    else{
        int newJ = j==0 ? 1 : 0;
        ll val = j==0 ? a[i] : b[i];
        return dp[i][j]=max<ll>(recurse(dp,a,b,i-1,j),(recurse(dp,a,b,i-1,newJ)*1LL+val*1LL));
    }
}

void helper(vecll& a,vecll& b,int n)
{
    ll dp[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=-1;
        }
    }
    ll ans = max<ll>(recurse(dp,a,b,n-1,0),recurse(dp,a,b,n-1,1));
    cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vecll a(n);
    vecll b(n);
    forLoop
        cin>>a[i];
    forLoop
        cin>>b[i];
    helper(a,b,n);
    return 0;
}
//3,4,4,4
//4,3,2,1