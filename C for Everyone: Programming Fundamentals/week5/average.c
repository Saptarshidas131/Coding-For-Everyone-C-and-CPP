/* Calculate average weight of elephant seals */

#include <stdio.h>

#include <stdlib.h>

#include <malloc.h>

// function to calculate average
double average(int row,int column,int mat[row][column])

{

    int a;

    int b;

    double sum=0.0;

    for(a=0;a<row;a++)

        for(b=0;b<column;b++)

            sum+=mat[a][b];

    return(sum/1000);

}


int main()

{

    int i;

    int j;

    int r=50;

    int col=20;

    int** mat=malloc(r*sizeof(int*));
 
   for(i=0;i<r;++i)

    // find size of int multiplied by r
    mat[i]=malloc(r*sizeof(int));

    // declaring file pointer
    FILE *file;

	// opening data.txt file in read mode
    file=fopen("data.txt", "r");

	// iterating through the data in data.txt
    for(i = 0; i < 1000; i++)

    {

        for(j = 0; j <col; j++)
 
       {

            if (!fscanf(file, "%d", &mat[i][j]))
 
           break;

            printf("%d\t",mat[i][j]);
 
           if(j==col-1)

            {

                printf("\n\n");

            }

	    // print average
            printf("Average of elephant seal is %.2f\n\n",average(r,col,mat));

        }

    }

    // closing file
    fclose(file);

    return 0;

}

