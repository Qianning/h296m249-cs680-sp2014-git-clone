/* 
Peiran Yang
u384w854
Pseudocode:
Let the user choice an option then run the function the user choice.
If the user does not want exit, then continual choice options.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double QsortTime;

//user menu and make the options for the user
char UserMenu( char *c )
{
	char choice;

	for ( choice = '0'; ( choice - 48 ) <= 0 || ( choice - 48 ) > 7; )
	{
		printf ( "\n----------------Menu----------------\n" );
		printf ( "0)Exit\n" );
		printf ( "1)Populate array\n" );
		printf ( "2)Copy array\n" );
		printf ( "3)Display array (first 10 items)\n" );
		printf ( "4)Quick Sort Ascending\n" );
		printf ( "5)Calculate Time for Quick Sort\n" );
		printf ( "Please select an option:\n" );
		scanf ( "\n%c", &choice );

		if ( choice - 48 <= 0 && choice - 48 > 5 )
		{
			printf ( "Option Error: No such option!\n" );
		}
		else if ( choice == '0' )
			return '0';
	}
	return choice;
}

void PopulateArray ( int *A )
{
	int i, j;
	srand ( time (0) );
	j = 0;

	for ( i = 10000; i > 0; i -- )
	{
		A[ j ] = i; //stores the value into the array
		j ++;
	}

	printf ( "\nPopulating done.\n" );
}

void CopyArrays ( int *array1, int *array2 )
{
	int i;

	for ( i = 0; i < 10000; i ++)
	{
		array2[ i ] = array1[ i ]; //copy the values from one array to another
	}

	printf ( "\nCopying done.\n" );
}

//Printing tha array for 10 items
void DisplayArray ( int *A )
{
	int i;

	for ( i = 0; i < 10; i ++ )
	printf ( "%d\n ", A[ i ] );
}

//Quick sort 
void QuickSort ( int *B, int first, int last )
{
    int p, j, t,i;

     if ( first < last )
	 {
         p = first; 
         i = first;
         j = last;

         while ( i < j )
		 {
             while ( B[ i ] <= B[ p] && i < last )
                 i ++;
             while ( B [ j ] > B[ p ] )
                 j --;
             if ( i < j )
			 {
                 t = B[ i ];
                 B[ i ] = B[ j ];
                 B[ j ] = t;
             }
         }

         t = B[ p ];
         B[ p ] = B[ j ];
         B[ j ] = t;
         QuickSort( B, first, j - 1 );
         QuickSort( B, j + 1, last ); 

    }
	
}

//calculate time
int CalculateTime ( int *A )
{
	time_t Begin, End;
	Begin = clock ();
	QuickSort ( A, 0, 9999 );

	printf("\nQuick Sort Done!\n");
	End = clock ();
	QsortTime = ( double ) ( End - Begin ) / CLOCKS_PER_SEC;

	return QsortTime;
}

void Exit ()
{
	exit (1);
}

int main ( void )
{
	char cSystem = '0';
	int Array1[ 10000 ], Array2[ 10000 ];

	printf ( "Welcome to CS460 HW 09 solution!\n" );

	for ( cSystem = UserMenu ( &cSystem ); cSystem - 48; cSystem = UserMenu ( &cSystem ) )
	{
		switch ( cSystem - 48 )
		{
			case 1:
				PopulateArray ( Array1 );//populate array
			break;
			case 2:
				CopyArrays ( Array1, Array2 );//copy array
			break;
			case 3:
				printf ( "Array 1:\n" );
				DisplayArray ( Array1 );//display array1
				printf ( "\nArray 2:\n" );
				DisplayArray ( Array2 );//display array2
				printf ( "\n" );
			break;
			case 4:
				CalculateTime ( Array1 );//calculate bubble sort time
			break;
			case 5:
				printf ( "Quick sort time is %lf\n", QsortTime );//print QsortTime
			break;
			
		}
	}
	Exit ();
	return 0;
}
