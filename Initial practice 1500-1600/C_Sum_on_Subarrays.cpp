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

void helper(int n,int k)
{
    if(k==0){
        forLoop
        {
            cout<<-1<<" ";
        }
        cout<<endl;
        return;
    }
    vecll ans;
    int count=0;
    int remainder = 0;
    int sum=0;
    for(int i=n;i>0;i--){
        if((sum+i)<=k)
        {
            sum+=i;
            count++;
        }
        else{
            remainder = k-sum-1;
            break;
        }
    }
    int flag=1;
    while(flag){
        ans.pb(40);
        count--;
        if(count<0) flag=0;
        if(count==0 && remainder<0) flag=0;
    }
    sum=40;
    int sizeRem = n - ans.size();
    for(int i=0;i<sizeRem;i++){
        if(remainder>0){
            remainder--;
            ans.pb(-1);
            sum-=1;
        }
        else if(remainder==0){
            ans.pb(-1*(sum+1));
            remainder--;
        }
        else ans.pb(-1);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    // count=0;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++){
    //         ll sum=0;
    //         for(int k=i;k<=j;k++){
    //             sum+=ans[k];
    //         }
    //         if(sum>0){
    //             count++;
    //         }
    //     }
    // }
    // cout<<count<<endl;
    return;

}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        helper(n,k);
    }
    return 0;
}
//count=9;
//rem=0;