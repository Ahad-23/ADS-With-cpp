#include <iostream>
using namespace std;
class tbtnode {
    char data;
    bool rbit;
    bool lbit;
    tbtnode *leftc;
    tbtnode *rightc;
    tbtnode(){
        lbit = rbit = false;
    }
    friend class tbt;
};
class tbt {
    tbtnode *head;
    public:
    tbt() {
        head = new tbtnode();
        head->rbit = head->lbit = true;
        head->leftc = head->rightc = head;
    }
    void create(){
        tbtnode *root = new tbtnode();
        cout << "Enter data of root node";
        cin >> root->data;
        head->lbit = 1;
        head->leftc = root;
        root->rightc = head;
        root->leftc = head;
        char ch1;

        do {
            tbtnode *temp = root;
            tbtnode *newnode = new tbtnode();
            bool flag = false;

            while (flag == false)
            {
                char ch;
                cout << "Do you want to enter data to left or to right (l/r)";
                cin >> ch;
                cout << "Enter data";
                cin >> newnode->data;
                if (ch == 'l')
                {
                    if (temp->lbit == 0)
                    {
                        newnode->rightc = temp;
                        newnode->leftc = temp->leftc;
                        temp->leftc = newnode;
                        temp->lbit = 1;
                        flag = true;
                    }
                    else
                    {
                        temp = temp->leftc;
                    }
                }
                if (ch == 'r'){
                    if (temp->rbit == 0)
                    {
                        newnode->leftc = temp;
                        newnode->rightc = temp->rightc;
                        temp->rightc = newnode;
                        temp->rbit = 1;
                        flag = true;
                    }
                    else
                    {
                        temp = temp->rightc;
                    }
                }
                cout << "Do you want to enter more nodes (y/n)";
                cin >> ch1;
                }
            }while (ch1 == 'y');

    }
    void inorder(){
        tbtnode *temp = head;
        while(1){
            temp = inordersucc(temp);
            if(temp == head) break;
            cout << temp->data;
        }
    }

    tbtnode* inordersucc(tbtnode* temp){
        tbtnode *x = temp->rightc;
        if (temp->rbit== 1){
            while (x->lbit==1)
            {
                x = x->leftc;
            }}
        return x;   
    }
    void preorder(){
        tbtnode* temp = head->leftc;
        while(temp!= head){
            cout << temp->data;
            while(temp->lbit != 0){
                temp = temp->leftc;
                cout << temp->data;

            }
            while(temp->rbit == 0){
                temp = temp->rightc;
            }
            temp = temp->rightc;
        }
    }
};

int main(){
    tbt t;
    t.create();
    t.inorder();
    t.preorder();

}