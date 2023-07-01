/********************************************************
*School Management System
*Author : Abdelrhman Elkhiat
*Last Updated : 21-6-2023
********************************************************/
#include"school.c"
int main()
{
    char* Subjects[NUM_SUB] = { '\0' };
    Subjects[0] = "Arabic";
    Subjects[1] = "English";
    Subjects[2] = "Physics";
    Subjects[3] = "Chemistry";
    Subjects[4] = "Mathematics";
    Subjects[5] = "C.S";
    Subjects[6] = "History";
    Subjects[7] = "Arts";
    List  Sorted_Alph, Sorted_Degree, Sorted_ID;
    CreateList(&Sorted_Alph);
    CreateList(&Sorted_Degree);
    CreateList(&Sorted_ID);
    MainMenu(&Sorted_Degree, &Sorted_Alph, &Sorted_ID, Subjects);
    return 0;
}
