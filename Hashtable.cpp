#include <iostream>

using namespace std;

class Hashtable
{
    int HT[20], flag[20];

public :
        int size;
        Hashtable()
        {
            for(int i=0; i<20; i++)
                flag[i] = 0;
        }
        int hashfunction(int key)
        {
            return (key%size);
        }
        void insert_key(int key);
        void search_key(int key);
        void delete_key(int key);
        void display();
};

void Hashtable :: insert_key(int key)
{
    int p;
    p = hashfunction(key);

    for(int i=0; i<size; i++)
    {
        if(flag[p] == 0)
        {
            HT[p] = key;
            flag[p] = 1;
            return;
        }
        else
            p = (p+1)%size;
    }
    cout << "\n Hash table is full!! ";
}
void Hashtable :: search_key(int key)
{
    int p;
    p = hashfunction(key);

    for(int i=0; i<size; i++)
    {
        if(HT[p] == key)
        {
            cout << "\n Item found at " << p;
            return;
        }
        else
            p = (p+1)%size;
    }
    cout << "\n Item not found. ";
}

void Hashtable :: delete_key(int key)
{
    int p;
    p = hashfunction(key);

    for(int i=0; i<size; i++)
    {
        if(HT[p] == key && flag[p] == 1)
        {
            flag[p] = 0;
            HT[p] = -1;
            cout << "\n " << key << " is deleted from the hash table. ";
            return;
        }
        else
            p = (p+1)%size;
    }
    cout << "\n The item to be deleted is not in the hash table. ";
}

void Hashtable :: display()
{
    for(int i=0; i<size; i++)
    {
        if(flag[i] == 1)
        {
            cout << " [" << i << "] -> " << HT[i] << endl;
        }
    }
}

int main()
{
    int ch, key;
    Hashtable obj;

    cout << "\n Enter the size of the hash table : ";
    cin >> obj.size;

    do
    {
        cout << "\n ------------------------------------------ ";
        cout << "\n Enter your choice "
                "\n 1. Insert element in the hash table. "
                "\n 2. Search for an element. "
                "\n 3. Delete an element from the hash table. "
                "\n 4. Display the hash table. "
                "\n 5. Exit. "
                "\n Here : ";
        cin >> ch;

        switch(ch)
        {
            case 1: cout << "\n Enter the element to be inserted in the hash table: ";
                    cin >> key;
                    obj.insert_key(key);
                break;

            case 2: cout << "\n Enter the element to be searched in the hash table : ";
                    cin >> key;
                    obj.search_key(key);
                break;

            case 3: cout << "\n Enter the element to be deleted from the hash table : ";
                    cin >> key;
                    obj.delete_key(key);
                break;

            case 4: cout << "\n HASH TABLE " << endl;
                    obj.display();
                break;
        }
    }while(ch!=5);

    cout << "\n ------------------------------------------ ";
    cout << "\n                     END                    ";
    cout << "\n ------------------------------------------ ";

    return 0;
}
