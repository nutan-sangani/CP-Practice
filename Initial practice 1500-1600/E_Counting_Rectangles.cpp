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

ll nums[1001][1001];
ll rowWise[1001][1001];
ll colWise[1001][1001];

void helper(ll n,ll q)
{
    for(int i=0;i<1001;i++){
        ll sum=0;
        for(int j=0;j<1001;j++){
            sum+=nums[i][j];
            rowWise[i][j]=sum;
        }
    }
    for(int j=0;j<1001;j++){
        ll sum=0;
        for(int i=0;i<1001;i++){
            sum+=rowWise[i][j];
            colWise[i][j]=sum;
        }
    }
    while(q--){
        ll hs,hb,ws,wb;
        cin>>hs>>ws>>hb>>wb; //1 1 3 4
        ll ans=0;
        ans=colWise[hb-1][wb-1]-colWise[hb-1][ws];
        ans -= (colWise[hs][wb-1] - colWise[hs][ws]);
        cout<<ans<<endl;
    } 
    // cout<<"ho";
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;        
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++)
                nums[i][j]=0;
        }
        for(int i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            nums[a][b]+=(a*b*1LL);
        }
        // cout<<"no";
        helper(n,q);
    }
    return 0;
}
// pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
//ye use krke ek baar me hi rowWise and colWise matrix nikal sakte, ie 2d prefix sum nikal sakte.