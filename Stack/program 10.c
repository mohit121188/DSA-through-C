/*Next greater element: Given an array, for each element, find the next greater element in the array
(e.g., for the array [4, 5, 2, 25], the next greater element for 4 is 5, for 5 is 25, for 2 is 25,
 and for 25 there is no greater element).*/

/*Algorithm next_greater : step by step
(1) Create an empty stack and an array to store the results.
(2) Iterate through the input array from right to left.
(3) For each element in the input array:
      (a) Pop elements from the stack until the top of the stack is greater than or equal to the current element, or until the stack is empty.
      (b) If the stack is empty, there is no greater element to the right of the current element, so store -1 in the result array for this element.
      (c) Otherwise, store the top element of the stack in the result array for this element.
      (d) Push the current element onto the stack.
(4) Reverse the result array.
(5) The result array now contains the next greater element for each element in the input array.
*/
#include <stdio.h>
#define max 4

struct stack {
    int arr[max];
    int tos;
};

typedef struct stack stack;

void push(stack *ps, int x) {
    if (ps->tos == max - 1) {
        printf("\nStack Overflow!!!");
        return;
    }
    ps->arr[++ps->tos] = x;
}

int pop(stack *ps) {
    if (ps->tos == -1) {
        printf("\nStack Underflow!!!");
        return -1;
    }
    return ps->arr[ps->tos--];
}

int peek(stack s) {
    return s.arr[s.tos];
}

int isempty(stack s) {
    return s.tos == -1;
}


void next_greater(int res_arr[], int arr[]) {
    int i;
    stack s;
    s.tos = -1;

    for (i = max - 1; i >= 0; i--) {
        while (!isempty(s) && arr[i] >= peek(s)) {
            pop(&s);
        }
        if (isempty(s)) {
            res_arr[i] = -1;
        } else {
            res_arr[i] = peek(s);
        }
        push(&s, arr[i]);
    }
}

int main() {
    int arr[max], i, res_arr[max];
    printf("Enter 4 integers: ");
    for (i = 0; i < max; i++) {
        scanf("%d", &arr[i]);
    }
    next_greater(res_arr, arr);
    for (i = 0; i < max; i++) {
        printf("\nNext greater element of %d is %d", arr[i], res_arr[i]);
    }
    return 0;
}
