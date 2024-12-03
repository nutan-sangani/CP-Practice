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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

void display(vector<pll>& ans){
    int n = ans.size();
    cout<<n<<endl;
    forn(0,n){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
}

void helper(string s,int n,int k)
{
    vector<pll> ans;
    int openingTill = 0;
    int i=0;
    while(i<n && s[i]=='(') ++i;
    openingTill = i;
    forn(0,n){
        if(s[i]=='(' && i>openingTill)
        {   
            ans.pb(mp(openingTill,i));
            openingTill++;
        }
    }
    int size = n/2;
    if(k>1){
        i=1;
        int j = size;
        int diff = k-1;
        while(diff>0){
            ans.pb(mp(i,j));
            j++;
            i+=2;
            --diff;
        }
    }
    display(ans);
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
        string s;
        cin>>s;
        helper(s,n,k);
    }
    return 0;
}