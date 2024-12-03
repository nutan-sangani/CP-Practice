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

ll countTrailingZeros(string s){
    int n = s.size();
    int j=n-1;
    ll count=0;
    while(s[j]=='0'){
        j--;
        count++;
    }
    return count;
}

void helper(vector<string>& nums,int k,int n)
{
    priority_queue<ll,vecll> pq;
    ll countOfDigits = 0;
    for(int i=0;i<n;i++){
        pq.push(countTrailingZeros(nums[i]));
        countOfDigits+=(nums[i].size());
    }
    bool isEven=true;
    while(!pq.empty()){
        ll element = pq.top();
        pq.pop();
        if(isEven){
            countOfDigits-=element;
            isEven=false;
        }
        else isEven=true;
    }
    // cout<<countOfDigits<<endl;
    if((countOfDigits-1)>=k){
        cout<<"Sasha"<<endl;
        return;
    }
    cout<<"Anna"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<string> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        helper(nums,k,n);
    }
    return 0;
}