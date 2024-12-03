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

void helper(ll n,ll k)
{
    ll maxi =0;
    ll first = n-1;
    while(first>0){
        maxi+=first;
        first-=2;
    }
    maxi*=2;
    if(k>maxi){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    vecll ans(n);
    forLoop
        ans[i]=(i+1);
    if(k==maxi) reverse(ans.begin(),ans.end());
    else{
        int i=0;
        int j=n-1;
        while(i<j){
            ll diff = j-i;
            if((k/2)>=diff){
                int temp = ans[i];
                ans[i]=ans[j];
                ans[j]=temp;
                i++;
                j--;
                k-=(diff*2);
            }
            else if(k==0) break;
            else{
                i++;
            }
        }
    }
    forLoop
        cout<<ans[i]<<" ";
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
        ll n,k;
        cin>>n>>k;
        if(k%2!=0){
            cout<<"No"<<endl;
        }
        else helper(n,k);
    }
    return 0;
}