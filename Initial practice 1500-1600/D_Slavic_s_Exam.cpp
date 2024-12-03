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

void fillAns(vector<char>& ans){
    int n = ans.size();
    forn(0,n)
        if(ans[i]=='?') ans[i]='a';
    return;
}

void display(vector<char>& ans){
    forn(0,ans.size()){
        cout<<ans[i];
    }
    cout<<endl;
}

void helper(string& s,string& t)
{
    int n = s.size();
    if(s.size()==t.size()){
        forn(0,s.size()){
            if(s[i]!=t[i] && (s[i]!='?')){
                cout<<"NO"<<endl;
                return;
            }
            else s[i]=t[i];
        }
        cout<<"YES"<<endl;
        cout<<s<<endl;
        return;
    }
    int i=0;
    int j=0;
    vector<char> ans(n,'.');
    forn(0,n) ans[i]=s[i];
    while(i<n){
        if(s[i]==t[j] || s[i]=='?'){
            ans[i]=t[j];
            i++;
            j++;
        }
        else i++;
        if(j==t.size()){
            cout<<"YES"<<endl;
            fillAns(ans);
            display(ans);
            return;
        }
    }
    if(j==t.size()){
        cout<<"YES"<<endl;
        fillAns(ans);
        display(ans);
        return;
    }
    cout<<"NO"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s;
        cin>>t;
        helper(s,t);
    }
    return 0;
}