#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here
#define MAX_RECORDS 1000

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Outputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main() {
    FILE *file;
    char buffer[100];
    FITNESS_DATA fitnessData[MAX_RECORDS];
    int numRecords = 0;

    file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL && numRecords < MAX_RECORDS) {
        // Tokenize the record and store in the FITNESS_DATA array
        char date[11], time[6], steps[10];
        tokeniseRecord(buffer, ",", date, time, steps);
        strcpy(fitnessData[numRecords].date, date);
        strcpy(fitnessData[numRecords].time, time);
        fitnessData[numRecords].steps = atoi(steps);
        numRecords++;
    }

    fclose(file);

    printf("Number of records in file: %d\n", numRecords);

    for (int i = 0; i < 3 && i < numRecords; i++) {
        printf("%s/%s/%d\n", fitnessData[i].date, fitnessData[i].time, fitnessData[i].steps);
    }

    return 0;
}
