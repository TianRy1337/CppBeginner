//92. Reverse Linked List II

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* getNodeValue(ListNode* head, int target){
        int count = 1;
        ListNode *nowNode{head};
        while (count!=target){
            nowNode = nowNode->next;
            count++;
        }
        return nowNode;
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode *newLeft{getNodeValue(head,left)};
        ListNode *newRight{getNodeValue(head,right)};      
        while(left < right)
        {
            int tmp{};
            tmp = newLeft->val;
            newLeft->val = newRight->val;
            newRight->val = tmp;
            left++;
            right--;
            newLeft = getNodeValue(head,left);
            newRight = getNodeValue(head,right);
        }

        return head;
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
    ListNode Node5 = ListNode(5);
    ListNode Node4 = ListNode(4,&Node5);
    ListNode Node3 = ListNode(3,&Node4);
    ListNode Node2 = ListNode(2,&Node3);
    ListNode Node1 = ListNode(1,&Node2);

    
    printAllNode(&Node1);
    cout << "\n";
    ListNode *newNodeHead = _Solve.reverseBetween(&Node1, 2, 5);
    // ListNode *newNodeHead = _Solve.getNodeValue(&Node1, 2);
    
    printAllNode(&Node1);


    
    cout << "\n\nEnd" << endl;
}
