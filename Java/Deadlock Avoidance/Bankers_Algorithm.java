/*
 ---------------------------------------------- Banker's Algorithm -------------------------------------------------------

    A algorithm which is used for resource allocation and deadlock avoidance in operating system. It is based on the
    concept of bank by allocating money to the requested user the bank should tally itself with money left in bank,
    likewise it works.
    It has two kind :-
            1) Safety Type
            2) Resource Request Type.

 ------------------------------------------------- Safety Type -----------------------------------------------------------

    1) To start with we should be able to allocate resources to all the process by executing any of the process
       need not be in a sequence manner.

    2) For writing the safe sequence of the process we should know the allocation of resources, maximum allocation,
       available resources and lastly the need matrix.

                    need matrix = maximum matrix - allocation matrix.

       the need matrix should not be negative or else we cannot allocate the available resources to the process.

    3) If the available resources of the process is greater than or equal to the needed resources of the process we can
       allocate the resources to that process or else we cannot allocate on top of that the process we allocated the
       resources will be finished at a certain time so the allocated resources will be free for that process we have to sum it.

                    available[process][resources] += allocation[process][resources]

    4) Since the available matrix is modified now we have to check again we can allocate the resources to the process we can't
       allocate resources before. Atlast we cannot allocate resources till now then we can say that DEADLOCK occurs.

 --------------------------------------------- Resource Request Type -----------------------------------------------------

    1) We have to allocate the additional resources requested by the process if we allocate the resources the system should not
       enter into DEADLOCK state.

    2) The requested additional resources should be less than the available resources and the need matrix of that process.

                    temp[resources] < need[process_no][resources]
                    temp[resources] < available[process_no][resources]

    3) Secondly we have to update the available, need and the allocation matrix with the additional resources.

                    need[process_no][i]-=temp[i];
                    available[0][i]-=temp[i];
                    allocation[process_no][i]+=temp[i];

    4) Then we have to check that if we allocate these additional resources to that process then we will be in a safe state
       by using the safety algorithm above.
       
 ------------------------------------------------- Complexities ----------------------------------------------------------
 
    Time Complexity  :- BigO(n*n*m)
    Space Complexity :- BigO(n*m)

 -------------------------------------------------- Drawbacks ------------------------------------------------------------

    1) It requires a fixed number of processes, and no additional processes can be started in the system
       while executing the process.

    2) The algorithm does no longer allows the processes to exchange its maximum needs while processing its tasks.

    3) Each process has to know their maximum resource requirement before starting the system.

*/

// Importing the Scanner class to read the input from user.
import java.util.Scanner;
public class Bankers_Algorithm
{
    // Declaring global variables, so we can use anywhere in the program.
    static Scanner sc;
    static int process;
    static int resources;
    static int allocation[][];
    static int maximum[][];
    static int available[][];
    static int temp_available[][];
    static int need[][];
    static int total[][];
    static int safesequence[];
    static boolean visited[];

    // The main method.
    public static void main(String[] args)
    {
        // Initializing he scanner class.
        sc = new Scanner(System.in);

        // Reading the number of process and number of resources from user.
        System.out.print("Enter number of process = ");
        process = sc.nextInt();
        System.out.print("Enter number of resources = ");
        resources = sc.nextInt();

        // Initializing all the declared variables.
        // The allocation matrix
        allocation = new int[process][resources];

        // The maximum matrix
        maximum = new int[process][resources];

        // The available matrix
        available = new int[process][resources];

        // Storing the available matrix in another matrix because the available matrix changes everytime, when the process allocated to bring
        // it to original available matrix this temp_available matrix will be used.
        temp_available = new int[process][resources];

        // The total resources going to be used by this process
        total = new int[1][resources];

        // The need matrix
        need = new int[process][resources];

        // The boolean visited matrix says about the process is allocated with the resources or not.
        visited = new boolean[process];

        // Lastly the answer matrix or the safe sequence matrix.
        safesequence = new int[process];

        // Reading the matrix inputs using this method.
        reading_input(process,resources);
    }

