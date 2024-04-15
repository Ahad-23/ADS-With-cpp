#include<iostream>
#include<string>
using namespace std;
class avl_node
{
    friend class avl_tree;
    int value;
    string word,meaning;
    avl_node *left,*right;
};

class avl_tree
{
    
    public:
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node* balance(avl_node *);
    void insert();
    avl_node* insert(avl_node *, avl_node *);
    void display(avl_node *, int);
    void inorder();
    void preorder();
    void postorder();
    void inorder(avl_node *a);
    void preorder(avl_node *a);
    void postorder(avl_node *a);
    avl_tree()
    {
        avl_node* root=NULL;
    }
};


avl_node* avl_tree :: ll_rotation (avl_node *parent)
{
    avl_node* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
}

avl_node* avl_tree :: rr_rotation (avl_node *parent)
{
    avl_node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node* avl_tree:: lr_rotation (avl_node *parent)
{
    avl_node *temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation(parent);
}


avl_node* avl_tree:: rl_rotation (avl_node *parent)
{
    avl_node *temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

int avl_tree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

int avl_tree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

avl_node* avl_tree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
        temp = ll_rotation (temp);
        else
        temp = lr_rotation (temp);
    }

    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
        temp = rl_rotation (temp);
        else
        temp = rr_rotation (temp);
    }
    return temp;
}

void avl_tree::insert()
{
    char ch;
    do
    {
        avl_node* root=new avl_node();
        avl_node *temp = root;
        cout<<("Enter word");
        cin>>root->word;
        cout<<("Enter it's meaning");
        cin>>root->meaning;
        root=insert(root, temp);
        cout<<("Do you want to enter more words?(Y/N)");
        cin>>ch;
    }
        while(ch == 'Y');
}

avl_node* avl_tree:: insert(avl_node *root, avl_node *temp)
{
    if (root == NULL)
    {
        avl_node* root = new avl_node();
        root->word= temp->word;
        root->meaning= temp->meaning;
        root->left = NULL;
        root->right = NULL;
    return root;
    }
    else if (temp->word<root->word)
    {
        root->left = insert(root->left, temp);
        root = balance (root);
    }
    else if (temp->word >= root->word)
    {
        root->right = insert(root->right, temp);
        root = balance (root);
    }
    return root;
}

void avl_tree::inorder(avl_node *temp) 
{
    if (temp != NULL) 
    {
      inorder(temp->left);
      cout << temp->word << endl;
      cout<< temp->meaning<<endl;
      inorder(temp->right);
    }
}

void avl_tree::preorder(avl_node *temp) 
{
    if (temp != NULL) 
    {
      cout << temp->word << endl;
      cout<< temp->meaning<<endl;
      preorder(temp->left);
      preorder(temp->right);
    }
}

void avl_tree::postorder(avl_node *temp) 
{
    if (temp != NULL) 
    {
      postorder(temp->left);
      postorder(temp->right);
      cout << temp->word << endl;
      cout<< temp->meaning<<endl;
    }
}

int main()
{
    avl_tree a1;
    a1.insert();
}
