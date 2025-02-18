#include <iostream>

using namespace std;

struct Node{

    int data;
    Node *next;
};

class LinkedList{
public:

    Node *head;

    void display(){
        Node *tem = head;
        
        while(tem != nullptr){
            cout<<"Data: "<<tem->data<<endl;
            tem = tem->next;
        }
    }

    void sum(){
        Node *tem = head;
        int sum=0,cnt=0;

        while(tem!=nullptr){
            sum+=tem->data;
            cnt++;
            tem = tem->next;
        }
    }

    void searchKeyElement(int key){
        Node *tem = head;
        int cnt=0;

        while(tem!=nullptr){
            if(tem->data == key){
                cout<<"Found key element at "<<cnt<<" Node"<<endl;
                return;
            }
            cnt++;
        }
    }

    void deleteElement(int key){
        Node *currPtr = head;
        Node *prevPtr = nullptr;

        while(currPtr != nullptr){
            if(currPtr->data == key){
                if(prevPtr){
                    prevPtr->next = currPtr->next;
                }else{
                    head = currPtr->next;
                }
                delete currPtr;
                return;
            }
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

    }

    void isSorted(){
        Node *currPtr = head;
        Node *nextPtr = head->next;

        while(nextPtr != nullptr){
            if(currPtr->data <= nextPtr->data){
                currPtr = nextPtr;
                nextPtr = nextPtr->next;
            }else{
                cout<<"Not Sorted"<<endl;
                return;
            }
        }

        cout<<"Sorted"<<endl;
        return;
    }

    void mergeList(LinkedList *list){
        Node *tem = head;

        while(tem->next != nullptr){
            tem = tem->next;
        }

        tem->next = list->head;
    }
};