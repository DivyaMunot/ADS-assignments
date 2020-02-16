/*
 * A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data sorted
in ascending/ Descending order. Also find how many maximum comparisons may require for
finding any keyword. Use Binary Search Tree for implementation.
 */

#include <iostream>
#include <cstring>

using namespace std;

typedef struct node
{
	string word, meaning;
	struct node *lf, *rt;
}NODE;

class BST
{
	NODE *root;

public:	BST()
		{
			root = NULL;
		}

		void createBinary();
		void addNewNode();
		void inOrder(NODE *root);
		void preOrder(NODE *root);
		void postOrder(NODE *root);
		NODE* search(NODE *root, string key);
		void update(NODE *root);
		void deletenode(string key);
		void display(NODE *cn);

		NODE* getroot()
		{
			return root;
		}
};

void BST :: createBinary()
{
	int n;
	cout << "\n Enter the number of words : ";
	cin >> n;

	bool flag=0;			//0 for left and 1 for right
	NODE *newnode, *cn, *parent;

	for(int i=0; i<n; i++)
	{
		newnode = new NODE;
		newnode->lf = newnode->rt = NULL;

		cout << "\n Enter the word : ";
		cin >> newnode->word;
		cout << "\n Enter the meaning of the word : ";
		cin >> newnode->meaning;

		if(root == NULL)
			root = newnode;
		else
		{
			cn = root;
			while(cn != NULL)
			{
				parent = cn;
				if(newnode->word < cn->word)
				{
					flag = 0;
					cn = cn->lf;
				}
				else
				{
					flag = 1;
					cn = cn->rt;
				}
			}
			if(flag == 0)
				parent->lf = newnode;
			else
				parent->rt = newnode;
		}

	}
}

void BST :: addNewNode()
{
	if(root == NULL)
		cout << "\n The dictionary is not created. ";
	else
	{
		bool flag=0;			//0 for left and 1 for right
		NODE *newnode, *cn, *parent;
		newnode = new NODE;
		newnode->lf = newnode->rt = NULL;

		cout << "\n Enter the word : ";
		cin >> newnode->word;
		cout << "\n Enter the meaning of the word : ";
		cin >> newnode->meaning;

		cn = root;
		while(cn != NULL)
		{
			parent = cn;
			if(newnode->word < cn->word)
			{
				flag = 0;
				cn = cn->lf;
			}
			else
			{
				flag = 1;
				cn = cn->rt;
			}
		}
		if(flag == 0)
			parent->lf = newnode;
		else
			parent->rt = newnode;
	}
}

void BST :: preOrder(NODE *cn)
{
	if(cn != NULL)
	{
		cout << cn->word << " - " << cn->meaning << "  ";
		preOrder(cn->lf);
		preOrder(cn->rt);
	}
}

void BST :: inOrder(NODE *cn)
{
	if(cn != NULL)
	{
		inOrder(cn->lf);
		cout << cn->word << " - " << cn->meaning << "  ";
		inOrder(cn->rt);
	}
}

void BST :: postOrder(NODE *cn)
{
	if(cn != NULL)
	{
		postOrder(cn->lf);
		postOrder(cn->rt);
		cout << cn->word << " - " << cn->meaning << "  ";
	}
}

NODE* BST :: search(NODE *root, string key)
{
	if(root == NULL || root->word == key)
		return root;
											// Key is greater than cn's data
	if (root->word < key)
		return search(root->rt, key);
											// Key is smaller than cn's data
	    return search(root->lf, key);
}

void BST :: update(NODE *cn)
{
	 cout << "\n Enter the new meaning of the word " << cn->word << " : ";
	 cin >> cn->meaning;
}

void BST :: deletenode(string key)
{
    bool flag=0;
    string word1, meaning1;
    NODE *cn, *parent, *temp;
    cn = root;

    while(cn != NULL)
    {
        if(key < cn->word)
         {
                 parent = cn;
                 cn = cn->lf;
                 flag = 0;
         }
         else if(key > cn->word)
         {
             parent = cn;
             cn = cn->rt;
             flag = 0;
         }
         else
         {
             flag = 1;
             break;
         }
     }
     if(flag == 1)
     {
         if(cn->lf == NULL && cn->rt == NULL)
         {
             if(cn == root)
             {
                 root = NULL;
             }
             else if(cn->word < parent->word)
                 parent->lf = NULL;
             else
                 parent->rt = NULL;

             delete cn;
         }
         else if(cn->lf == NULL && cn->rt != NULL)
         {
             if(cn == root)
             {
                 root = cn->rt;
             }
            else if(cn->word < parent->word)
                 parent->lf = cn->rt;
             else
                 parent->rt = cn->rt;
                 delete cn;
         }
         else if(cn->rt == NULL && cn->lf != NULL)
         {
             if(cn == root)
             {
                 root = cn->lf;
                 //return;
             }
             else if(cn->word < parent->word)
                 parent->lf = cn->lf;
             else
                 parent->rt = cn->lf;
             delete cn;
         }
         else if(cn->lf != NULL && cn->rt != NULL)
         {
             temp = cn->lf;
             while(temp->rt != NULL)
             {
                 temp = temp->rt;
             }
             word1 = temp->word;
             meaning1 = temp->meaning;
             deletenode(temp->word);
             deletenode(temp->meaning);
             cn->word = word1;
             cn->meaning = meaning1;
         }
         else
             cout << "\n Word is not present. ";
     }
}

void BST :: display(NODE *cn)
{
	if(cn != NULL)
	{
		display(cn->lf);
		cout << "\n " << cn->word << " - " << cn->meaning << "\n";
		display(cn->rt);
	}
}

int main()
{
	BST  obj;
	NODE *temp;

	int choice;
	string key;

	do
	{
		cout << "\n ---------------------------------------- ";
		cout << "\n Enter your choice "
				"\n 1. Create Dictionary "
				"\n 2. Add new word "
				"\n 3. Inorder "
				"\n 4. Perorder "
				"\n 5. Postorder "
				"\n 6. Search for a word "
				"\n 7. Update the meaning "
				"\n 8. Delete a word "
				"\n 9. Display the dictionary "
				"\n 10. Exit "
				"\n Here : ";
		cin >> choice;

		switch(choice)
		{
			case 1: obj.createBinary();
				break;

			case 2: obj.addNewNode();
				break;

			case 3: cout << "\n Inorder : ";
					obj.inOrder(obj.getroot());
				break;

			case 4: cout << "\n Preorder : ";
					obj.preOrder(obj.getroot());
				break;

			case 5: cout << "\n Postorder : ";
					obj.postOrder(obj.getroot());
				break;

			case 6: cout << "\n Enter the word to be searched : ";
					cin >> key;
					temp = obj.search(obj.getroot(), key);
					if(temp != NULL)
						cout << "\n" << temp->word << " - " << temp->meaning << "\n";
					else
						cout << "\n Word not found! " << "\n";
				break;

			case 7:	cout << "\n Enter the word whose meaning is to be updated : ";
					cin >> key;
					temp = obj.search(obj.getroot(), key);
					obj.update(temp);
				break;

			case 8: cout << "\n Enter the word to be deleted from the dictionary : ";
					cin >> key;
					obj.deletenode(key);
					cout << "\n The word is deleted. ";
				break;

			case 9: obj.display(obj.getroot());
				break;

			default : cout << "\n ----------------- END ----------------- ";
				break;
		}
	}while(choice < 10);

	return 0;
}
