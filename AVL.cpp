#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node *lf,*rt;
};

class AVL
{
	node* root;
public:
	AVL()
	{
		root=NULL;
	}
	node* insert_node(node* root,int value);
	node* balance(node *T);
	int height(node *temp);
	int B_Factor(node *temp);
	node* rotate_right(node *parent);
	node* rotate_left(node *parent);
	node* RL(node *parent);
	node* RR(node *parent);
	node* LR(node *parent);
	node* LL(node *parent);
	void inorder(node *tree);
	void preorder(node *tree);
	void postorder(node *tree);
	void display(node *ptr, int level);
	node* getroot()
	{
		return root;
	}
	void setroot(node *ro)
	{
		root=ro;
	}
};

node* AVL::insert_node(node* root,int value)
{
	if(root==NULL)
	{
	     root=new node;
	     root->data=value;
	     root->lf=root->rt=NULL;
	     return root;
	}
	else if(value<root->data)
	{
		root->lf=insert_node(root->lf,value);
		root=balance(root);
	}
	else if(value>root->data)
	{
		root->rt=insert_node(root->rt,value);
		root=balance(root);
	}
	cout<<"\n INSERTION DONE!!!!!!!!";
	return root;
}

int AVL::height(node* temp)
{
	int h=0;
	if(temp!=NULL)
	{
		int l_height=height(temp->lf);
		int r_height=height(temp->rt);
		int max_height=max(l_height,r_height);
		h=max_height+1;
	}
	return h;
}
int AVL::B_Factor(node* temp)
{
	int l_height=height(temp->lf);
	int r_height=height(temp->rt);
	int b_factor=l_height-r_height;
	return b_factor;
}

node* AVL::rotate_right(node* parent)
{
	node* temp;
   	temp=parent->lf;
   	parent->lf=temp->rt;
    	temp->rt=parent;
}

node* AVL::rotate_left(node* parent)
{
	node* temp;
	temp=parent->rt;
	parent->rt=temp->lf;
	temp->lf=parent;

	return temp;

}
node* AVL::LL(node* parent)
{
	node *temp;
	temp=rotate_right(parent);
    	return temp;
}
node* AVL::RR(node* parent)
{
	node *temp;
	temp=rotate_left(parent);
	return temp;
}
node* AVL::LR(node* parent)
{
	node* temp;
	temp=parent->lf;
	parent->lf=rotate_left(temp);
	temp=rotate_right(parent);
   	return temp;
}
node* AVL::RL(node* parent)
{
	node* temp;
	temp=parent->rt;
	parent->rt=rotate_right(temp);
	temp=rotate_left(parent);

	return temp;
}

node* AVL::balance(node* T)
{
	int bal_factor=B_Factor(T);
	if(bal_factor>1)
	{
		if(B_Factor(T->lf)>0)
		{
			T=LL(T);
		}
		else
			T=LR(T);
	}
	else if(bal_factor<-1)
	{
		if(B_Factor(T->rt)>0)
			T=RL(T);
		else
			T=RR(T);
	}
	return T;
}

void AVL::display(node *ptr, int level)

{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->rt, level + 1);
        cout<<"\n";
        if (ptr == root)
	        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->lf, level + 1);
    }
}

void AVL::inorder(node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->lf);
    cout<<tree->data<<"  ";
    inorder (tree->rt);

}

void AVL::preorder(node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->lf);
    preorder (tree->rt);
}


void AVL::postorder(node *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->lf );
    postorder ( tree ->rt );
    cout<<tree->data<<"  ";
}

int main()
{
	AVL obj;
	node *ro=NULL;
	int ch,value;
	do
	{
		cout<<"\n1.ADD NODE";
		cout<<"\n2.DISPLAY TREE";
		cout<<"\n3.INORDER TRAVERSAL";
		cout<<"\n4.PREORDER TRAVERSAL";
		cout<<"\n5.POSTORDER TRAVERSAL";
		cout<<"\n6.EXIT";
		cin>>ch;
		switch(ch)
		{
		case 1:
			    cout<<"\n Enter Value you want to enter: ";
			    cin>>value;
			    ro=obj.insert_node(obj.getroot(),value);
			    obj.	setroot(ro);
			    break;
		case 2:
			    if (obj.getroot() == NULL)
            		    {
		                cout<<"Tree is Empty"<<endl;
		                continue;
            		    }
		            cout<<"Balanced AVL Tree:"<<endl;
		            obj.display(obj.getroot(), 1);
		            break;
	        case 3:
          		   cout<<"Inorder Traversal:"<<endl;
          		   obj.inorder(obj.getroot());
         		   cout<<endl;
         		   break;
       		case 4:
         		   cout<<"Preorder Traversal:"<<endl;
         		   obj.preorder(obj.getroot());
         		   cout<<endl;
          		  break;
       		case 5:
         		   cout<<"Postorder Traversal:"<<endl;
         		   obj.postorder(obj.getroot());
         		   cout<<endl;
          		  break;
          	case 6:
          		 break;
		}

	}while(ch!=6);
	return 0;
}
