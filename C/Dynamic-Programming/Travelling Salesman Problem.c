#include<stdio.h>

//initialized two array-->cities a 2D array to store the distance between two cities and cities_visited a 1D array to store the cities that are already visited.
int cities[10][10],cities_visited[10],n,cost=0;

int main()
{
    int i,j;

printf("Enter the number of Cities: ");
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

printf("\n\nThe Possible Path is:\n");
min_cost(0); //passing 0 because starting vertex

printf("\n\nMinimum cost is %d\n ",cost);

return 0;
}

//min_cost function calculates the minimum cost required to visit a city.
void min_cost(int city)
{
int i,ncity;

cities_visited[city]=1;

printf("%d--",city+1);
ncity=least(city);

if(ncity==9999)
{
ncity=0;
printf("%d",ncity+1);
cost+=cities[city][ncity];

return;
}

min_cost(ncity);
}

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


          
          