    // Reads the matrix inputs from the user
    private static void reading_input(int process, int resources)
    {
        // Reading the allocation matrix
        System.out.println("Allocation matrix,");
        for(int i=0;i<process;i++)
        {
            for(int j=0;j<resources;j++)
            {
                allocation[i][j] = sc.nextInt();
            }
        }

        // Reading the maximum matrix
        System.out.println("Maximum matrix,");
        for(int i=0;i<process;i++)
        {
            for(int j=0;j<resources;j++)
            {
                maximum[i][j] = sc.nextInt();
            }
        }

        // Calculating the need matrix
        // need matrix = maximum matrix - allocation matrix.
        for(int i=0;i<process;i++)
        {
            for(int j =0;j<resources;j++)
            {
                need[i][j] = maximum[i][j] - allocation[i][j];
                // The need matrix cannot be negative, if it is then we cannot allocate the resources.
                if(need[i][j] < 0)
                {
                    System.out.println("The allocation of resources are higher than the maximum resources");
                    System.out.println("It can't calculate the need matrix");
                    System.exit(0);
                }
            }
        }

        // Giving the choice to the user about if they know about any of these values we can allocate the resources.
        System.out.println("If you know available resources value then please enter 1 or if you know the total resources value" +
                " then enter 2");

        // Reading the choice of the user.
        int response = sc.nextInt();

        // Based on the choice entered the available resources will be calculated.
        switch (response)
        {
            // Directly reading the available resources from the user if user knows about it.
            case 1:
                System.out.println("Please enter the available resource value ");
                for(int i=0;i<resources;i++)
                {
                    available[0][i] = sc.nextInt();
                }
                break;
            // The user knows about total resources only so we are calculating the available resources from total resources.
            case 2:
                System.out.println("Please enter the total resource value ");
                for(int i=0;i<resources;i++)
                {
                    total[0][i] = sc.nextInt();
                }

                // Calculating the value of available matrix from the total and allocation.
                // Available matrix = total resources matrix - total allocated resources matrix.
                // Temporary array to store the total allocation matrix.
                int temp[][] = new int[1][resources];
                for(int j =0; j< resources;j++)
                {
                    int sum =0;
                    for(int i =0; i<process;i++)
                    {
                        sum+=allocation[i][j];
                    }
                    temp[0][j] = sum;
                }

                // Available matrix = total resources matrix - total allocated resources matrix.
                for(int i=0;i<resources;i++)
                {
                    available[0][i] = total[0][i] - temp[0][i];
                }
                break;
        }

        // Printing the readed value to the user before going to banker's algorithm
        printingvalues();
    }

    // Printing the readed values.
    private static void printingvalues()
    {
        // Printing the allocation matrix.
        System.out.println("Allocation Matrix :-");
        for(int i=0;i<process;i++)
        {
            for(int j=0;j<resources;j++)
            {
                System.out.print(allocation[i][j] + " ");
            }
            System.out.println();
        }

        // Printing the maximum matrix.
        System.out.println("Maximum Matrix :-");
        for(int i=0;i<process;i++)
        {
            for(int j=0;j<resources;j++)
            {
                System.out.print(maximum[i][j] + " ");
            }
            System.out.println();
        }

        // Printing the available resources.
        System.out.println("The available resources,");
        for(int i=0;i<resources;i++)
        {
            // The available resources cannot be less than 0, if it was then we can't allocate the resources to any tasks.
            if(available[0][i] <0)
            {
                System.out.println("The process is not having any available resource to allocate these tasks");
                System.exit(0);
            }
            System.out.print(available[0][i]+ " ");
            // Storing the available resources to temp_available resources matrix.
            temp_available[0][i] = available[0][i];
        }

        // Printing the need matrix.
        System.out.println("\nThe need matrix :-");
        for(int i=0;i<process;i++)
        {
            for(int j=0;j<resources;j++)
            {
                System.out.print(need[i][j] + " ");
            }
            System.out.println();
        }

        // Calling the banker's algo method to compute the banker's algorithm.
        bankersAlgo();
    }

