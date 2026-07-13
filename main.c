#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void displayStudents();
void deleteStudent();
void updateStudent();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while(1) {
        printf("\n----- Student Management System -----\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        Student s;
        printf("Enter student ID: ");
        scanf("%d", &s.id);
        printf("Enter student name: ");
        getchar();  
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';  
        printf("Enter student marks: ");
        scanf("%f", &s.marks);
        
        students[studentCount] = s;
        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Student list is full. Cannot add more students.\n");
    }
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n----- Student Records -----\n");
    int i;
    for (i = 0; i < studentCount; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("----------------------------\n");
    }
}

void deleteStudent() {
    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            int j;
            for (j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];  
            }
            studentCount--;
            printf("Student with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateStudent() {
    int id, found = 0;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter new student name: ");
            getchar();  
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';  
            
            printf("Enter new student marks: ");
            scanf("%f", &students[i].marks);
            
            printf("Student information updated successfully.\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

