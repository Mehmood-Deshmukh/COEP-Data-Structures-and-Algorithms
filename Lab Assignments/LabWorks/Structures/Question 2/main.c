// Q.2 Using the structure from Question 1, write a program to display the details of the student whose 
// name is entered by the user. Display the name of the students who have secured less than 
// 40% of the aggregate. In addition, print each student’s average marks.  

#include <stdio.h>
#include <string.h>
#include "./logic.c"

#define MAX_STUDENTS 10
#define MAX_NAME_SIZE 20
int main(){
    Student Students[MAX_STUDENTS];
    int studentIndex = 0;
    char name[MAX_NAME_SIZE];

    Students[studentIndex].rollNumber = 1;
    Students[studentIndex].name = (Name){"Mehmood", "Rehan", "Deshmukh"};
    Students[studentIndex].gender = 'M';
    Students[studentIndex].DOB = (Date){3, 9, 2005};
    Students[studentIndex].marks = (Marks){85.7, 82.0, 94.3};
    studentIndex++;

    Students[studentIndex].rollNumber = 2;
    Students[studentIndex].name = (Name){"Yashwant", "Chandrakant", "Bhosale"};
    Students[studentIndex].gender = 'F';
    Students[studentIndex].DOB = (Date){1, 11, 2001};
    Students[studentIndex].marks = (Marks){95.0, 89.5, 100};
    studentIndex++;
    
    Students[studentIndex].rollNumber = 3;
    Students[studentIndex].name = (Name){"Deven", "Arunn", "Shinde"};
    Students[studentIndex].gender = 'M';
    Students[studentIndex].DOB = (Date){14, 11, 2005};
    Students[studentIndex].marks = (Marks){32.7, 65.3, 22.3};
    studentIndex++;

    printf("Enter name of student to get Details:\n");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<studentIndex; i++){
        if(strcmp(Students[i].name.firstName, name) == 0){
            found = 1;
            printDetails(Students[i]);
        }
    }

    if(!found) printf("Student with name %s not found\n", name);

    printf("**Average marks for each student**\n");

    for (int i = 0; i < studentIndex; ++i) {  
        float averageMarks = getAverageMarks(Students[i].marks);
        float aggregatePercentage = averageMarks;

        printf("%s %s %s has an average of %.2f%% marks\n",
                  Students[i].name.firstName, Students[i].name.middleName, Students[i].name.lastName, averageMarks);

        if (aggregatePercentage < 40) {
            printf("\n%s %s %s having the Roll Number %d has an average of %.2f%% marks and has secured less than 40%% aggregate.\n",
                   Students[i].name.firstName, Students[i].name.middleName, Students[i].name.lastName,
                   Students[i].rollNumber, averageMarks);
        }
    }



    return 0;
}
