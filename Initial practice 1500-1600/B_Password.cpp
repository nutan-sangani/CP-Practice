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

void helper(string& s)
{
    int n = s.size();
    vecll lps(n,0);
    int len = 0;
    int i=1;
    while(i<n){
        if(s[len]==s[i]){
            lps[i] = ++len;
            i++;
        }
        else {
            if(len==0){
                i++;
                continue;
            }
            else {
                len = lps[len-1];
            }
        }
    }
    int suffixLength = lps[n-1];
    if(suffixLength==0){
        cout<<"Just a legend"<<endl;
        return;
    }
    forn(0,n-1){
        if(lps[i]==suffixLength){
            cout<<s.substr(0,suffixLength)<<endl;
            return;
        }
    }
    string sub = s.substr(0,suffixLength);
    int size = sub.size();
    vecll lps2(size,0);
    i=1;
    len=0;
    while(i<size){
        if(sub[i]==sub[len]){
            lps2[i] = ++len;
            i++;
        }
        else{
            if(len==0){
                i++;
            }
            else{
                len = lps2[len-1];
            }
        }
    }
    if(lps2[size-1]==0) cout<<"Just a legend"<<endl;
    else cout<<s.substr(0,lps2[size-1])<<endl;
    return;
}

int main()
{
    FASTIO
    
    string s;
    cin>>s;
    helper(s);
    return 0;
}