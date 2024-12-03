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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(vector<ll>& nums,ll n,ll m,string s)
{
    ll product = 1LL;
    int start,end;
    start=0;
    end=n-1;
    for(int i=0;i<n-1;i++){
        if(s[i]=='L'){
            start++;
        }
        else{
            end--;
        }
    }
    vector<ll> val;
    val.pb(nums[start]);
    for(int i=n-2;i>=0;i--){
        if(s[i]=='L'){
            start--;
            val.pb(nums[start]);
        }
        else{
            end++;
            val.pb(nums[end]);
        }
    }
    vector<ll> ans;
    for(int i=0;i<n;i++){
        product=((product*val[i])%m);
        ans.pb(product);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> nums(n);
        forLoop
            cin>>nums[i];
        string s;
        cin>>s;
        helper(nums,n,m,s);
    }
    return 0;
}