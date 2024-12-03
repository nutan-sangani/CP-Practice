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

void addHalf(vector<int>& direction,vector<char>& ans){
    int half = direction.size()/2;
    for(int i=0;i<direction.size();i++){
        if(half==0){
            ans[direction[i]]='H';
            continue;
        }
        ans[direction[i]]='R';
        half--;
    }
    return;
}

void helper(string s,int n)
{
    if(n==1) {
        cout<<"NO"<<endl;
        return;
    }
    if(n==2){
        if(s[0]==s[1])
        {
            cout<<"RH"<<endl;
            return;
        }
        cout<<"NO"<<endl;
        return;
    }
    int countN,countS,countW,countE;
    countN=countE=countW=countS=0;
    vector<int> N,S,W,E;
    for(int i=0;i<n;i++){
        if(s[i]=='N') N.pb(i);
        if(s[i]=='S') S.pb(i);
        if(s[i]=='E') E.pb(i);
        if(s[i]=='W') W.pb(i);
    }
    vector<char> ans(n);
    countN=N.size();
    countS=S.size();
    countW=W.size();
    countE=E.size();
    if((countN%2==0 && countS%2==0)){
        addHalf(N,ans);
        addHalf(S,ans);
    }
    else if(countN%2!=0 && countS%2!=0){
        ans[N[countN-1]]='R';
        ans[S[countS-1]]='R';
        N.pop_back();
        S.pop_back();
        addHalf(N,ans);
        addHalf(S,ans);
    }//nenRRe
    else {
        cout<<"NO"<<endl;
        return;
    }
    if(countE%2==0 && countW%2==0){
        addHalf(E,ans);
        addHalf(W,ans);
    }
    else if(countE%2!=0 && countW%2!=0){
        ans[E[countE-1]]='H';
        ans[W[countW-1]]='H';
        E.pop_back();
        W.pop_back();
        addHalf(E,ans);
        addHalf(W,ans);
    }
    else {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<endl;
    return;
}
//N=3, e=2, s=1
//

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        helper(s,n);
    }
    return 0;
}