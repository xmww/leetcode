//
// Created by skl on 2018/9/16.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        ListNode* newNode = NULL, *header = NULL;
        bool flag = false;

        auto addVal = [&flag](int a, int b)
        {
            int ret =  a + b + flag;
            if(ret > 9)
            {
                flag = true;
                ret -= 10;
            }
            else
            {
                flag = false;
            }
            return ret;
        };

        auto pushNode = [&newNode, &header](ListNode* node)
        {
            if(NULL == newNode)
            {
                newNode = node;
                header = node;
            }
            else
            {
                newNode->next = node;
                newNode = node;
            }
        };

        while(NULL != l1 && NULL != l2)
        {
            pushNode(new ListNode(addVal(l1->val, l2->val)));
            l1 = l1->next;
            l2 = l2->next;
        }

        while(NULL != l1)
        {
            pushNode(new ListNode(addVal(l1->val,0)));
            l1 = l1->next;
        }

        while(NULL != l2)
        {
            pushNode(new ListNode(addVal(0, l2->val)));
            l2 = l2->next;
        }

        if(flag)
        {
            pushNode(new ListNode(addVal(0, 0)));
        }
        return header;
    }
};

ListNode* createListNode(const vector<int>& vec)
{
    ListNode* header = NULL, *preNode = NULL;

    auto pushNode = [&preNode, &header](ListNode* node)
    {
        if(NULL == preNode)
        {
            preNode = node;
            header = node;
        }
        else
        {
            preNode->next = node;
            preNode = node;
        }
    };

    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        pushNode(new ListNode(*it));
    }
    return header;
}

void printListNode(const ListNode* list)
{
    bool isStart = true;
    while(NULL != list)
    {
        if(isStart)
        {
            cout << list->val;
            isStart = false;
        }
        else
        {
            cout << " -> "  << list->val;
        }
        list = list->next;
    }
}



int main()
{
    Solution s;
    //(2 -> 4 -> 3) + (5 -> 6 -> 4)
    cout << "test01 start" << endl;
    {
        vector<int> v1 = {2, 4, 3};
        vector<int> v2 = {5, 6, 4};
        ListNode* l1 = createListNode(v1);
        ListNode* l2 = createListNode(v2);
        ListNode* l3 = s.addTwoNumbers(l1, l2);

        std::cout << "print l1:";
        printListNode(l1);
        cout << endl << "print l2:";
        printListNode(l2);
        cout << endl << "output:";
        printListNode(l3);
        cout << endl;
    }
    cout << "test01 end" << endl;


    cout << "test02 start" << endl << endl;
    {
        vector<int> v1 = {0};
        vector<int> v2 = {5, 6, 4};
        ListNode* l1 = createListNode(v1);
        ListNode* l2 = createListNode(v2);
        ListNode* l3 = s.addTwoNumbers(l1, l2);

        std::cout << "print l1:";
        printListNode(l1);
        cout << endl << "print l2:";
        printListNode(l2);
        cout << endl << "output:";
        printListNode(l3);
        cout << endl;
    }
    cout << "test02 end" << endl;

    return 0;
}