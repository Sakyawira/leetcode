#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Reverse the list
        // Create an array of the values
        ListNode* originalHead = head;

        // Calculate the size of the link list
        int size = 0;
        while (head != nullptr)
        {
            head = head->next;
            size++;
        }
        head = originalHead;

        // Create an array of all the list nodes' values
        int* originalList = new int[size];
        int i = 0;
        while (i < size) {
            originalList[i] = head->val;
            i++;
            head = head->next;
        }

        // Create a reversed array of all the list nodes' values
        int* reversedList = new int[size];
        for (int i = 0; i < size; i++) {
            reversedList[i] = originalList[(size - i) - 1];
        }

        // Compare them
        for (int i = 0; i < size; i++) {
            std::cout << "reversedlist = " << reversedList[i] << ", variableList = " << originalList[i] << std::endl;
            if (originalList[i] != reversedList[i]) {
                delete[] reversedList;
                delete[] originalList;
                std::cout << "false" << std::endl;
                return false;
            }
        }
        delete[] reversedList;
        delete[] originalList;
        std::cout << "true" << std::endl;
        return true;
    }
};

int main() {
    ListNode* nextNext = new ListNode(2);
    ListNode* next = new ListNode(1, nextNext);
    ListNode* head = new ListNode(2, next);
    Solution s;
    s.isPalindrome(head);
    delete nextNext;
    delete next;
    delete head;
}