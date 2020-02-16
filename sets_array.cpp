#include <iostream>
#include <cstring>

using namespace std;

class set
{
	int N;
	int data[20];

public:
	void accept();                      //Function to accept no. of data
	int funion(set, set);               //Function to find union
    void intersect(set, set);           //Function to find intersection
    void diff(set, set);                //Function to find difference
};

void set :: accept()
{
	cout << "\n Enter total no of elements : ";
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cout << " Enter element : ";
		cin >> data[i];
	}
}

int set :: funion(set a, set b)
{
    int index = a.N;
    int flag;
    int i, j;

    cout << "{ ";
	for(i=0; i<a.N; i++)
	{
		data[i] = a.data[i];
		cout << data[i] << " ";
	}

	for(i=0; i<b.N; i++)
	{
	    flag = 0;
		for(j=0; j<a.N; j++)
		{
			if(b.data[i] == a.data[j])
			{
				flag=1;
				break;
			}
        }

		if(flag == 0)
        {
			data[index] = b.data[i];
            cout << data[index] << " ";
            index++;
        }
    }
       cout << "}" << endl;

       return index;
}

void set :: intersect(set a, set b)
{
    int i, j, k;
    k=0;
    cout << "{ ";
    for(i=0; i<a.N; i++)
    {
        for(j=0; j<b.N; j++)
        {
            if(a.data[i] == b.data[j])
            {
                data[k] = a.data[i];
                cout << data[k] << " ";
                k++;
            }
        }
    }
    cout << "}" << endl;
}

void set :: diff(set a, set b)
{
    int i, j, k, diff, flag;
    k=0;
    flag=0;

    cout << "{ ";
    for(i=0; i<a.N; i++)
    {
        flag=0;

        for(j=0; j<b.N; j++)
        {
            if(a.data[i] == b.data[j])
            {
                flag=1;
                break;
            }
        }

        if(flag == 0)
        {
            data[k] = a.data[i];
            cout << data[k] << " ";
            k++;
        }
    }
    cout << "}" << endl;
}

int main()
{
	set A_obj, B_obj, union_obj, inter_obj, diff_obj;
    int m=0;
    int n=0, ch;

    do
    {
    	cout << "\n ------------------------------------ ";
    	cout << "\n Enter your choice : "
    			"\n 1. Accept. "
    			"\n 2. Union. "
    			"\n 3. Intersection. "
    			"\n 4. Only in set A. "
    			"\n 5. Only in set B. "
    			"\n 6. Not in any set. "
    			"\n 7. Exit. ";
    	cin >> ch;

    	switch(ch)
    	{
    		case 1: cout << "\n Enter total number of data : ";
    	    		cin >> n;

    	    		cout << "\n Enter data for set A : ";
    	    		A_obj.accept();

    	    		cout << "\n Enter data for set B : ";
    	    		B_obj.accept();
    	    	break;

    		case 2: cout << "\n Union of set A and set B : ";
    	    		m = union_obj.funion(A_obj, B_obj);
    	    	break;

    		case 3:	cout << "\n Intersection of set A and set B : ";
    	    		inter_obj.intersect(A_obj, B_obj);
    	    	break;

    		case 4: cout << "\n Set A elements : ";
    				diff_obj.diff(A_obj, B_obj);
    			break;

    		case 5: cout << "\n Set B elements : ";
    	    		diff_obj.diff(B_obj, A_obj);
    	    	break;

    		case 6:	cout << "\n Number of elements which are not in both the sets : " << n-m;
    			break;

    		default:cout << "\n Invalid input! ";
    			break;
    	}

    }while(ch != 7);

    cout << "\n ---------------------------------------------- ";
    cout << "\n                       END                      ";
    cout << "\n ---------------------------------------------- ";

    return 0;
}
