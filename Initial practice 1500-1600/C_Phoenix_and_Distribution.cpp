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

void addAll(vector<char>& ans,umll& count){
    for(int i=0;i<26;i++){
        for(int j=0;j<count['a'+i];j++){
            ans.pb('a'+i);
        }
    }
    return;
}

void displayAns(vector<char>& ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
}

void helper(string& s,int n,int k)
{
    umll count;
    vector<char> ans;
    vector<char> unique;
    int uniqueCount=0;
    forLoop
    {
        if(count[s[i]]==0){
            uniqueCount++;
            unique.pb(s[i]);
        } 
        count[s[i]]++;
    }
    sort(unique.begin(),unique.end());
    int rem=k;
    if(count[unique[0]]>=rem && unique.size()==1){
        int addition = ceil((count[unique[0]]*1.f)/(k*1.f));
        for(int i=0;i<addition;i++)
            ans.pb(unique[0]);
        // if(count[unique[0]]%k!=0) ans.pb(unique[0]);
        displayAns(ans);
        return;
    }
    if(count[unique[0]]==rem && unique.size()==2){
        ans.pb(unique[0]);
        int addition = ceil((count[unique[1]]*1.f)/(k*1.f));
        for(int i=0;i<addition;i++)
            ans.pb(unique[1]);
        displayAns(ans);
        return;
    }
    if(count[unique[0]]>=rem){
        count[unique[0]]-=rem;
        ans.pb(unique[0]);
        addAll(ans,count);
        displayAns(ans);
        return;
    }
    int range=0;
    int i=0;
    while(i<unique.size()){
        range+=count[unique[i]];
        if(range>=k){
            ans.pb(unique[i]);
            displayAns(ans);
            return;
        }
        i++;
    }
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
        string s;
        cin>>s;
        helper(s,n,k);
    }
    return 0;
}