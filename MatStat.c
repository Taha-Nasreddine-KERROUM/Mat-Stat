#include <stdio.h>
#include <stdlib.h>

void readMatrix ( double ***m, int R, int C ) // r stands for rows, c for columns
{
    *m = (double **)malloc(R * sizeof(double *));
    if (*m == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    for (double **p = *m; p < *m + R; p++) {
        *p = (double *)malloc(C * sizeof(double));
        if (*p == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    
    for ( double **p = *m; p < *m + R; p++ )
    {
        for ( double *q = *p; q < *p + C; q++ )
        {
            printf(" V[%ld][%ld] = ", p - *m, q - *p );
            scanf("%lf", q);
        }
    }
    
}

void statistics ( double **m, int R, int C, double *min, double *max, double *mn )
{
    *min = **m;
    for ( double **p = m; p < m + R; p++ )
        for ( double *q = *p; q < *p + C; q++ ){
            if ( *max < *q )
                *max = *q;
            if ( *min > *q )
                *min = *q;
            *mn += *q;        
        }
    *mn /= ( R * C );
}

void displayMatrix ( double **m, int R, int C )
{
    for ( double **p = m; p < m + R; p++ ){
        for ( double *q = *p; q < *p + C; q++ )
            printf(" %.2lf\t", *q );
        printf("\n");    
    }    
}

int main()
{
    double **matrix, minimum, maximum = 0, mean = 0; int N, M;
    printf(" Enter the number of rows and columns:\n ");
    printf("rows = ");
    scanf("%d", &N);
    printf(" columns = ");
    scanf("%d", &M);
    readMatrix( &matrix, N, M );
    statistics ( matrix, N, M, &minimum, &maximum, &mean );
    displayMatrix( matrix, N, M );
    printf("\n mini = %.2lf\n max = %.2lf\n mean = %.2lf", minimum, maximum, mean);
    return 0;
}
