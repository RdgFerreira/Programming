#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <ostream>
#include <list>
#include<bits/stdc++.h>

#define COUNT 10
using namespace std;

struct node {
    struct node *left;
    int data;
    int height;
    struct node *right;

};

class AVL
{
private:
    
public:
    struct node * root;
    AVL(){
        this->root = NULL;

    }

    int calheight(struct node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(struct node *n){
        if(n->left && n->right){
            return n->left->height - n->right->height; 
        }
        else if(n->left && n->right == NULL){
            return n->left->height; 
        }
        else if(n->left== NULL && n->right ){
            return -n->right->height;
        }
        return 0;
    }

    struct node * llrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp; 
    }


    struct node * rrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp; 
    }


    struct node * rlrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        
        return tp2; 
    }

    struct node * lrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        return tp2; 
    }

    struct node* insert(struct node *r,int data){
        
        if(r==NULL){
            struct node *n;
            n = new struct node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 
            return r;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

 
    struct node * deleteNode(struct node *p,int data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        struct node *t;
        struct node *q;
        if(p->data < data){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data > data){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }                  
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }

        
        return p;
    }

     struct node* inpre(struct node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    struct node* insuc(struct node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }
    void levelorder_newline(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;            
        }
        levelorder_newline(this->root);
    }

    void levelorder_newline(struct node *v){
        queue <struct node *> q;
        struct node *cur;
        q.push(v);
        q.push(NULL);      

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur == NULL && q.size()!=0){
                cout<<"\n";
                
                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<" "<<cur->data;

                if (cur->left!=NULL){
                q.push(cur->left);
                }
                if (cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            
            
        }
    }

    // Function to print binary tree in 2D
    // It does reverse inorder traversal
    void print2DUtil(node *root, int space)
    {
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print2DUtil(root->right, space);

        // Print current node after space
        // count
        cout<<endl;
        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<<root->data<<"\n";

        // Process left child
        print2DUtil(root->left, space);
    }

    // Wrapper over print2DUtil()
    void print2D()
    {
        // Pass initial space count as 0
        print2DUtil(root, 0);
    }

    void printBinaryTree(node* root, int space = 0, int height = 10)
    {
        // Base case
        if (root == nullptr) {
            return;
        }
    
        // increase distance between levels
        space += height;
    
        // print right child first
        printBinaryTree(root->right, space);
        cout << endl;
    
        // print the current node after padding with spaces
        for (int i = height; i < space; i++) {
            cout << ' ';
        }
        cout << root->data;
    
        // print left child
        cout << endl;
        printBinaryTree(root->left, space);
    }

    void printBTree() {
        printBinaryTree(root, 0, 10);
    }

    void printBinaryTree2(node *p)
    {
        int height = p->height * 2;
        for (int i = 0 ; i < height; i ++) {
            printRow(p, height, i);
        }
    }

    void printRow(const node *p, const int height, int depth)
    {
        vector<int> vec;
        getLine(p, depth, vec);
        cout << setw((height - depth)*2); // scale setw with depth
        bool toggle = true; // start with left
        int placeholder = 31;
        if (vec.size() > 1) {
                for (int v : vec) {
                        if (v != placeholder) {
                                if (toggle)
                                        cout << "/" << "   ";
                                else
                                        cout << "\\" << "   ";
                        }
                        toggle = !toggle;
                }
                cout << endl;
                cout << setw((height - depth)*2);
        }
        for (int v : vec) {
                if (v != placeholder)
                        cout << v << "   ";
        }
        cout << endl;
    }

    void getLine(const node *root, int depth, vector<int>& vals)
    {
        int placeholder = 31;
        if (depth <= 0 && root != nullptr) {
                vals.push_back(root->data);
                return;
        }
        if (root->left != nullptr)
                getLine(root->left, depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back(placeholder);
        if (root->right != nullptr)
                getLine(root->right, depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back(placeholder);
    }

    void printBTree2() {
        printBinaryTree2(root);
    }


    void printBTree3()
    {
        int i = 0;
        while (i <= root->height){
            printlv(i);
            i++;
            cout << endl;
        }
    }

    void printlv(int n){
        node* temp = root;
        int val = pow(2, root->height -n+2);
        cout << setw(val) << "";
        dispLV(temp, n, val);
    }

    void dispLV(node*p, int lv, int d)
    {
        int disp = 2 * d;
        if (lv == 0){
            if (p == NULL){

                cout << " x ";
                cout << setw(disp -3) << "";
                return;
            }
            else{
                int result = ((p->data <= 1) ? 1 : log10(p->data) + 1);
                cout << " " << p->data << " ";
                cout << setw(disp - result-2) << "";
            }
        }
        else
        {
            if (p == NULL&& lv >= 1){
                dispLV(NULL, lv - 1, d);
                dispLV(NULL, lv - 1, d);
            }
            else{
                dispLV(p->left, lv - 1, d);
                dispLV(p->right, lv - 1, d);
            }
        }
    }

    void postorder(node* p, int indent)
    {
        if(p != NULL) {
            if(p->right) {
                postorder(p->right, indent+4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->data << "\n ";
            if(p->left) {
                std::cout << std::setw(indent) << ' ' <<" \\\n";
                postorder(p->left, indent+4);
            }
        }
    }

    void printBTree4() {
        postorder(root, 31);
    }

    void visualize(AVL b) {
        cout << "================================================================================================================" << endl;
        b.printBTree();
        cout << "================================================================================================================" << endl;
        b.print2D();
        cout << "================================================================================================================" << endl;
        // b.printBTree2();
        b.printBTree4();
        cout << "================================================================================================================" << endl;
        b.printBTree3();
        cout << "================================================================================================================" << endl;
    }


    ~AVL(){

    }
};


int main() {

    AVL b;
    int c,x;
    int n = 7;
    int v[n] = {4,2,3,6,7,1,5};
    for(int i: v) b.root = b.insert(b.root,i);
    b.visualize(b);

    do{
        cout<<"\n1.Display levelorder on newline";
        cout<<"\n2.Insert";
        cout<<"\n3.Delete\n";
        cout<<"\n0.Exit\n";
        cout<<"\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
            b.levelorder_newline();
            cout << endl << endl;
            b.visualize(b);           // to print the tree in level order
            break;
                  
        case 2:
            cout<<"\nEnter no. ";
            cin>>x;
            b.root = b.insert(b.root,x);
            break;
        
        case 3:
            cout<<"\nWhat to delete? ";
            cin>>x;
            b.root = b.deleteNode(b.root,x);
            break;
            
        case 0:
            break;
        }

     } while(c!=0);

     return 0;
  
}