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

void helper(vecll& nums,int n,vecll& unique)
{
    map<ll,ll> prev; //nums[i] : index
    umll maxDist;
    for(ll x:unique){
        prev[x]=-1;
    }
    for(int i=0;i<n;i++){
        // if(prev[nums[i]])
        ll dist = i-(prev[nums[i]]==-1 ? 0 : prev[nums[i]]);
        if(prev[nums[i]]==-1){
            // cout<<dist+1<<endl;
            maxDist[nums[i]]=max<ll>(maxDist[nums[i]],(dist+1LL));
        }
        else maxDist[nums[i]]=max<ll>(maxDist[nums[i]],dist);
        prev[nums[i]]=i;
        if(i==n-1){
            for(ll x:unique){
                if(prev[x]!=i)
                {
                    ll temp = i-prev[x]+1;
                    maxDist[x]=max<ll>(maxDist[x],temp);
                }
            }
        }
    }
    vecll ans(n+1);
    sort(unique.begin(),unique.end());
    for(int i=0;i<unique.size();i++){
        int val = maxDist[unique[i]];
        int j=val;
        while(j<=n && ans[j]==0){
            ans[j]=unique[i];
            j++;
        }
        // cout<<unique[i]<<" "<<val<<endl;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            cout<<-1<<" ";
        }
        else cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}
//unqiue = 1,3,5 -> 4 4 4
//1 3 1 5 3 1
//

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll nums(n);
        vecll unique;
        umll map;
        forLoop{
            cin>>nums[i];
            if(map[nums[i]]==0){
                unique.pb(nums[i]);
                map[nums[i]]=1;
            }
        }
        helper(nums,n,unique);
    }
    return 0;
}