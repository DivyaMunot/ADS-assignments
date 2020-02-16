#include <iostream>

using namespace std;

class graph
{
    int G[10][10] , nV , visited[10];
public:
    void readGraph();
    void prims();
    void iniVisited()
    {
        for(int i =0;i<10;i++)
            visited[i] = 0;
    }
};

void graph :: readGraph()
{

    int sV , eV , cost , ed;

    for(int i =0;i<10;i++)
        for(int j=0;j<10;j++)
            G[i][j] = 0;

    cout << "Enter Number of Vertices:";
    cin >> nV;
    cout << "\nEnter no. of edges:";
    cin >> ed;

    for(int i=0;i<ed;i++)
    {
    cout << "\nNow Enter the starting vertex of the edge:";
    cin >> sV;
    cout << "\nNow Enter the ending vertex of the edge:";
    cin >> eV;
    cout << "\nNow Enter the Weight of the edge:";
    cin >> cost;

    G[sV][eV] = cost;
    G[eV][sV] = cost;
    }
cout << "\nThe Cost Matrix is:" << endl;
    for(int i =0;i<nV;i++)
        {
            for(int j=0;j<nV;j++)
            {
                cout << G[i][j] << " ";
            }
    cout << endl;
    }
}


void graph :: prims()
{
    int edge = 0 , x , y , i , j , start;
     int min , mins = 0;

    iniVisited();

    cout << "\nEnter the the vertex for Prims Algo:";
    cin >> start;

    cout << "v1" << "  v2 \tCost" << endl;

    visited[start] = 1;

    while(edge < nV-1)
    {
        min = 999;
        for(i=0;i<nV;i++)
        {
            if(visited[i] == 1)
            {
                for(j=0;j<nV;j++)
                {
                    if(visited[j] == 0 && G[i][j] != 0)
                    {
                        if(min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

        }
        cout << x << " - "  << y << "\t" << G[x][y] << endl;
        visited[y] = 1;
        mins = mins + G[x][y];
        edge++;
    }

    cout << "\nCost of Minimum Spanning tree is:" << mins;
}

int main()
{
    graph g;
    g.readGraph();
    g.prims();
    return 0;
}
