#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int num1, num2, diff, borrow = 0;

    while (temp1 != NULL || temp2 != NULL) {
        if (temp1 != NULL && temp2 != NULL) {
            num1 = temp1->data;
            num2 = temp2->data;

            if (num2 > num1) {
                if (borrow == 1) {
                    num1 = (num1 + 10) - 1;
                } else {
                    num1 = num1 + 10;
                }
                borrow = 1;
            } else {
                if (borrow == 1) {
                    num1 -= 1;
                    borrow = 0;
                }
            }

            diff = num1 - num2;
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        } else if (temp1 != NULL) {
            num1 = temp1->data;

            if (borrow == 1) {
                if (num1 == 0) {
                    diff = 9;
                    borrow = 1;
                } else {
                    diff = num1 - 1;
                    borrow = 0;
                }
            } else {
                diff = num1;
            }

            temp1 = temp1->prev;
        }

        dl_insert_first(headR, tailR, diff);
    }

    // Remove leading zeros from the result
    delete_zeros_in_list1(headR, tailR);
    return 0;
}