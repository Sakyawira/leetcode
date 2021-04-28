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
        std::vector<int> variablesList;
        // Reverse the list
        //int size = 0;
        while (head != nullptr)
        {
            variablesList.push_back(head->val);
            head = head->next;
            //size++;
        }
        std::vector<int> reversedList = variablesList;

        std::reverse(reversedList.begin(), reversedList.end());

        std::cout << variablesList.size() << std::endl;

        for (int i = 0; i < variablesList.size(); i++) {
            std::cout << "reversedlist = " << reversedList[i] << ", variableList = " << variablesList[i] << std::endl;
            if (variablesList[i] != reversedList[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ListNode* head;
    Solution s;
    s.isPalindrome(head);
}