    // Method which performs the banker's algorithm of SAFETY kind.
    private static void bankersAlgo()
    {
        // Counter variable to track, how many times the loop runs which should be less than the total process.
        int counter = 0;
        // The variable which says about the deadlock or the safe sequence.
        int l =0;
        // use loop to iterate, until all the processes are not finished.
        while (counter < process)
        {
            // find in-finished process which needs can be satisfied with the current available resource.
            boolean foundSafeSystem = false;
            // The banker's algo of first kind.
            for (int m = 0; m < process; m++)
            {
                // when process is not finished
                if (visited[m] == false)
                {
                    int j;
                    // Loop to check whether the need of each process for all the resources is less than the available resource.
                    for (j = 0; j < resources; j++)
                    {
                        //check need of current resource for current process with available.
                        if (need[m][j] > available[0][j])
                        {
                            break;
                        }

                    }
                    // j and total resources will be equal when all the needs of current process are satisfied
                    if (j == resources)
                    {
                        for (int k = 0; k < resources; k++)
                        {
                            available[0][k] += allocation[m][k];
                        }
                        // Add current process in the safesequence array
                        safesequence[counter++] = m;
                        // Make this process finished
                        visited[m] = true;
                        foundSafeSystem = true;
                    }
                }
            }
            // The condition of DeadLock.
            if (foundSafeSystem == false)
            {
                l = 1;
                System.out.println("The system is not in the safe state");
                System.out.println("----- DEADLOCK OCCURS -----");
                break;
            }
        }
        // Printing the safe sequence of the tasks.
        if(l!=1)
        {
            System.out.println("The safe sequence of the system is : ");
            for (int i = 0; i < process; i++)
            {
                if(i==process-1)
                {
                    System.out.println("P" + safesequence[i]);
                }
                else
                {
                   System.out.print("P" + safesequence[i] + " --> ");
                }
            }
        }
        // The second variety of banker's algo.
        // The resource request kind starts here.
        // Giving choice to user whether they want any additional resources to a process or not.
        System.out.println("\nDo you want any additional resources to be allocated to a process");
        System.out.println("Yes : 1, No : 2");

        // Reading the response from the user
        int response = sc.nextInt();

        // Performing based on the response by the user.
        switch (response)
        {
            // The user wants to allocate resources to a process.
            case 1:
                // Since the available matrix is changed by allocating the resources to all tasks.
                // We have to change it to original value.
                for(int i =0;i<resources;i++)
                {
                    available[0][i] = temp_available[0][i];
                }
                // Since the boolean array is changed to true we have to set it to false. To say whether the deadlock occurs or not.
                for(int i=0;i<process;i++)
                {
                    visited[i] = false;
                }
                // Calling the resource request method.
                resource_request();
                break;
            // The user doesn't want to allocate any resources to a process.
            case 2:
                // The program will be terminated.
                System.out.println("The program is terminated");
                System.exit(0);
                break;
        }
    }

    // The method which performs the resource request.
    private static void resource_request()
    {
        // Reading the process number which user wants to allocate additional resources.
        System.out.println("Enter the process number which you want additional resources");
        int process_no = sc.nextInt();

        // Temporary array to store the additional resources of that process.
        int temp[] = new int[resources];

        // Reading the additional resources values from the user.
        System.out.println("Enter the additional resources of that process");
        for(int i=0;i<resources;i++)
        {
            temp[i] = sc.nextInt();
            // The additional resources requested should be less than need matrix.
            if(temp[i] > need[process_no][i])
            {
                System.out.println("The additional resources you requested is exceeding the needed resources so I can't allocate" +
                        " or else system will enter into a UNSAFE STATE");
                System.exit(0);
            }
            // The additional resources requested should be less than available matrix.
            else if(temp[i] > available[0][i])
            {
                System.out.println("The additional resources you requested is exceeding the available resources so I can't allocate" +
                        " or else system will enter into a UNSAFE STATE");
                System.exit(0);
            }
        }

        // Updating the need, available, allocation matrix values to allocate the additional resources.
        for(int i=0;i<resources;i++)
        {
            need[process_no][i]-=temp[i];
            available[0][i]-=temp[i];
            allocation[process_no][i]+=temp[i];
        }

        // Calling the banker's algo of first kind to check that it will not cause any deadlock after allocating the additional resources.
        System.out.println("After allocating the resources you requested,");
        bankersAlgo();
    }
}
