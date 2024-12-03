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

int getIndexTillAltern(string s){
    int n=s.size();
    int count=0;
    int i=1;
    while(i<n-1 && s[i]!=s[i-1]){
        i++;
        count++;
    }
    return count+1;
}

void helper(string s)
{
    int maxCount=0;
    int n=s.size();
    char one,other;
    one='b';
    other='w';
    vector<char> one1(n),two(n);
    for(int i=0;i<n;i++){
        one1[i]=one;
        two[i]=other;
        one= one=='b'? 'w':'b';
        other= other=='b'?'w':'b';
    }
    int i=0;
    while(i<n){
        int temp=0;
        if(one1[i]==s[i]){
            while(i<n && one1[i]==s[i]){
                i++;
                temp++;
            }
            maxCount = max(maxCount,temp);
        }
        i++;
    }
    i=0;
    while(i<n){
        int temp=0;
        if(two[i]==s[i]){
            while(i<n && two[i]==s[i]){
                i++;
                temp++;
            }
            maxCount = max(maxCount,temp);
        }
        i++;
    }
    int fromStarting = getIndexTillAltern(s);
    reverse(s.begin(),s.end());
    int fromEnding = getIndexTillAltern(s);
    if(s[0]!=s[n-1] && maxCount!=n){
        maxCount = max(maxCount,fromStarting+fromEnding);
    }
    cout<<maxCount<<endl;
}

int main()
{
    FASTIO
    
    string s;
    cin>>s;
    helper(s);
    return 0;
}