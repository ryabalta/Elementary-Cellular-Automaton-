#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
    char *endptr1, *endptr2, *endptr3;
    int cells, generations, mid;
    int left, right, binaryVal, pTwo;
    unsigned int wCode;
    int *curArr, *nextArr, *temp;
    int i, j, g, b;

    /* checking if user entered a value or not */
    if (argc != 4) { 
        printf("Value could not found.\n");
        return -1;
    }

    /* reading the input strings and converting into integers */
    cells = strtol(argv[1], &endptr1, 10); 
    generations = strtol(argv[2], &endptr2, 10);
    wCode = strtol(argv[3], &endptr3, 10);

    /* validating the value */
    if (*endptr1 != '\0' || *endptr2 != '\0' || *endptr3 != '\0') {
        printf("Invalid value.\n");
        return -1;
    }

    /* checking the value range*/
    if(cells <= 0 || generations <= 0 || wCode < 0 || wCode > 255){
        printf("Value out of range.\n");
        return -1;
    }

    /* dynamically allocating two arrays to store the state of cells*/
    curArr = (int *) calloc(cells, sizeof(int));
    nextArr = (int *) calloc(cells, sizeof(int));

    /* checking whether the heap is full or not */
    if (curArr == NULL || nextArr == NULL) {
        free(curArr);
        free(nextArr);
        exit (EXIT_FAILURE);
    }

    /* printing generation 0 */
    mid = cells / 2;
    curArr[mid] = 1;

    for (i = 0; i < cells; i++) {
        if (curArr[i] == 1) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    /* main loop to compute the logic */
    for (i = 1; i < generations; i++) {
        for (j = 0; j < cells; j++) {
            /* setting the neighbour cells */
            if (j == 0) {
                left = cells - 1;
            } else {
                left = j - 1;
            }

            if (j == cells - 1) {
                right = 0;
            } else {
                right = j + 1; 
            }
            
            /* converting the rule number into binary */
            binaryVal = (4 * (curArr[left]) + 2 * (curArr[j]) + curArr[right]);

            /* determining the next generation state of the cell */
            pTwo = 1;
            for(b = 0; b < binaryVal; b++){
                pTwo = pTwo * 2;
            }

            nextArr[j] = (wCode / pTwo) % 2;
        }   

        /* printing next generation */
        for (g = 0 ; g < cells; g++) {
            if (nextArr[g] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        printf("\n");

        /* swapping the arrays so that the current changes */
        temp = curArr;
        curArr = nextArr;
        nextArr = temp;
    }

    free(curArr);
    free(nextArr);

    return 0; 
}