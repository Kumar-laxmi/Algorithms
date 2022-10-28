package Floyd_Warshall;

import java.util.Scanner;
public class floyd_warshall {
  
  public static void min_dist (int matrix[][],int vertice) 
  { 
      
      int i, j, count=0; 
   
  while( count < vertice) 
      { 
          for (i = 0; i < vertice; i++) 
          { 
             
              for (j = 0; j < vertice; j++) 
              { 
                 
                  if (matrix[i][count] + matrix[count][j] < matrix[i][j]) 
                      matrix[i][j] = matrix[i][count] + matrix[count][j]; 
              } 
          } 
          count++;
      } 
    display(matrix,vertice); 
  } 
  public static void display(int matrix[][],int vertice) 
  { 
      System.out.print ("SHORTEST PATH BETWEEN EVERY VERTICES: \n"); 
      for (int i = 0; i < vertice; i++) 
      { 
      	System.out.print("\t"+(i+1));
      }
      System.out.print("\n");
      for (int i = 0; i < vertice; i++) 
      { 
      	System.out.print((i+1)+"\t");
          for (int j = 0; j < vertice; j++) 
          { 
             
              	System.out.print (matrix[i][j]+"\t"); 
          } 
          System.out.print("\n"); 
      }
      
  } 

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("ENTER THE NUMBER OD VERTICES OF GRAPHS: ");
    int vertice = sc.nextInt();
    
    int matrix[][] = new int[vertice][vertice],i,j;
    for(i=0;i<vertice;i++) {
      
      for(j=0;j<vertice;j++) {
        System.out.print("ENTER MATRIX["+i+"]["+j+"]:");
        matrix[i][j]=sc.nextInt();
      }
    }
    min_dist (matrix,vertice);

  }

}

