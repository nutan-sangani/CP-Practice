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

void helper(vecll &nums,ll n)
{
    int sum=0;
    vector<pll> ans;
    umll count;
    for(int i=0;i<n;i++){
        count[nums[i]]++;
        if(i==0 || i%2==0){
            sum+=nums[i];
        }
        else sum+=(-1*nums[i]);
    }
    if(sum==0){
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }
    if((count[-1]+count[1])%2!=0){
        cout<<-1<<endl;
        return;
    }
    int i=0;
    while(i<n){
        int begin=i;
        while(i<n && nums[i]==0) i++;
        if(i>=n){
            ans.pb(mp(begin+1,i));
            break;
        }
        if(begin!=i)
            ans.pb(mp(begin+1,i));
        int start=i++;
        while(i<n && nums[i]==0) i++;
        if(i>=n){
            ans.pb(mp(begin+1,i));
            break;
        }
        int end=i++;
        int dist = end-start;
        if(dist%2==0)
            sum = nums[start] + nums[end];
        else sum = nums[start] + (-1)*nums[end];
        if(sum==0){
            ans.pb(mp(start+1,end+1));
        }
        else{
            if(dist%2==0){
                ans.pb(mp(start+1,end-2+1));
                ans.pb(mp(end-1+1,end+1));
            }
            else{
                ans.pb(mp(start+1,end-1+1));
                ans.pb(mp(end+1,end+1));
            }
        }
    }
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}