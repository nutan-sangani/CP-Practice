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

ll findLargestMultiple(ll n){
    ll val=1;
    for(int i=1;i<n;i++){
        if(n%i==0)
            val = i;
    }
    return val;
}

void helper(int n)
{
    string s(n,'0');
    int nonMultiple = -1;
    for(int i=2;i<=26;i++){
        if(n%i!=0){
            nonMultiple = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        s[i]=('a'+i%nonMultiple);
    }
    cout<<s<<endl;
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
        cin>>n;
        helper(n);
        // cout<<880%26<<endl;
    }
    return 0;
}