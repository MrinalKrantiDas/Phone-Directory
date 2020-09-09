#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
// This is an user defined structure for  storing the contact details in form of linked list.
struct Node {
    long long data;
    string name;
    Node *next;
};
// The head of the linked list is assigned a NULL value initially

Node *head=nullptr;

// Function to create a Linked List
// This is the building block of the project and adds contact to the list every time a new entry is made

Node* Create(long long data, string name, Node *head)
{
  if(head==nullptr)
  {
      Node*temp=new Node();
      temp->data=data;
      temp->name=name;
      temp->next=nullptr;
      head=temp;
  }
  else
  {
      Node *trav=head;
      while(trav->next!=nullptr)
      trav=trav->next;
      Node*temp=new Node();
      temp->data=data;
      temp->name=name;
      trav->next=temp;
      temp->next=nullptr;

  }
  return head;
}
// This function will be used when the user wants to search a contact by his/her Name.

void TraverseByName(Node *head, string Name)
{
    Node *temp=head;
    int flag=0;
    while(temp!=nullptr)
    {
        if(temp->name==Name)
        {
            flag=1;
            cout<<"The phone number is:  "<<temp->data<<endl;
        }
        temp=temp->next;
    }
    if(flag==0) cout<<"Name not found"<<endl;
}
// This function will help when  the user will want to search a contact by his/her number

void TraverseByNumber(Node *head, long long Number)
{
    Node *temp=head;
    int flag=0;
    while(temp!=nullptr)
    {
        if(temp->data==Number)
        {
            flag=1;
            cout<<"The phone number is:  "<<temp->data<<endl;
        }
        temp=temp->next;
    }
    if(flag==0) cout<<"Number not found"<<endl;
}
// Function to view full contact list

void TraverseEntireList(Node *head)
{
     Node *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->name<<"   "<<temp->data<<endl;
        temp=temp->next;
    }

}
//Function to change the contact's Name

void ChangeName(Node *head)
{
    cout<<"Enter the name you want to change:"<<endl;
    string str1;
    cin>>str1;
    cout<<"Enter the new name to be used:"<<endl;
    string str2;
    cin>>str2;
    Node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->name==str1)
        {
            temp->name=str2;
        }
        temp=temp->next;
    }
}

//Function to change the contact's number in case he/she changes it

void ChangeNumber(Node *head)
{
    cout<<"Enter the number you want to change:"<<endl;
    long long x;
    cin>>x;
    long long y;
    cout<<"Enter the new number to be used:"<<endl;
     cin>>y;
     Node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==x)
        {
            temp->data=y;
        }
        temp=temp->next;
    }
}
// Now we will see the code to remove duplicate contacts from the Phone Directory

void RemoveDuplicates(Node* head)
{
    map<long long, int> mp;
    Node *temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr)
    {
        if(mp.find(temp->data)!=mp.end())
        prev->next=temp->next;
        if(mp.find(temp->data)==mp.end())
        {
            mp[temp->data]++;
            prev=temp;
        }
         temp=temp->next;
    }
}
// Function to sort the names in the phone directory alphabetically

void SortByName(Node *head)
{
    map<string,int> mpstr;
    Node* temp=head;
    cout<<"\n The contacts sorted alphabetically are:"<<endl;
    while(temp!=nullptr)
    {
        mpstr[temp->name]++;
        temp=temp->next;
    }
    for(auto it=mpstr.begin();it!=mpstr.end();it++)
    {
        while(it->second--)
        {
            cout<<it->first<<endl;
        }
    }
}
// The main function
int main()
{
    cout<<"Enter the total number of queries you have:"<<endl;
    int queries;
    cin>>queries;
    while (queries--)
    {
      cout<<"Do you want to save a new contact detail or view contact book"<<"\n";
      cout<<endl;
      cout<<"Press 1: Save a new contact"<<endl;
      cout<<"Press 2: Search contact detail"<<endl;
      cout<<"Press 3: To see entire contact list"<<endl;
      cout<<"Press 4: To update an existing contact"<<endl;
      cout<<"Press 5: To remove duplicate contacts"<<endl;
      cout<<"Press 6: To view contacts sorted by their names:"<<endl;
      int choice;
      cin>>choice;
      if(choice==1)
      {
        cout<<"Enter the Phone Number:  "<<endl;
        long long n;
        cin>>n;
        cout<<endl;
        cout<<"Make sure while you enter the name, use underscores instead of space"<<endl;
        cout<<"\n";
        cout<<"Enter the name of the person:"<<endl;
        string Name;
        cin>>Name;
        head=Create(n,Name,head);
       }
      if(choice==2)
        {
        cout<<"Enter whether you want to search by name or number:"<<endl;
        cout<<"Press 1: Search by Name"<<endl;
        cout<<"Press 2: Search by Number"<<endl;
        int x;
        cin>>x;
        if(x==1)
        {
            string SearchName;
            cout<<"Enter the name you want to search"<<endl;
            cin>>SearchName;
            TraverseByName(head,SearchName);
        }
        if(x==2)
        {
             long long SearchNumber;
             cout<<"Enter the number you want to search"<<endl;
             cout<<endl;
             cin>>SearchNumber;
             cout<<endl;
             TraverseByNumber(head,SearchNumber);
        }
        }
        if(choice==3)
        {
             if(head==nullptr)
            cout<<"The phone directory is empty. Add new contact details to view"<<endl;
            else
                TraverseEntireList(head);
        }
        if(choice==4)
        {
            cout<<"Enter the field you want to change/update"<<endl;
            cout<<"Press 1: To change the name of a contact"<<endl;
            cout<<"Press 2: To change the number of a contact"<<endl;
            int a;
            cin>>a;
            if(a==1)
            ChangeName(head);
            if(a==2)
            ChangeNumber(head);
        }
        if(choice==5)
        {
            RemoveDuplicates(head);
            cout<<"The updated list after removing the duplicate contacts:"<<endl;
            TraverseEntireList(head);
        }
        if(choice==6)
        {
            SortByName(head);
            cout<<endl;
        }
        cout<<endl;
    }
      // This is just to write into a text file the values entered by the user. The file will contain all information given as input

        ofstream WriteToFile;
        WriteToFile.open("Contact_Details.txt");
        Node*temp=head;
        while(temp!=nullptr)
        {
            WriteToFile<<temp->data<<"   "<<temp->name<<endl;
            temp=temp->next;
        }
        WriteToFile.close();

return 0;
}

