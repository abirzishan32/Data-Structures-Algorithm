#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define pb push_back
#define N 10000005
#define div 1000003
#define mod 1000000007
#define MOD 998244353
#define fr(i,a,b) for(int i = a;i<b;i++)
#define fri(i,a,b) for(int i = a;i>=b;i--)
#define pyn(flag) cout<<(flag?"YES":"NO")<<endl;
#define vrev reverse(v.begin(), v.end())
#define vin cin>>v[i]
#define vsort sort(v.begin(), v.end())
#define yout cout<<"YES"<<endl
#define nout cout<<"NO"<<endl;


class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node (int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree{
    public:
    Node *root;
    BinaryTree() : root(nullptr) {}
    void insertion(Node* &curr, int val){
        if(curr == nullptr){
            curr = new Node(val);
            return;
        }
        else if(val < curr->data) {
            insertion(curr->left, val);
        }
        else{
            insertion(curr->right, val);
        }
    }

    void inserting(int val){
        insertion(root, val);
    }

    void inorder(Node *node){
        if(node != nullptr){
            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);
        }
    }

    void Inorder(){
        cout<<"Inorder : ";
        inorder(root);
    }

    void preorder(Node *node){
        if(node != nullptr){
            cout<<node->data<<" ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void Preorder(){
        cout<<"Preorder : ";
        preorder(root);
    }

    void postorder(Node *node){
        if(node != nullptr){
            postorder(node->left);
            postorder(node->right);
            cout<<node->data<<" ";
        }
    }

    void Postorder(){
        cout<<"Postorder : ";
        postorder(root);
    }


};



int main(int argc, const char** argv) {
    BinaryTree bt;
    bt.inserting(5);
    bt.inserting(3);
    bt.inserting(7);
    bt.inserting(2);
    bt.inserting(4);
    bt.inserting(6);
    bt.inserting(8);
    bt.Inorder();
    cout<<endl;
    bt.Preorder();
    cout<<endl;
    bt.Postorder();
    cout<<endl;
    return 0;
}
