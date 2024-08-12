#include "./header.h"

float getAverageMarks(Marks marks){
    return (float)(marks.english + marks.mathematics + marks.computerScience) / 3;
}

void printDetails(Student Student){
    printf("Rollnumber: %d\n", Student.rollNumber);
    printf("Name: %s %s %s\n", Student.name.firstName, Student.name.middleName, Student.name.lastName);
    printf("Gender: %c\n", Student.gender);
    printf("DOB: %d/%d/%d\n", Student.DOB.day,Student.DOB.month,Student.DOB.year);
    printf("Marks: English: %d Mathematics: %d Computer Science: %d\n\n",Student.marks.english, Student.marks.mathematics, Student.marks.computerScience);
}