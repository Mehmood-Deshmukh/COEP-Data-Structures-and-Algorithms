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


float getAverageMarks(Marks marks);
void printDetails(Student Student);