/*Write the program and algorithm to add two polynomials using linked list. Explain with
an example.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *sum = NULL;
struct node *create_poly(struct node *ptr)
{
    int c, e;
    struct node *new_node;
    printf("\n Enter the coefficient and exponent : ");
    scanf("%d%d", &c, &e);
    while (c != 0)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coeff = c;
        new_node->exp = e;
        new_node->next = NULL;
        if (ptr == NULL)
        {
            ptr = new_node;
        }
        else
        {
            struct node *ptr1 = ptr;
            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next;
            }
            ptr1->next = new_node;
        }
        printf("\n Enter the coefficient and exponent : ");
        scanf("%d%d", &c, &e);
    }
    return ptr;
}
struct node *display_poly(struct node *ptr)
{
    struct node *ptr1 = ptr;
    while (ptr1 != NULL)
    {
        printf("%dx^%d", ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
        if (ptr1 != NULL)
        {
            printf(" + ");
        }
    }
    return ptr;
}


struct node *insert(struct node *ptr, int c, int e)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coeff = c;
    new_node->exp = e;
    new_node->next = NULL;
    if (ptr == NULL)
    {
        ptr = new_node;
    }
    else
    {
        struct node *ptr1 = ptr;
        while (ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
        }
        ptr1->next = new_node;
    }
    return ptr;
}

struct node *add_poly(struct node *a, struct node *b)
{
    struct node *ptr1 = a;
    struct node *ptr2 = b;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            sum = insert(sum, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            sum = insert(sum, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else
        {
            sum = insert(sum, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        sum = insert(sum, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        sum = insert(sum, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }
    return sum;
}


int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1. Enter the first polynomial");
        printf("\n 2. Display the first polynomial");
        printf("\n 3. Enter the second polynomial");
        printf("\n 4. Display the second polynomial");
        printf("\n 5. Add the polynomials");
        printf("\n 6. Display the result");
        printf("\n 7. EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            poly1 = create_poly(poly1);
            break;
        case 2:
            poly1 = display_poly(poly1);
            break;
        case 3:
            poly2 = create_poly(poly2);
            break;
        case 4:
            poly2 = display_poly(poly2);
            break;
        case 5:
            sum = add_poly(poly1, poly2);
            break;
        case 6:
            sum = display_poly(sum);
            break;
        }
    } while (option != 7);
    return 0;
}
