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

class MyCompir{
    public:
        bool operator()(pair<int,int>&a , pair<int,int>&b){ //asks positon is correct or not
            return a.first>b.first;
        }
};

void helper(vecll& nums,int n,int m,int k)
{
    if(n==k){
        cout<<n<<endl;
        return;
    }
    vector<pair<int,int>> diff;
    for(int i=0;i<n-1;i++)
    {
        diff.pb(mp(nums[i+1]-nums[i],i));
    }
    sort(diff.begin(),diff.end(),MyCompir());
    omll deleted;
    for(int i=0;i<k-1;i++){
        deleted[diff[i].second]=1;
        // cout<<diff[i].second<<" ";
    }
    // for(int i=0;i<n-1;i++){
    //     cout<<diff[i].first<<" ";
    // }
    int i=0;
    ll ans=0;
    while(i<n){
        // // if(deleted[i]==1){
        // //     cout<<i<<" ";
        // // }
        // i++;
        int first,last;
        first=last=-1;
        int count=0;
        while(i<n && deleted[i]!=1){
            count++;
            if(first==-1){
                first=nums[i];
                last=nums[i];
            }
            if(i==n-1){
                last=nums[i];
            }
            i++;
        }
        if(i<n && deleted[i]==1){
            count++;
            last=nums[i];
        }
        if(count>1){
            ans+=((last-first+1)*1LL);
        }
        else{
            ans+=1;
        }
        i++;
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    int n,m,k;
    cin>>n>>m>>k;
    vecll nums(n);
    forLoop
        cin>>nums[i];
    helper(nums,n,m,k);
    return 0;
}
//11,46,6
//46,11,6

//2,2,57,28
//57,28,2,2