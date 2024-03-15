#include<bits/stdc++.h>
#define ll long long
#define ln cout<<'\n'; 
using namespace std;
struct Node{
    int val;
    Node * left,*right;
    Node (int val)
    {
        this->val = val;
        left= right = NULL;
    }
};
void insert(int ind,Node * root,string &path,int val)
{
    if(ind == path.size()-1)
    {
        if(path[ind]=='L') root->left = new Node(val);
        else root->right = new Node(val);
        return;
    }

    if(path[ind]=='L') insert(ind+1,root->left,path,val);
    else insert(ind+1,root->right,path,val);
}
void print(Node *root)
{
    if(!root) return;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}
void build(int n,vector<int> &nodes,vector<string> &p)
{
    vector<pair<string,int>> v;
    for(int i=0;i<n-1;i++)
    {
        v.push_back({p[i],nodes[i+1]});
    }
    sort(v.begin(),v.end());
    Node *root = new Node(nodes[0]);
    for(int i=0;i<n-1;i++)
    {
        insert(0,root,v[i].first,v[i].second);
    }
    print(root);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen( "error.txt", "w", stderr);
    freopen( "output.txt", "w", stdout);
    freopen( "input.txt", "r", stdin);
    #endif

    int n; cin>>n;
    vector<string> p(n-1);
    vector<int> nodes(n);
    cin>>nodes[0];
    for(int i=0;i<n-1;i++)
    {
        cin>>p[i]>>nodes[i+1];
    }
    // Node *root = new Node(nodes[0]);
    build(n,nodes,p);
    // now we want to print the tree
    /*
    Input:
    15 1
LLL
2
LL
3
L
4
RR
5
R
6
LLRLL
7
LLR
8
LLRL
9
LLRLR
10
LRRRR
11
LRRL
12
LRRR
13
LRR
14
LR
15
        */
 return 0;
}
