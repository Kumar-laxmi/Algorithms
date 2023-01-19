#include <stdio.h>
 
void towers(int, char, char, char);
 
int main()
{
    int number;
    printf("Enter the number of rings : ");
    scanf("%d", &number);
    printf("Order of moves involve in the Tower of Hanoi are :\n");
    towers(number, 'A', 'C', 'B');
    return 0;
}
void towers(int number, char frompole, char topole, char auxpole)
{
    if (number == 1)
    {
        printf("\n Move disk 1 from pole %c to pole %c", frompole, topole);
        return;
    }
     towers(number - 1, frompole, auxpole, topole);
    printf("\n Move ring %d from pole %c to pole %c", number, frompole, topole);
    towers(number - 1, auxpole, topole, frompole);
}