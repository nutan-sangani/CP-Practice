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

void insert(stack<char>& st){
    if(!st.empty() && st.top()=='0'){
        st.push('0');
        return;
    }
    st.push('2');
    return;
}

void remove(stack<char>& st){
    if(!st.empty() && st.top()=='1'){
        st.pop();
        if(!st.empty())
        {
            st.pop();
            st.push('1');
        }
        return;
    }
    st.pop();
    return;
}

void helper(string s)
{
    stack<char> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            insert(st);
        }
        else if(s[i]=='-'){
            remove(st);
        }
        else if(s[i]=='1'){
            if(st.size()<=1){
                continue;
            }
            else{
                if(st.top()!='0'){
                    st.pop();
                    st.push('1');
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        else if(s[i]=='0'){
            if(st.size()<=1){
                cout<<"NO"<<endl;
                return;
            }
            if(st.top()!='1'){
                st.pop();
                st.push('0');
                continue;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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
        helper(s);
    }
    return 0;
}