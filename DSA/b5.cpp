/*A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method*/


#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char caption[10];
    int count;
    struct node *child[10];
} *root;
class Book
{
public:
    void create();
    void display(node *r1);

    Book()
    {
        root = NULL;
    }
};

void Book::create()
{
    int totle_chapters, i, j, k;
    root = new node;
    cout << "Enter name of book: ";
    cin >> root->caption;
    cout << "Enter no. of chapters in book: ";
    cin >> totle_chapters;
    root->count = totle_chapters;
    for (i = 0; i < totle_chapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name: ";
        cin >> root->child[i]->caption;
        cout << "Enter no. of sections in  Chapter " << root->child[i]->caption<<":";
        cin >> root->child[i]->count;
        for (j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1<<":" ;
            cin >> root->child[i]->child[j]->caption;
        }
    }
}

void Book::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";

        cout << "\n Book title : " << r1->caption;
        tchapters = r1->count;
        for (i = 0; i < tchapters; i++)
        {

            cout << "\n  Chapter : " << i + 1;
            cout << " " << r1->child[i]->caption;
            cout << "\n Sections :  ";
            for (j = 0; j < r1->child[i]->count; j++)
            {

                cout << "\n  " << r1->child[i]->child[j]->caption;
            }
        }
    }
}

int main()
{
    int choice;
    Book b;
    while (1)
    {

        cout << "Book Tree Creation" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b.create();
        case 2:
            b.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}
