#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct node
{
    int w;
    struct node *next;
}NODE;

class Adjacency
{
	NODE *head[10];
	NODE *list[10];
    int G[10][10], nV, nE, visited[10];

public:
    	NODE *nn, *cn;
    	Adjacency()
		{
    		nV = 0;
    		nE = 0;
    		cn = nn = NULL;
    		for(int i=0; i<10; i++)
    			head[i] = NULL;
		}
    	void read_Graph();
    	void addnode(int m,int n);
    	void display_matrix();
    	void display_list();
    	void visit();
    	void DFS(int);
    	void IDFS(int);
    	void BFS(int);
};

void Adjacency :: read_Graph()
{
    cout << "\n Enter number of vertices of the graph : ";
    cin >> nV;
    cout << "\n Enter number of edges of the graph : ";
    cin >> nE;

    int i, j, m, n;
    for(i=1; i<=nV; i++)
    {
        for(j=1; j<=nV; j++)
        {
            G[i][j]=0;
        }
    }

    for(i=1; i<=nE; i++)
    {
    	list[i] = NULL;
    }

    for(i=1; i<=nE; i++)
    {
        cout << "\n Enter initial vertex : ";
        cin >> m;
        cout << " Enter end vertex : ";
        cin >> n;

        G[m][n] = 1;
        G[n][m] = 1;

        addnode(m, n);
        addnode(n, m);

        cout << endl;
    }
}

void Adjacency :: addnode(int m, int n)
{
	cout << "\n Adding edge : " << m << "  " << n;
	nn = new NODE;
	nn->next = NULL;
	nn->w = n;
	if(list[m] == NULL)
	{
		list[m] = nn;
	}
	else
	{
	    for(cn=list[m]; cn->next!=NULL; cn=cn->next);
	    	cn->next = nn;
	}
}

void Adjacency :: display_matrix()
{
	cout << "\n Adjacency Matrix : " << endl;
    int i, j;
    for(i=1; i<=nV; i++)
    {
        for(j=1; j<=nV; j++)
        {
              cout << " " << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Adjacency :: display_list()
{
	cout << "\n Adjacency List : ";

	for(int i=1; i<=nV; i++)
	{
		cout << "\n [" << i << "]";
		for(cn=list[i]; cn!=NULL; cn=cn->next)
		{
			cout << " -> " << cn->w;
		}
	}
	cout << endl;
}

void Adjacency :: visit()
{
	for(int i=0;i<10;i++)
	{
		visited[i]=0;
	}
}

void Adjacency :: DFS(int v)
{
    cout << v << " -> ";
    visited[v-1] = 1;

    for(int i=1; i<=nV; i++)
    {
        if( (G[v][i]==1) && (visited[i-1]==0) )
            DFS(i);
    }
}

void Adjacency :: IDFS(int v)
{
    stack<int> s;
    int i, w;

	visit();

    s.push(v);
    while(!s.empty())
    {
        w = s.top();
        s.pop();
        if(visited[w-1] == 0)
        {
            cout << w << " -> ";
	        visited[w-1] = 1;

	        for(i=nV; i>=1; i--)
	        {
	        	if( (G[w][i]==1) && (visited[i-1]==0) )
	        		s.push(i);
	        }
        }
    }
    cout << endl;
}

void Adjacency :: BFS(int v)
{
    queue<int> q;
    int w, i;

	visit();

    q.push(v);
    while(!q.empty())
    {
        w = q.front();
        q.pop();

        if(visited[w-1] == 0)
        {
            visited[w-1] = 1;
            cout << w << " - ";

            for(i=1; i<=nV; i++)
            {
                if(G[w][i]==1 && visited[i-1]==0)
                    q.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
	Adjacency G1;
    int ch, iV;
    cout << "\n ------------------------------------- ";
    cout << "\n           Graph operations            ";
    do
    {
    	cout << "\n ************************************* ";
    	cout << "\n 1. Enter graph details ";
    	cout << "\n 2. Display graph matrix and list ";
    	cout << "\n 3. DFS traversal(Recursive) ";
    	cout << "\n 4. IDFS traversal(NonRecursive) ";
    	cout << "\n 5. BFS traversal ";
    	cout << "\n 6. Exit ";
        cout << "\n Enter your choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1: G1.read_Graph();
            	break;

            case 2: G1.display_matrix();
            		G1.display_list();
            	break;

            case 3:
            		cout << "\n Enter initial vertex for traversal : ";
                    cin >> iV;
                    G1.visit();
                    cout << "\n DFS : ";
                    G1.DFS(iV);
				break;

             case 4:
				 	 cout << "\n Enter initial vertex for traversal : ";
                     cin >> iV;
                     cout << "\n IDFS : ";
                     G1.IDFS(iV);
				break;

             case 5:
                     cout << "\n Enter initial vertex for traversal : ";
                     cin >> iV;
                     cout << "\n BFS : ";
                     G1.BFS(iV);
                break;

        }
    }while(ch != 6);

    cout << "\n ------------------------------------- ";
    cout << "\n                   END                 ";
    cout << "\n ------------------------------------- ";

    return 0;
}
