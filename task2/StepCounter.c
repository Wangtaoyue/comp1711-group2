#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
#define MAX_RECORDS 1000
FITNESS_DATA records[MAX_RECORDS];
int record_count = 0;

int readCSV(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return 0;
    }
    else {
        char line[100];
        record_count = 0;
        while (fgets(line, sizeof(line), file)) {
            char date[11], time[6], steps_str[10];
            tokeniseRecord(line, ",", date, time, steps_str);
            int steps = atoi(steps_str);
            if (record_count < MAX_RECORDS) {
                strcpy(records[record_count].date, date);
                strcpy(records[record_count].time, time);
                records[record_count].steps = steps;
                record_count++;
            }
            else {
                break;
            }
        }
        fclose(file);
        return 1;
    }
}

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
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

// Function for menu
void ShowTotalRecords() {
    printf("Total records: %d\n", record_count);
}

void FindFewStepPeriod() {
    if (record_count ==0) {
        printf("No data available.\n");
        return;
    }

    int FewSteps = records[0].steps;
    int FewIndex = 0;

    for (int i = 1; i < record_count; i++) {
        if(records[i].steps < FewSteps){
            FewSteps = records[i].steps;
            FewIndex = i;
        }
    }

    printf("Fewest steps: %s %s\n", records[FewIndex].date, records[FewIndex].time);
}

void FindLargeStepPeriod() {
    if (record_count == 0) {
        printf("No data available.\n");
        return;
    }

    int LargeSteps = records[0].steps;
    int LargeIndex = 0;

    for (int i = 1; i < record_count; i++) {
        if (records[i].steps > LargeSteps) {
            LargeSteps = records[i].steps;
            LargeIndex = i;
        }
    }

    printf("Largest steps: %s %s\n", records[LargeIndex].date, records[LargeIndex].time);
}

void CalculateMeanSteps() {
    if (record_count == 0) {
        return;
    }

    int totalSteps = 0;
    for (int i = 0; i < record_count; i++) {
        totalSteps += records[i].steps;
    }
    double MeanSteps = (double)totalSteps / record_count;
    printf("Mean step count: %.f\n", MeanSteps);
}

void FindLongestOver500StepsPeriod() {
    if (record_count == 0) {
        printf("No data available.\n");
        return;
    }
    
    int longestStart = 0, longestEnd = 0;
    int currentStart = 0, currentEnd = 0;
    int longestLength =0;

    for (int i = 0; i < record_count; i++) {
        if (records[i].steps > 500) {
            if (longestLength ==0) {
                currentStart = i;
                currentEnd = i;
            }
            else {
                currentEnd = i;
            }
            if (currentEnd - currentStart + 1 > longestLength) {
                longestLength = currentEnd - currentStart + 1;
                longestStart = currentStart;
                longestEnd = currentEnd;
            }
        }
        else{
            currentStart = i + 1;
        }
    }
    if (longestLength > 0) {
        printf("Longest period start: %s %s\nLongest period end: %s %s\n", records[longestStart].date, records[longestStart].time, records[longestEnd].date, records[longestEnd].time);
    }
    else {
        printf("No period over 500 steps found.\n");
    }
}

int main() {
   char filename[100];
   char choice;
   int fileLoaded = 0;

   while (1) {
    printf("\nMenu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'A': case 'a': 
            printf("Input filename: ");
            scanf("%s", filename);
            if (readCSV(filename) == 1) {
                fileLoaded = 1;
                printf("File successfully loaded.\n");
            }
            else {
                fileLoaded = 0;
            }
            break;
        case 'B': case 'b':
            if (fileLoaded) {
                ShowTotalRecords();
            }
            else {
                printf("No file loaded.\n");
            }
            break;
        case 'C': case 'c':
            if (fileLoaded) {
                FindFewStepPeriod();
            }
            else {
                printf("No file loaded.\n");
            }
            break;
        case 'D': case 'd':
            if (fileLoaded) {
                FindLargeStepPeriod();
            }
            else {
                printf("No file loaded.\n");
            }
            break;
        case 'E': case 'e':
            if (fileLoaded) {
                CalculateMeanSteps();
            }
            else {
                printf("No file loaded.\n");
            }
            break;
        case 'F': case 'f':
            if (fileLoaded) {
                FindLongestOver500StepsPeriod();
            }
            else {
                printf("No file loaded.\n");
            }
            break;
        case 'Q': case 'q':
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
    }
   }

   return 0;
}