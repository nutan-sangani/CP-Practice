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

void helper(vecll& nums,int n,ll k,ll z)
{
    ll sum=0;
    ll maxSum=0;
    ll j=0;
    while(j<=z){
        sum=0LL;
        ll max=-1;
        ll range=k-j*2;
        if(range<0)
            break;
        for(int i=0;i<=range;i++)
        {
            sum+=nums[i];
            if(i>0 && (nums[i]+nums[i-1])>max){
                max=(nums[i]+nums[i-1]);
            }
        }
        //10 20 30 40 50
        //0  1  2   3  4
        ll temp = sum + ((max)*j);
        ll temp2=-1;
        if(range<n-1){
            ll tempMax = nums[range]+nums[range+1];
            temp2 = sum + (tempMax*j);
            // temp2+=nums[range];
            if(temp2>maxSum){
                // cout<<"temp2 "<<j<<" "<<temp2<<endl;
                maxSum=temp2;
            }
        }
        if(temp>maxSum){
            // cout<<"temp "<<j<<" "<<temp<<endl;
            maxSum=temp;
        }
        j++;
    }
    cout<<maxSum<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll k,z;
        cin>>n>>k>>z;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n,k,z);
    }
    return 0;
}
//5 4 1
//1 5 4 3 2
//0 1 2 3 4
//
