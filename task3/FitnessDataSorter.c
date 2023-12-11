#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Define variable
#define MAX_RECORDS 1000
FitnessData records[MAX_RECORDS];
int record_count = 0;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to read data from file
int readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file ==NULL) {
        printf("File not found\n");
        return 1;
    }
    else {
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            tokeniseRecord(line, ',', records[record_count].date, records[record_count].time, &records[record_count].steps);
            record_count++;
        }
        fclose(file);
    }
    return 0;   
}

// Funtion to sort data
void SortData() {
    int i, j;
    FitnessData temp;

    for (i = 0; i < record_count - 1; i++) {
        for (j =0; j < record_count - i - 1; j++) {
            if (records[j].steps < records[j + 1].steps) {
                temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

//Function to write data to file
void WriteDataToFile(const char *filename) {
    char OutPutFilename[100];
    
    strcpy(OutPutFilename, filename);
    char *dot = strrchr(OutPutFilename, '.');
    if (dot != NULL) {
        *dot = '\0';
    }
    strcat(OutPutFilename, ".tsv");

    FILE *file = fopen(OutPutFilename, "w");

    if (file == NULL) {
        printf("Error opening file to write.\n");
        return;
    }

    for (int i = 0; i < record_count; i++) {
        fprintf(file, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);
    }

    fclose(file);
    printf("Data sorted and written to %s\n", OutPutFilename);
}

int main() {
    char filename[100];

    printf("Enter Filename: ");
    scanf("%s", filename);

    if (readCSV(filename) == 1) {
        return 1;
    }

    SortData();

    WriteDataToFile(filename);

    return 0;
}
