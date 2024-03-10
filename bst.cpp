#include<iostream>
#include<string>

using namespace std;
class node
{
 
   string word;
   string meaning;
   node *left;
   node *right;
   friend class binarytree;
};
class binarytree
{
   
   node *root;
   public:
   void bstrootcreate();
   void create_bst(node *root);
   void preordernr(node *root);
   void preordernr();
   void postordernr(node *root);
   void postordernr();
   void inordernr(node *root);
   void inordernr();
   node *copytreerec(node *root);
   node *copytreerec();
   void copytreenonrec(node *root);
   void copytreenonrec();
   void mirrorimage(node *root);
   void mirrorimage();
   void levelnr();
   bool search(node *root,string w);
   void delnode(string w);
 };
 
class queue2
{
   int f = -1;
   int r = -1;
   node *q[20];
   public:
   void insert(node *temp);
   node* remove();
   bool isempty();
   friend class binarytree;
};
   
void queue2 :: insert(node *temp)
{
   
   q[++f] = temp;
}

node* queue2:: remove()
{
   node *temp = q[++r];
   return temp;
}

bool queue2:: isempty()
{
  if(f == r)
  return true;
  else
  return false;
}


void binarytree :: bstrootcreate()
{
   root = new node();
   cout << "Enter Word" << endl;
   cin>>root->word;
   cout << "Enter Meaning Of The Word" << endl;
   cin>>root->meaning;
   root->left = root->right = NULL;
   create_bst(root);
}

void binarytree :: create_bst(node *root)
{
   char ch='Y';
   int flag;

   while(ch=='Y')
   {
      node *curr = new node();
      node *temp = root;
      flag = 0;
      cout<<"Enter Word : "<<endl;
      cin>>curr->word;
      cout << "Enter Meaning Of The Word" << endl;
      cin>>curr-> meaning;
      curr->left = curr->right = NULL;
      while(flag == 0)
      {
         
         if(curr->word.compare(temp->word) <= 0)   // currword <= temp->word
         {
            if(temp->left == NULL)
            {
               temp->left = curr;
               flag = 1;
               break;
            }
            else
            {
               temp = temp->left;
               flag = 0;
            }
         }
         else
         {
            if(temp->right == NULL)
            {
               temp->right = curr;
               flag = 1;
               break;
            }
            else
            {
               temp = temp->right;
               flag = 0;
            }
         }        
      }
      cout<<"Do you want to insert a new Node? (Y/N)"<<endl;
      cin>>ch;
  }
}
bool binarytree :: search(node *root, string w)
{
  if(root ==NULL)
  {
    return false;
  }
 
 
    if(root->word.compare(w) == 0)
    {
      return true;
    }
    if(root->word.compare(w) < 0)
    {
      return search(root->right,w);
    }
    else
    {
      return search(root->left,w);
    }
  }
 
 
 void binarytree :: delnode(string w)
{
    bool b = search(root,w);
    node *temp = root;
    node *parent = NULL;
    if(b==false)
    {
        cout<<"NODE NOT FOUND. DELETE A NODE WHICH IS ACTUALLY PRESENT.";
    }
    else
    {
        cout<<"NODE HAS BEEN FOUND.\n";
        cout<<w<<" HAS BEEN DELETED.";
        if(root->word.compare(w) != 0)
        {
        temp = root;
        while(temp!=NULL)
        {
            if(temp->word.compare(w) == 0)
                break;
            else if(temp->word.compare(w) > 0)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                parent = temp;
                temp = temp->right;        
            }
        }
        if(temp->left == NULL && temp->right == NULL)
        {
            if(parent->right == temp)
            {
                parent->right = NULL;
            }
            else
            {
                parent->left = NULL;
            }
            delete temp;
        }
        else if(temp->left == NULL && temp->right != NULL)
        {
            if(parent->right == temp)
            {
                parent->right = temp->right;
            }
            else
            {
                parent->left = temp->right;
            }
            delete temp;
        }
        else if(temp->left != NULL && temp->right == NULL)
        {
            if(parent->right == temp)
            {
                parent->right = temp->left;
            }
            else
            {
                parent->left = temp->left;
            }
            delete temp;
        }
        else
        {
            node *s = temp->left;
            node *r = temp->right;
            if(parent->right == temp)
            {
                parent->right = r;
            }
            else
            {
                parent->left = r;
            }
            while(r->left!=NULL)
            {
                r = r->left;
            }
            r->left = s;
            temp->right = NULL;
            delete temp;   
        }  
      }   
    
    else
    {   
       if(temp->left == NULL && temp->right == NULL)
        {
           root= NULL;
           delete root;
        }
        else if(temp->left == NULL && temp->right != NULL)
        {
            root = temp->right;
            temp->right = NULL;
            delete temp;
        }
        else if(temp->left != NULL && temp->right == NULL)
        {
            root = temp->left;
            temp->left = NULL;
            delete temp;
        }
        else
        {
            node *s = temp->left;
            node *r = temp->right;
            root = r;
            while(r->left!=NULL)
            {
                r = r->left;
            }
            r->left = s;
            temp->right = NULL;
            delete temp;   
         }
           
        }
    }
}
void binarytree :: preordernr(node *root)
{
       if(root!=NULL)
  {
   
    cout<<"Word:" <<root->word<< "\n";
    cout<<"Meaning:" <<root->meaning<< "\n";
    preordernr(root->left);
    preordernr(root->right);
   
  }
}
void binarytree :: preordernr()
{
     preordernr(root);
}

