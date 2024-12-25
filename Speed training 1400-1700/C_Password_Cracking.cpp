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

int query(string s){
    cout<<"? "<<s<<endl;
    cout.flush();
    int output;
    cin>>output;
    return output;
}

void solve(){
    int n;
    cin>>n;
    string ans="1";
    if(n==1){
        if(query("1")){
            cout<<"! 1"<<endl;
            cout.flush();
            return;
        }
        cout<<"! 0"<<endl;
        cout.flush();
        return;
    }
    //keep adding prefix
    while(ans.size()<n){
        string addOne = "1"+ans;
        string addZero = "0"+ans;
        if(query(addOne)){
            ans = "1"+ans;
        }
        else if(query(addZero)){
            ans = "0" + ans;
        }
        else break;
    }
    if(ans.size()==n && n!=1){
        cout<<"! "<<ans<<endl;
        cout.flush();
        return;
    }
    //keep adding suffix;
    while(ans.size()<n){
        string addOne = ans+"1";
        string addZero = ans+"0";
        if(query(addOne)){
            ans = ans+"1";
        }
        else if(query(addZero)){
            ans = ans+"0";
        }
        else break;
    }
    if(ans.size()<n){
        //means khali zeros h.
        ans="";
        while(n){
            ans+="0";
            --n;
        }
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}