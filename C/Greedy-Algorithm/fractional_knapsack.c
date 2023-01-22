#include <stdio.h>

void main()
{
    // capacity = knapsack capacity
    // no_items:- number of items that can be enter
    // cur_weight:- current weight
    int capacity, no_items, cur_weight, item;
    int used[10]; // to keep track of which items have been added to the knapsack
    float total_profit;
    int i;
    int weight[10];
    int value[10];

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d item:\n", no_items);
    for (i = 0; i < no_items; i++)
    {
        // enter weight and value of each object
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }

    for (i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity; // to keep track of the current weight of the knapsack
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item]; // calculates the total profit by adding the value of all the items added to the knapsack
        if (cur_weight >= 0)
            printf("Added object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], cur_weight);
        else
        {
            int item_percent = (int)((1 + (float)cur_weight / weight[item]) * 100);
            printf("Added %d%% (%d Rs., %dKg) of object %d in the bag.\n", item_percent, value[item], weight[item], item + 1);
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
        // If the item can be added completely to the knapsack, it is added in its entirety, and the space remaining in the knapsack is updated. If the item cannot be added completely to the knapsack, only a fraction of the item is added, and the space remaining in the knapsack is updated accordingly.
    }

    printf("Filled the bag with objects worth %.2f Rs.\n", total_profit);
}