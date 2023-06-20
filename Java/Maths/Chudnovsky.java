public class Chudnovsky {

    public static void main( String[ ] args ) {
        int k = 13;

        final String outputFormat = "%." + ( k - 1 ) + "f";

        double result = new Chudnovsky( ).calculateLoop( k );

        System.out.println( "result = " + String.format( outputFormat, result ) );
        System.out.println( "result = " + result );

        result = 1 / new Chudnovsky( ).calculateRecursive( k );

        System.out.println( "result = " + String.format( outputFormat, result ) );
        System.out.println( "result = " + result );
    }

    public double calculateLoop( int k ) {
        double result = 0;
        for ( int i = 0; i <= k; i++ ) {
            result = result + doCalc( i );
        }
        return 1 / result;
    }

    public double calculateRecursive( int k ) {
        if ( k == 0 ) { return doCalc( k ); }

        return doCalc( k ) + calculateRecursive( k - 1 );
    }

    public double doCalc( int k ) {
        double numerator = Math.pow( -1, k ) * factorial( 6 * k ) * ( 545140134 * k + 13591409 );
        double denominator = factorial( 3 * k ) * Math.pow( factorial( k ), 3 ) * Math.pow( 640320, 3 * k + 3.0 / 2.0 );
        return 12.0 * numerator / denominator;
    }

    public double factorial( int n ) {
        if ( n == 0 ) {
            return 1;
        } else {
            return n * factorial( n - 1 );
        }
    }

}
