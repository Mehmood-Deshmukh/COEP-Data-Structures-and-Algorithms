// Q.1 Declare a structure that represents the following hierarchical information: 
// to Remember 

//     (a) Student 
//     (b) Roll Number 
//     (c) Name (Typedef) 
//         (i) First name 
//         (ii) Middle Name 
//         (iii) Last Name 
//     (d) Gender 
//     (e) Date of Birth (Typedef) 
//         (i) Day 
//         (ii) Month 
//         (iii) Year 
//     (f) Marks (typedef) 
//         (i) English 
//         (ii) Mathematics 
//         (iii) Computer Science 

typedef struct Name{
    char *firstName;
    char *middleName;
    char *lastName;
} Name;

typedef struct Date{
    int day;
    int month;
    int year;
} Date;

typedef struct Marks{
    int english;
    int mathematics;
    int computerScience;
} Marks;

typedef struct Student{
    int rollNumber;
    Name name;
    char gender;
    Date DOB;
    Marks marks;
} Student;

