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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool isSorted(string s,int n){
    forLoop
    {
        if(i<n-1 && s[i]>s[i+1]){
            return false;
        }
    }
    return true;
}
//zzzzzbbb
int countOfSameLargest(string s,vector<int> indexes){
    int count=1;
    int n = indexes.size();
    for(int i=1;i<n;i++){
        if(s[indexes[i]]!=s[indexes[0]]){
        }
        else{
            count++;
        }
    }
    // cout<<count;
    return count;
}

void helper(string s,int n)
{
    if(isSorted(s,n)) 
    {
        cout<<0<<endl;
        return;
    }
    vector<int> indexes;
    string copy=s+"";
    stack<int> st;
    forLoop
    {
        if(st.empty() || st.top()>=s[i]){
            st.push(s[i]);
            indexes.pb(i);
        }
        else{
            while(!st.empty() && st.top()<s[i]){
                st.pop();
                indexes.pop_back();
            }
            st.push(s[i]);
            indexes.pb(i);
        }
    }
    for(int i=0;i<indexes.size();i++){
        s[indexes[i]]=st.top();
        st.pop();
    }
    if(isSorted(s,n)){
        int sameLargest = countOfSameLargest(copy,indexes);
        cout<<indexes.size()-sameLargest<<endl; //handle case where last k elem is repeation multiple times.
    }
    else{
        cout<<-1<<endl;
    }
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
        string s;
        cin>>s;
        helper(s,n);
    }
    return 0;
}
//znmigec