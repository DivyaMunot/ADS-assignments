#include<iostream>
#define null NULL
using namespace std;

class nodes
{
public:
    int data;
    class nodes * next;
};

class sets
{
    class nodes *heada, *headb;
public:
    sets();
    void insert_node();
    void delete_node();
    bool search_data(int, int);
    void print_sets();
    void union_set();
    void intersection_set();
    void differece_set();
    void symmetric_diff();
};

sets::sets()
{
    heada = null;
    headb = null;
}

bool sets::search_data(int data, int ch)
{
    class nodes *p;
    if(ch == 0)
        p = heada;
    else if (ch == 1)
        p = headb;
    while(p != null){
        if(p -> data == data)
            return 1;
        p = p -> next;
    }
    return 0;
}

void sets::insert_node()
{
    class nodes *start;
    cout << "In which Set do you want to insert the data(A/B):";
    char ch;
    cin >> ch;
    int flag = -1;
    if(ch == 'A' || ch == 'a'){
        start = heada;
        flag = 0;
    }
    else if(ch == 'B' || ch == 'b') {
        start = headb;
        flag = 1;
    }
    else{
        cout << "Wrong choice" << endl;
        return;
    }
    cout << "Enter the data you want to enter: " ;
    int data;
    cin >> data;
    if(search_data(data, flag)){
        cout << "The data is already Present in the set" << endl;
        return;
    }
    else{
        class nodes *temp = new class nodes;
        temp -> data = data;
        temp -> next = NULL;
        if(start != NULL){
            while(start -> next != NULL)
                start = start -> next;
            start -> next = temp;
            return;
        }
        else{
            if(flag == 0)
                heada = temp;
            else
                headb = temp;
            return;
        }

    }
}

void sets::delete_node()
{
    class nodes *start;
    cout << "Enter the node in which your data is present(A/B): ";
    char ch;
    cin >> ch;
    int flag = -1;
    if(ch == 'A' || ch == 'a'){
        flag = 0;
        start = heada;
    }
    else if(ch == 'B' || ch == 'b'){
        flag = 1;
        start = headb;
    }
    else{
        cout << "Wrong Choice " << endl;
        return;
    }
    cout << "Enter the data that you want to delete:";
    int data;
    cin >> data;
    if(search_data(data, flag)){
        class nodes *p, *q;
        if(flag == 0)
            p = heada;
        else if(flag == 1)
            p = headb;
        q = p;
        if(p -> data == data){
            if(flag == 0)
                heada = p -> next;
            else if(flag == 1)
                headb = p -> next;
            cout << "Successfully deleted data" << endl;
            return;
        }
        else{
            p = p -> next;
            while(p -> data != data){
                p = p -> next;
                q = q -> next;
            }
            q -> next = p -> next;
            cout << "Successfully deleted data" << endl;
            return;
        }
    }
    cout << "No Data found" << endl;
}

void sets::union_set()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Union" << endl;
    class nodes *p, *q;
    p = heada;
    q = headb;
    while(p != null){
        if(p != null)
            cout << p -> data << " ";
        p = p -> next;
    }
    while(q != null){
        if(q != null && !search_data(q -> data, 0))
            cout << q -> data << " ";
        q = q -> next;
    }
    cout << endl;
}

void sets::intersection_set()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Intersection " << endl;
    class nodes *p;
    p = heada;
    while(p != null){
        if(p != null && search_data(p -> data, 1))
            cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

void sets::differece_set()
{cout << "------------------------------------------------------------" << endl;
    cout << "Difference sets" << endl;
    class nodes *p, *q;
    p = heada;
    q = headb;
    cout << "A - B: " ;
    while(p != null){
        if(p != null && !search_data(p -> data, 1))
            cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
    cout << "B - A: ";
    while(q != null){
        if(q != null && !search_data(q -> data, 0))
            cout << q -> data << " ";
        q = q -> next;
    }
    cout << endl;

}

void sets::symmetric_diff()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Symmetric difference" << endl;
    class nodes *p, *q;
    p = heada;
    q = headb;
    while(p != null){
        if(p != null && !search_data(p -> data, 1))
            cout << p -> data << " ";
        p = p -> next;
    }
    while(q != null){
        if(q != null && !search_data(q -> data, 0))
            cout << q -> data << " ";
        q = q -> next;
    }
    cout << endl;
}

void sets::print_sets()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "The sets are " << endl;
    class nodes *p = heada;
    cout << "A: ";
    while(p != null){
        if(p == null)
            break;
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
    cout << "B: ";
    p = headb;
    while(p != NULL){
        if(p == NULL)
            break;
        cout << p -> data << " " ;
        p = p -> next;
    }
    cout << endl;
}

void menu()
{
    int ch;
    sets o;
    do{
        cout << "------------------------------------------------------------" << endl;
        cout << "1.Insert Data" << endl;
        cout << "2.Delete Data" << endl;
        cout << "3.Display both the sets" << endl;
        cout << "4.Union of both sets" << endl;
        cout << "5.Intersection of sets" << endl;
        cout << "6.Difference of sets" << endl;
        cout << "7.Symmetric difference of sets" << endl;
        cout << "8.Exit" << endl;
        cout << ">>";
        cin >> ch;
        switch(ch)
        {
        case 1:
           o.insert_node();
           break;
        case 2:
            o.delete_node();
            break;
        case 3:
            o.print_sets();
            break;
        case 4:
            o.union_set();
            break;
        case 5:
            o.intersection_set();
            break;
        case 6:
            o.differece_set();
            break;
        case 7:
            o.symmetric_diff();
            break;
        case 8:
            cout << "------------------------------------------------------------" << endl;
            cout << "Thank You" << endl;
        default:
            cout << "------------------------------------------------------------" << endl;
            cout << "Wrong choice" << endl;
        }
    }while(ch != 9);
}

int main()
{
    menu();
    return 0;
}
