#include <stdio.h>
#include <stdlib.h>

// External GAS function declaration
extern int sum_array(const int *arr, int count);

int main(int argc, char *argv[]) {
    // 1. Verify command line arguments
    if (argc < 2) {
        printf("Usage: %s <data_file_name>\n", argv[0]);
        return 1;
    }

    // 2. Open the input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // 3. Read the total number of data points (first line)
    int count = 0;
    if (fscanf(file, "%d", &count) != 1 || count <= 0) {
        fprintf(stderr, "Error reading valid data point count from file.\n");
        fclose(file);
        return 1;
    }

    // 4. Allocate memory for the array
    int *array = (int *)malloc(count * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // 5. Read integers into the memory array
    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            fprintf(stderr, "Error reading data element at index %d\n", i);
            free(array);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // 6. Call the x86-64 assembly routine (%rdi = array, %rsi = count)
    int total_sum = sum_array(array, count);

    // 7. Output the sum
    printf("Sum: %d\n", total_sum);

    // Clean up memory
    free(array);
    return 0;
}
