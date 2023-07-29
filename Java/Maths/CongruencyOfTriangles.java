    // Congruency of Triangles Program
    // It can be used to check whether the two traingles are congruent or not.
    // Author: @swastik-akhil


    public class CongruencyOfTriangles {
        public static void main(String[] args) {
            
            // SSS property

            int a1 = 3, b1 = 4, c1 = 5;
            int a2 = 3, b2 = 4, c2 = 5;
            if (a1==a2 && b1==b2 && c1==c2) {
                System.out.println("The triangles are congruent");
            }
            else {
                System.out.println("The triangles are not congruent");
            }

            // SAS property

            int a3= 3,m = 50, b3 = 4 ;
            int a4 = 3, n = 50, b4 = 4;
            if (a3==a4 && b3==b4 && m == n) {
                System.out.println("The triangles are congruent");
            }
            else {
                System.out.println("The triangles are not congruent");
            }

            // ASA property

            int m1 = 40 , a5 = 3, m2 = 60;
            int m3 = 40 , a6 = 3, m4 = 60;
            if (m1==m3 && m2==m4 && a5==a6) {
                System.out.println("The triangles are congruent");
            }
            else {
                System.out.println("The triangles are not congruent");
            }

            // AAS property

            int m5 = 40 , m6 = 60, a7 = 6;
            int m7 = 40 , m8 = 60, a8 = 6;
            if (m5==m7 && m6==m8 && a7==a8) {
                System.out.println("The triangles are congruent");
            }
            else {
                System.out.println("The triangles are not congruent");
            }

            // RHS property

            int a9 = 3, b5 = 4;
            int a10 = 3, b6 = 4;
            if (a9==a10 && b5==b6) {
                System.out.println("The triangles are congruent");
            }
            else {
                System.out.println("The triangles are not congruent");
            }

    //Note that SSSA is not the sufficient condition for congruency of triangles.



        }
    }
