#include <iostream>
using namespace std;

class treenode // create a class for single node of tree
{
  char data;
  treenode *left;
  treenode *right;
  friend class tree;
};

class stack // creating a stack class instead of using the default class as
            // instructed by the professor
{
  int top;
  treenode *data[30];
  friend class tree;

public:
  stack() { top = -1; }

  void push(treenode *temp) {
    top++;
    data[top] = temp;
  }

  treenode *pop() {
    if (!empty()) {
      treenode *ele = data[top];
      top--;
      return ele;
    } else
      return nullptr;
  }

  bool empty() {
    if (top < 0)
      return true;
    else
      return false;
  }
};

class tree // creating a class for tree
{
  treenode *root;

public:
  tree() // initailizing root to null
  {
    root = NULL;
  }

  // creating a tree recursively
  void create_r() // initializing root and driver function for recursive
                  // function call
  {
    root = new treenode();
    cout << "Enter Data To Be Put In Root" << endl;
    cin >> root->data;
    root->left = root->right = NULL;
    create_r(root);
  }

  void create_r(treenode *root) {
    char ch;
    treenode *ptr;
    cout << "Do You Want To Attach Node on Left or Right (L/R) " << endl;
    cin >> ch;
    if (ch == 'L') {
      ptr = new treenode();
      cin >> ptr->data;
      ptr->left = ptr->right = NULL;
      root->left = ptr;
      create_r(ptr);
    }

    if (ch == 'R') {
      ptr = new treenode();
      cin >> ptr->data;
      ptr->left = ptr->right = NULL;
      root->right = ptr;
      create_r(ptr);
    } else
      cout << "Invalid Input" << endl;
  }

  // creating a tree non-recursively
  void create_nr() {
    treenode *temp;
    char ch;

    if (root == NULL) {
      root = new treenode();
      cout << "Enter Data To Be Put In Root" << endl;
      cin >> root->data;
      root->left = root->right = NULL;
    }

    do {
      temp = root;
      int flag = 0;

      while (flag == 0) {
        cout << "Do You Want To Attach Node on Left or Right (L/R) " << endl;
        cin >> ch;

        if (ch == 'L') {
          if (temp->left == NULL) {
            temp->left = new treenode();
            cout << "Enter Data For Left Child" << endl;
            cin >> temp->left->data;
            temp->left->left = temp->left->right = NULL;
            flag = 1;
          }
          temp = temp->left;
        } else if (ch == 'R') {
          if (temp->right == NULL) {
            temp->right = new treenode();
            cout << "Enter Data For Right Child" << endl;
            cin >> temp->right->data;
            temp->right->left = temp->right->right = NULL;
            flag = 1;
          }
          temp = temp->right;
        }
      }

      cout << "Do You Want To Continue (Y/N) " << endl;
      cin >> ch;

    } while (ch == 'Y');
  }

  // postorder traversal recursively
  void postorder() { postorder(root); }

  void postorder(treenode *temp) {
    if (temp != NULL) {
      postorder(temp->left);
      postorder(temp->right);
      cout << temp->data << endl;
    }
  }

  // inorder traversal recursively
  void inorder() { inorder(root); }
  void inorder(treenode *temp) {
    if (temp != NULL) {
      inorder(temp->left);
      cout << temp->data << endl;
      inorder(temp->right);
    }
  }

  // preorder traversal recursively
  void preorder() { preorder(root); }

  void preorder(treenode *temp) {
    if (temp != NULL) {
      cout << temp->data << endl;
      preorder(temp->left);
      preorder(temp->right);
    }
  }

  // inorder traversal non-recursively
  void inorder_nr() {
    treenode *temp = root;
    stack s;
    while (1) {
      while (temp != NULL) {
        s.push(temp);
        temp = temp->left;
      }
      if (s.empty())
        break;

      temp = s.pop();
      cout << temp->data << endl;
      temp = temp->right;
    }
  }

  // preorder traversal non-recursively
  void preorder_nr() {
    treenode *temp = root;
    stack s;
    while (1) {
      while (temp != NULL) {
        cout << temp->data << endl;
        s.push(temp);
        temp = temp->left;
      }
      if (s.empty())
        break;

      temp = s.pop();

      temp = temp->right;
    }
  }

  // postorder traversal non-recursively
  void postorder_nr() {
    treenode *temp = root;
    stack s;
    while (1) {
      while (temp != NULL) {
        s.push(temp);
        temp = temp->left;
      }
      if (s.data[s.top]->right == NULL) {
        temp = s.pop();
        cout << temp->data << endl;
      }

      while (!s.empty() && s.data[s.top]->right == temp) {
        temp = s.pop();
        cout << temp->data << endl;
      }

      if (s.empty())
        break;

      temp = s.data[s.top]->right;
    }
  }
};

int main() {
  tree bt;
  int create_choice;
  cout << "Enter 1 to create tree recursively,2 to create non-recursively"
       << endl;
  cin >> create_choice;

  switch (create_choice) {
  case 1:
    bt.create_r();
    break;
  case 2:
    bt.create_nr();
    break;
  default:
    cout << "Invalid Input" << endl;
    break;
  }

  int trav_choice;
  cout << "Enter 1 to traverse tree recursively,2 to traverse non-recursively"
       << endl;
  cin >> trav_choice;
  switch (trav_choice) {
  case 1:
    cout << "Preorder Traversal" << endl;
    bt.preorder();
    cout << "Inorder Traversal" << endl;
    bt.inorder();
    cout << "Postorder Traversal" << endl;
    break;
  case 2:
    cout << "Inorder Traversal Non recursive" << endl;
    bt.inorder_nr();
    cout << "Preorder Traversal Non recursive" << endl;
    bt.preorder_nr();
    cout << "Postorder Traversal Non recursive" << endl;
    bt.postorder_nr();
  }

  return 0;
}