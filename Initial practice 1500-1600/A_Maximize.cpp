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

void helper(int x)
{
    int maxi=-1;
    int i=1;
    int maxi_i=-1;
    while(i<x){
        if(gcd(x,i)+i > maxi){
            maxi_i=i;
        }
        maxi=max<int>(maxi,gcd(x,i)+i);
        i++;
    }
    cout<<maxi_i<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        helper(x);
    }
    return 0;
}