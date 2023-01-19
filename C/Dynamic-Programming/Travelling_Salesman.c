#include<stdio.h>

//creating a 2D array cities to store the cost of travelling from one city to another

//cities_visited is a 1D array that store the cities already visited


int cities[10][10],cities_visited[10],n,cost=0;

int main()

{
    int i,j;

printf("Enter the number of Cities: ");//asking user to input the number of cities

    scanf("%d",&n);

printf("\nEnter the Cost Matrix\n");

for(i=0;i < n;i++)

{

    printf("\nEnter Elements of Row: %d\n",i+1);

for( j=0;j < n;j++)

    scanf("  %d",&cities[i][j]);

cities_visited[i]=0;

}

printf("\n\nThe cost list is:");

for( i=0;i < n;i++)

{

    printf("\n");

for(j=0;j < n;j++)

    printf("\t%d",cities[i][j]);
}

//printing the possibe path and the minimum cost required
    
printf("\n\nThe Possible Path is:\n");

    min_cost(0); //passing 0 because starting vertex

printf("\n\nMinimum cost is %d\n ",cost);

return 0;
}

//this function returns the minimum cost required to visit all the cities

void min_cost(int city)

{

    int i,ncity;

cities_visited[city]=1;

printf("%d--",city+1);

    ncity=least(city);

if(ncity==9999)//checking if there is a way to move from one city to another (here infinity==9999)

{

    ncity=0;

    printf("%d",ncity+1);

    cost+=cities[city][ncity];

return;

}

min_cost(ncity);
}

//calculates the mimimum cost required to travel from one city to another

int least(int c)

{

    int i,nc=9999;

    int min=9999,kmin;

for(i=0;i < n;i++)

{

    if((cities[c][i]!=0)&&(cities_visited[i]==0))

        if(cities[c][i]+cities[i][c] < min)

        {

            min=cities[i][0]+cities[c][i];

            kmin=cities[c][i];

            nc=i;

        }

}


    if(min!=9999)

        cost+=kmin;


    return nc;

}




