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

void helper(string s,string a,string b,int n)
{
    int j=0;
    map<ll,int> map;
    // 123412341234
    // 3
    // 111
    // 444
    for(int i=0;i<n;i++){
        int lower,upper;
        lower=(a[i]-'0');
        upper=(b[i]-'0');
        int countPossible = upper-lower+1;
        while(j<s.size() && countPossible>0){
            int value = (s[j]-'0');
            if(value<=upper && value>=lower && map[value]==0){
                countPossible--;
                map[value]++;
            }
            j++;
        }
        map.clear();
        if(countPossible!=0){
            cout<<"YES"<<endl;
            return;
        }
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
        string s;
        cin>>s;
        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        helper(s,a,b,n);
    }
    return 0;
}