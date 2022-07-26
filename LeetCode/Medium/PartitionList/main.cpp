//92. Reverse Linked List II

#include<iostream>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
private:
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode();
        ListNode* list2 = new ListNode();

        ListNode* tail1 = list1;
        ListNode* tail2 = list2;
        while(head){
            if(head->val < x){
                tail1->next = head;
                tail1 = tail1->next;
            }else{
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = head->next;
        }
        tail1->next = list2->next;
        tail2->next = nullptr;
        return list1->next;
    }
};




void printAllNode(ListNode *head)
{
    ListNode *nowNode{head};
    cout <<"[";
    while(nowNode->next!=nullptr){
        cout << nowNode->val;
        if(nowNode->next!=nullptr){
            cout<<", ";
            nowNode = nowNode->next;
        }else{
            cout<<"";
        }
    }
    cout << nowNode->val;
    cout << "]";
}

int main(){
    Solution _Solve = Solution();
    ListNode Node6 = ListNode(2);
    ListNode Node5 = ListNode(5,&Node6);
    ListNode Node4 = ListNode(2,&Node5);
    ListNode Node3 = ListNode(3,&Node4);
    ListNode Node2 = ListNode(4,&Node3);
    ListNode Node1 = ListNode(1,&Node2);
    printAllNode(&Node1);
    auto Node = _Solve.partition(&Node1,3);
    
    cout << "\n";
    printAllNode(Node);

    cout << "\n\nEnd" << endl;
}
