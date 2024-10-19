#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Students {
    char studentName[30];
    int rollNum;
    double marks;
}studentInfo;

//Function to add and display student details
void addStudentRecords(studentInfo **students, int *numStudents) {
    char choice;
    
    do {
        *numStudents += 1;
        *students = realloc(*students, (*numStudents) * sizeof(studentInfo));
        
        if (*students == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(1);
        }
        
        studentInfo *currentStudent = &(*students)[*numStudents - 1];
        
        printf("\nEnter details for student %d:\n", *numStudents);
        
        printf("Name: ");
        scanf(" %[^\n]", currentStudent->studentName);
        
        printf("Roll Number: ");
        scanf("%d", &currentStudent->rollNum);
        
        printf("Marks: ");
        scanf("%lf", &currentStudent->marks);
        
        printf("\nDo you want to add another student? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    char userName[30];
    studentInfo *students = NULL;
    int numStudents = 0;

    printf("Please enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0; // Remove newline character
    printf("Welcome to the Student's record system, %s\n", userName);

    addStudentRecords(&students, &numStudents);

    // Print all student records
    printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].studentName);
        printf("Roll Number: %d\n", students[i].rollNum);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    // Free allocated memory
    free(students);

    return 0;
}