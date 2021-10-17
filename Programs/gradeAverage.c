#include <stdio.h>

int main()
{
    int numStudents;
    double grades[50];
    int numGrades = 0, averageGrades = 0;

    // ask for number of students so that the number of prompts to enter nth number of student will not be as much as the array size of the available grades to input
    printf("Please enter number of students: ");
    scanf(" %d", &numStudents);

    for (int i = 0; i < numStudents; i++)
    {
        // var:i pertains to array position, var:j pertains to student number
        int j = i + 1;
        printf("Please enter grade for student %d: ", j);
        scanf(" %lf", &grades[i]);
        // break if there's a student whose score is zero
        // break position before the increment of number of valid grade inputs
        if (grades[i] == 0)
            continue;
        // add number of inputted grades as opposed to number of students which some may not even have grades
        numGrades++;
    }

    // compute only for valid number of grade inputs and not number of students
    for (int i = 0; i < numGrades; i++)
    {
        averageGrades += grades[i];
    }

    printf("There were a total of %d number of students. Average of %d students is %.2f", numStudents, numGrades, averageGrades / (double)numGrades);

    return 0;
}