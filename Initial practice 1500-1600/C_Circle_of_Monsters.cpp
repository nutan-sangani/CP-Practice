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

void helper(vector<pll>& nums,int n)
{
    vecll diff(n);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int prev = i==0 ? n-1 : i-1;
        diff[i] = max<ll>(nums[i].first - nums[prev].second,0);
        sum+=diff[i];
    }
    ll mini=LLONG_MAX;
    for(int i=0;i<n;i++){
        ll moves = sum - diff[i];
        moves+=nums[i].first;
        mini = min<ll>(moves,mini);
    }
    cout<<mini<<endl;
}
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
        vector<pll> nums;
        forLoop
        {
            ll a,b;
            cin>>a>>b;
            nums.pb(mp(a,b));
        }
        helper(nums,n);
    }
    return 0;
}