void binarytree :: postordernr(node *root)
{
      if(root!=NULL)
  {
   
    postordernr(root->left);
    postordernr(root->right);
    cout<<"Word ->" <<root->word<< "\n";
    cout<<"Meaning ->" <<root->meaning<< "\n\n";
  }
}
void binarytree :: postordernr()
{
    postordernr(root);
}

void binarytree :: inordernr(node *root)
{
   
       if(root!=NULL)
  {
   
    inordernr(root->left);
    cout<<"Word ->" <<root->word<< "\n";
    cout<<"Meaning ->" <<root->meaning<< "\n\n";
    inordernr(root->right);
 
  }
     
}

node* binarytree :: copytreerec(node *root)
{
    node *temp = NULL;
    if(root !=NULL)
    {
        temp = new node();
        temp->word = root->word;
        temp->meaning= root->meaning;
        temp->left = copytreerec(root->left);
        temp->right = copytreerec(root->right);
    }
    return temp;
}

node* binarytree :: copytreerec()
{
   node *t = copytreerec(root);
   return t;
}
       

void binarytree :: inordernr()
{
     inordernr(root);
}

void binarytree :: mirrorimage(node *root)
{
   node* t1;
   if(root!=NULL)
   {
     t1 = root->left;
     root->left = root->right;
     root->right = t1;
     mirrorimage(root->left);
     mirrorimage(root->right);
   }
}
void binarytree :: mirrorimage()
{
   mirrorimage(root);
}
 
void binarytree :: levelnr()
{
   queue2 Q;
   node* t;
   Q.insert(root);
   while(!Q.isempty())
   {
      t = Q.remove();
     cout<<"Word " <<t->word<< "\n";
     cout<<"Meaning" <<t->meaning<< "\n\n";
     
      if(t->left !=NULL)
      {
        Q.insert(t->left);
      }
      if(t->right!=NULL)
      {
        Q.insert(t->right);
      }
   }
}
     
 int main()  
{
   int ch=1;
   binarytree b1;
   node *n1;
   string w;
   while(ch<9 && ch>0)
   {
      cout<<"Binary Search Tree Operations.\n1 = Create.\n2 = Inorder.\n3 = Preorder.\n4 = Postorder.\n5 = LevelWise.\n6 = Copy Recursively.\n7 = Mirror Image. \n8 = Delete Node.\nPress Any Other Number To Exit."<<endl;
      cin>>ch;
      cout<<"\n\n";
      switch(ch)
      {
         case 1 : b1.bstrootcreate();
                  break;
         case 2 : cout<<"Inorder Form Is :"<<endl;
                  b1.inordernr();
                  break;
         case 3 : cout<<"Preorder Form Is :"<<endl;
                  b1.preordernr();
                  break;
         case 4 : cout<<"Postorder Form Is :"<<endl;
                  b1.postordernr();
                  break;
         case 5:  cout<<"LevelWise Form Is :"<<endl;
                  b1.levelnr();
                  break;                      
         case 6:  cout<<"Tree Copied Recursively."<<endl;
                  n1 = b1.copytreerec();
                  b1.inordernr(n1);
                  break;
         case 7:  cout<<"Mirror Image Created. Call a traversal Function to check."<<endl;
                  b1.mirrorimage();
                  break;
         case 8:  cout<<"Enter Word to Delete."<<endl;
                  cin>>w;
                  b1.delnode(w);
                  break;                      
         default : cout<<"Program Exitted."<<endl;  
                  break;      
       }  
}
}