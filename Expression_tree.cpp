#include <iostream>

using namespace std;

typedef struct node
{
    char data;
    node *left, *right;
}NODE;

class stack
{
    NODE *st[10];

public: int top;

        stack()
        {
            top = -1;
            for(int i=0; i<10; i++)
                st[i] = 0;
        }

        void push(NODE *a)
        {
            top++;
            st[top] = a;
        }

        NODE* pop()
        {
            NODE *b;
            b = st[top];
            top--;
            return b;
        }

        bool isempty()
        {
            if(top == -1)
                return 1;
            else
                return 0;
        }
};

class expression
{
    NODE *root;

public: expression()
        {
            root = NULL;
        }

        int isOperand(char a)
        {
            char b = a;
            if(b=='*' || b=='-' || b=='+' || b=='/')
            {
                return 0;
            }
            else
                return 1;
        }

        int priority(char exp)
        {
            if(exp=='*' || exp == '/')
                return 2;
            else
                return 1;
        }

        void buildtree()
        {
            stack s1,s2;
            char exp[20];
            NODE *opr, *opt1, *opt2, *nn;

            cout << "\n Enter the exp : ";
            cin >> exp;

            for(int i=0; exp[i]!='\0'; i++)
            {
                if(isOperand(exp[i]))
                {
                    nn = new NODE;
                    nn->data = exp[i];
                    nn->right = nn->left = NULL;
                    s1.push(nn);
                }
                else
                {
                    if(s2.isempty())
                    {
                        nn = new NODE;
                        nn->data = exp[i];
                        nn->right = nn->left = NULL;
                        s2.push(nn);
                    }
                    else
                    {
                        while(s2.top >= priority(exp[i]))
                        {
                            opr = s2.pop();
                            opt1 = s1.pop();
                            opt2 = s1.pop();
                            opr->left = opt1;
                            opr->right = opt2;
                            s1.push(opr);
                        }
                        nn = new NODE;
                        nn->data = exp[i];
                        nn->left = nn->right = NULL;
                        s2.push(nn);
                    }
                }
            }
			while(!s2.isempty())
			{
				opr = s2.pop();
				opt1 = s1.pop();
				opt2 = s1.pop();
				opr->left = opt1;
				opr->right = opt2;
				s1.push(opr);
			}
			root = s1.pop();
		}
};

int main()
{
    expression obj;
    obj.buildtree();
}
