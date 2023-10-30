/*Write the recursive pseudo code and recursive program using C for “Tower of Hanoi” 
problem. Explain your solution for three disc using recursive steps/recursive tree.
*/
#include<stdio.h>
#include<stdlib.h>
void tower(int n,char S, char H, char D)
{
    if(n==1)
    {
        printf("Move %d disk from %c to %c\n",n,S,H,D);
        return;
    }
    tower(n-1,S,D,H);
    printf("\nMove %d disk from %c to %c\n",n,S,H,D);
    tower(n-1,H,S,D);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    tower(n,'S','H','D');
    return 0;
}