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

void solve(){
    string s;
    cin>>s;
    vecll count(26,0);
    int oddCount=0;
    int oddChar=-1;
    int n = s.size();
    forn(0,n){
        count[s[i]-'A']+=1;
    }
    forn(0,26){
        if(count[i]%2!=0){
            oddCount+=1;
            oddChar=i;
        }
    }
    if(oddCount>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    vector<char> ans(n,'a');
    int i=0;
    int j=n-1;
    for(int k=0;k<26;k++){
        if(count[k]==0) continue;
        while(count[k]>1){
            ans[i]=char('A'+k);
            ans[j]=char('A'+k);
            count[k]-=2;
            ++i;
            --j;
        }
    }
    if(n%2!=0){
        ll mid = n/2;
        ans[mid]=char(oddChar+'A');
    }
    for(int k=0;k<n;k++){
        cout<<ans[k];
    }
    return;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}