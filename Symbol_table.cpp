#include <iostream>
#include<string>

using namespace std;

struct st
{
	string identifer;
	string type;
	string initial;
	int no;
    int line_no[10];
    bool flag;
};

class table
{
	st a[20];
	int n;

public:
    table()
    {
        for(int i=0;i<20;i++)
		a[i].flag=false;

    }
	void accept()
	{
		int j,k;

		cout<<"\n Enter number of entries : ";
		cin>>n;

		for(int i=0;i<n;i++)
		{
            cout<<endl;
			cout<<"Enter identifier name : ";
			cin>>a[i].identifer;

			cout<<"Enter data-type of the identifier : ";
			cin>>a[i].type;

			cout<<"Enter initial value of identifier : ";
			cin>>a[i].initial;

			cout<<"Enter number of lines identifier is used : ";
			cin>>a[i].no;

            a[i].flag =true;

			for(j=0;j<a[i].no;j++)
			{
				cout<<"Enter line numbers: ";
				cin>>a[i].line_no[j];
			}
		}

	}

	void display()
	{

    	cout<<"\nIdentifier name   Type   Initial value   No. of lines it is used   Line numbers\n";
		for(int i=0; i<=n ;i++)
		{
			if(a[i].flag==true)
			{
			    cout<<'\n'<<a[i].identifer<<"\t           "<<a[i].type<<"\t      "<<a[i].initial<<"\t                "<<a[i].no<<"\t             [";
			    for(int j=0;j<a[i].no;j++)
			    {
				    cout<<a[i].line_no[j]<<" ";
			    }
			    cout<<"]";
		    }
		}
		cout<<"\n\n";
	}

	void addnewrecord()
	{

            n=n+1;
            a[n].flag =true;
            cout<<"\nEnter identifier name : ";
			cin>>a[n].identifer;

			cout<<"Enter data-type of the identifier : ";
			cin>>a[n].type;

			cout<<"Enter initial value of identifier : ";
			cin>>a[n].initial;

			cout<<"Enter number of lines identifier is used : ";
			cin>>a[n].no;

			for(int j=0;j<a[n].no;j++)
			{
				cout<<"Enter line numbers: ";
				cin>>a[n].line_no[j];
			}

			cout<<"\nRecord added successfully !\n\n ";


	}

    void deleterecord()
    {
            string f;

            int i,j;
            cout<<"\nEnter the identifier name you want to delete : ";
            cin>>f;

            for(i=0;i<=n;i++)
		    {
			    if(a[i].identifer==f && a[i].flag == true)
			    {
			        a[i].flag=false;
			        cout<<"\nDeleted successfully !\n\n ";
			        return;
			    }
            }

            cout<<"\nIdentifier not found !\n\n ";
    }

    void updaterecord()
    {
            string f;

            int i,j;
            cout<<"\nEnter the identifier name you want to update : ";
            cin>>f;

            for(i=0;i<=n;i++)
		    {
			    if(a[i].identifer==f && a[i].flag == true)
			    {
			        cout<<"\nEnter updated data : \n";
			        cout<<"Enter data-type of the identifier : ";
			        cin>>a[i].type;

			        cout<<"Enter initial value of identifier : ";
			        cin>>a[i].initial;

			        cout<<"Enter number of lines identifier is used : ";
			        cin>>a[i].no;

			        for(int j=0;j<a[i].no;j++)
			        {
				        cout<<"Enter line numbers: ";
				        cin>>a[i].line_no[j];
			        }
			        cout<<"\nUpdated successfully !\n\n ";
			        return;
			    }
            }

           cout<<"\nIdentifier not found !\n\n ";;

    }

};

int main()
{
	table t;
	cout<<"----------------------------SYMBOL TABLE--------------------------------";
	int ch;
	do
	{
	    cout<<"\nMenu";
	    cout<<"\n\n1 : Create symbol table.";
	    cout<<"\n2 : Display Symbol table.";
	    cout<<"\n3 : Add new element to the symbol table.";
	    cout<<"\n4 : Update an element in the symbol table.";
	    cout<<"\n5 : Delete an element from the symbol table.";
	    cout<<"\n6 :EXIT";
	    cout<<"\nEnter your choice : ";
        cin>>ch;

	    switch(ch)
        {
            case 1 : t.accept();
                     break;
            case 2 : t.display();
                     break;
            case 3 : t.addnewrecord();
                     break;
            case 4 : t.updaterecord();
                     break;
            case 5 : t.deleterecord();
                     break;
            case 6 : cout<<"\nExitted...!\n";
                     break;
            default:cout<<"\nEnter a valid choice...!";
        }
    }while(ch!=6);
	return 0;
}
