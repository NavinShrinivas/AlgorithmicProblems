/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* newNode(int val){
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* Copy1 = l1;
    struct ListNode* Copy2 = l2;
    while(Copy1!=NULL && Copy2!=NULL){
        if(Copy1->next == NULL && Copy2->next == NULL){
            break;
        }
        if(Copy1 -> next == NULL){
            Copy1->next = newNode(0);
        }else if(Copy2->next == NULL){
            Copy2->next = newNode(0);
        }
        Copy1 = Copy1->next;
        Copy2 = Copy2->next;
    } 
    
    int first_digit = l1->val+l2->val;
    int carry = 0;
    if (first_digit >= 10){
        carry = 10;
        first_digit -= 10;
    }
    struct ListNode* AnswerList =  newNode(first_digit);
    struct ListNode* ret = AnswerList;
    while(l1->next!=NULL && l2->next!=NULL){
        l1 = l1->next;
        l2 = l2->next;

        if(carry != 0){
            int middle_digits = l1->val+l2->val+1;
            if (middle_digits >= 10){
                carry = 10;
                middle_digits -= 10;
            }else{
                carry = 0;
            }
            AnswerList->next = newNode(middle_digits);
        }else{
            int middle_digits = l1->val+l2->val;
            if (middle_digits >= 10){
                carry = 10;
                middle_digits -= 10; 
            }
            AnswerList->next = newNode(middle_digits);
        }

        AnswerList = AnswerList->next;

    }
    if(carry!=0){
        AnswerList->next = newNode(1);
    }

    return ret;
}
