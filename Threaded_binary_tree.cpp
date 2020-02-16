#include <iostream>

using namespace std;

struct node
{
    int data;
    bool lch, rch;
    node *left, *right;
};

class TBT
{
    node *root;

public:
        TBT()
        {
            root = new node;
            root->left = root->right = root;
            root->lch = root->rch = 0;
        }

        void create_TBT();
        void insert_node(node *parent , int LR);
        void inorder();
        node* leftmost(node *cn);
};

void TBT :: create_TBT()
{
    cout << "\n Enter -1 if the node doesn't exist. ";
    cout << "\n Enter the root : ";
    insert_node(root, 1);                       //1 for left child and 0 for right child
}

void TBT :: insert_node(node *parent, int LR)
{
    int d;
    cout << "\n Enter the value : ";
    cin >> d;

    if(d == -1)
        return;

    node *nn;
    nn = new node;
    nn->data = d;

    if(LR == 1)                                 //entering left child
    {
        nn->lch = parent->lch;
        nn->left = parent->left;
        nn->right = parent;
        nn->rch = 0;
        parent->lch = 1;
        parent->left = nn;
    }
    else if(LR == 0)                            //entering right child
    {
        nn->rch = parent->rch;
        nn->right = parent->right;
        nn->left = parent;
        nn->lch = 0;
        parent->rch = 1;
        parent->right = nn;
    }

    cout << "\n Enter left child of " << nn->data << " : ";
    insert_node(nn, 1);

    cout << "\n Enter right child of " << nn->data << " : ";
    insert_node(nn, 0);
}

node *TBT ::leftmost(node *cn)
{
    while(cn->lch == 1)
    {
        cn = cn->left;
    }
    return (cn);
}

void TBT :: inorder()
{
    node *cn;
    cn = root->left;
    while(cn != root)
    {
        cn = leftmost(cn);
        cout << " " << cn->data << " ";
        while(cn->rch==0 && cn->right!=root)
        {
            cn = cn->right;
            cout << " " << cn->data << " ";
        }
        cn = cn->right;
    }
}

int main()
{
    TBT obj;
    int ch;

    do
    {
        cout << "\n ---------------------------------------- ";
        cout << "\n Enter your choice "
                "\n 1. Create TBT. "
                "\n 2. Inorder display. "
                "\n 3. Exit. "
                "\n Here : ";
        cin >> ch;

        switch(ch)
        {
            case 1: obj.create_TBT();
                break;

            case 2: obj.inorder();
                break;

            case 3:
                break;

            default : cout << "\n Invalid choice! ";
                break;
        }
    }while(ch != 3);

    cout << "\n ---------------------------------------- ";
    cout << "\n                     END                  ";
    cout << "\n ---------------------------------------- ";

    return 0;
}
