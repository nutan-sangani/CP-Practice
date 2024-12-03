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

void helper(string& s,int n)
{
    ll left,right;
    left=right=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            right+=(right+1);
        }
        else left+=(left+1);
    }
    ll last = pow(2,n);
    for(int i=1;i<=last;i++){
        if(i>left && last-right>=i){
            cout<<i<<" ";
        }
    }
    return;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    helper(s,n);
    return 0;
}