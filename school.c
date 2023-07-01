#include"school.h"
/*Pre: the lists Sorted_Alph,Sorted_Degree,Sorted_ID exist and intialized
  post: Sorted_ID Contains the list of students in a sorted manner */
void MainMenu(List* Ptr_List_Degree, List* Ptr_List_Alph, List* Ptr_List_ID, char* Subjects[])
{
    int Choice[5] = { 0 };
    int StudentID;
    StudentSt_t* Ptr_Stud_St = NULL;
    ListNode* Ptr_Node_ID = NULL;
    ListNode* Ptr_Node_Search = NULL;

    printf("*****************************************************\n******** Welcome to School Management System ********\n*****************************************************\n");
    do
    {
        printf("Please select required operation\n");
        printf("1) Adding New Student\n");
        printf("2) Deleting Existing Student\n");
        printf("3) Editing Existing Student\n");
        printf("4) Display Students In Alphabetical Order\n");
        printf("5) Display Students According to Grade\n");
        printf("6) Update Existing Students' Degrees\n");
        printf("7) Exit \n");
        /*scan user's input*/
        printf("Your Choice Is : ");
        scanf("%d", &Choice[0]);
        switch (Choice[0])
        {
            /*case 1: Adding new student*/
        case 1:
            /*creating student structure and creating a new node*/
            Ptr_Stud_St = (StudentSt_t*)malloc(sizeof(StudentSt_t));
            Ptr_Node_ID = (ListNode*)malloc(sizeof(ListNode));
            IntializeNode(Ptr_Node_ID, Ptr_Stud_St);
            /*filling the structure with user's input*/
            CreateStudent(Ptr_List_ID, Ptr_Stud_St);
            DegreesEntery(Ptr_Stud_St->Grades, Subjects);
            /*checks if the node is created*/
            if (CheckEntery(Ptr_Stud_St))
            {
                printf("*****************************************************\n***************** Successful Entry! *****************\n*****************************************************\n");
                Display_Student(Ptr_Stud_St, Subjects);
                /*adding the created node filled with data to the list in a sorted manner*/
                InsertSortedID(Ptr_List_ID, Ptr_Node_ID);
            }
            break;
            /*case 2: Deleting a student*/
        case 2:
            /*checks if there is a student already created and selected*/
            if (CheckEntery(Ptr_Stud_St))
            {
                /*taking the user input and checking if he wants to delete the current student entered previously or search data base for another student*/
                printf("Please Choose The Action You Need \n");
                printf("1)Delete Current Student\n");
                printf("2)Delete Student From Archive\n");
                printf("Your Choice Is : ");
                scanf("%d", &Choice[1]);
                switch (Choice[1])
                {
                    /*case : 1 Deleting a student entered previously*/
                case 1:
                    /*removing the student form the list then deallocating the memory*/
                    DeleteNode(Ptr_List_ID, Ptr_Node_ID);
                    Ptr_Stud_St = NULL;
                    printf("*****************************************************\n***************** Student Deleted ! *****************\n*****************************************************\n");
                    break;
                    /*case : 2 Deleting a student from database by ID*/
                case 2:
                    printf("Enter The ID of Student To Delete : ");
                    scanf("%d", &StudentID);
                    /*checking if the id entered by the user exists in database*/
                    if (FOUND == SearchListID(Ptr_List_ID, StudentID, &Ptr_Node_Search))
                    {
                        /*if found removing the student form the list then deallocating the memory*/
                        DeleteNode(Ptr_List_ID, Ptr_Node_Search);
                        Ptr_Stud_St = NULL;
                        printf("*****************************************************\n***************** Student Deleted ! *****************\n*****************************************************\n");
                    }
                    /*if student is not found prints out ID NOT FOUND*/
                    else
                    {
                        printf("\aSTUDENT ID NOT FOUND!\n");
                    }
                    break;
                default:
                    printf("\aYour Choice Was Invalid ENTER A VALID CHOICE!\n : ");
                    break;
                }
            }
            else
            {
                /*if there is no student entered previously or the student entered was deleted by user it will ask the user for the id if the list has elements*/
                if (!ListEmpty(Ptr_List_ID))
                {
                    /*in case of list in not empty*/
                    /*if found removing the student form the list then deallocating the memory*/
                    printf("Enter The ID of Student To Delete : ");
                    scanf("%d", &StudentID);
                    if (FOUND == SearchListID(Ptr_List_ID, StudentID, &Ptr_Node_Search))
                    {
                        DeleteNode(Ptr_List_ID, Ptr_Node_Search);
                        printf("*****************************************************\n***************** Student Deleted ! *****************\n*****************************************************\n");
                    }
                    /*if student is not found prints out ID NOT FOUND*/
                    else
                    {
                        printf("\aSTUDENT ID NOT FOUND!\n");
                    }
                }
                /*in case of list in empty*/
                else
                {
                    printf("\aLIST IS EMPTY! \n");
                }
            }
            break;
            /*case : 3 editing a student*/
        case 3:
            /*checks if there is a student already created and selected*/
            if (CheckEntery(Ptr_Stud_St))
            {
                printf("Please Choose The Action You Need \n");
                printf("1)Edit Current Student\n");
                printf("2)Edit Student From Archive\n");
                printf("Your Choice Is : ");
                scanf("%d", &Choice[1]);
                switch (Choice[1])
                {
                    /*in case of editing student already created*/
                case 1:
                    printf("Please Choose The Action You Need \n");
                    printf("1)Edit All Data \n");
                    printf("2)Edit Specific Field Student\n");
                    printf("Your Choice Is : ");
                    scanf("%d", &Choice[2]);
                    if (1 == Choice[2])
                    {
                        /*editing a student entered previously by over writing on the previous student the new data*/
                        CreateStudent(Ptr_List_ID, Ptr_Stud_St);
                        DegreesEntery(Ptr_Stud_St->Grades, Subjects);
                        /*removing the node as the id is changed and reinserting it again in the correct place*/
                        RemoveNode(Ptr_List_ID, Ptr_Node_ID);
                        InsertSortedID(Ptr_List_ID, Ptr_Node_ID);
                        printf("*****************************************************\n***************** Successful Edit ! *****************\n*****************************************************\n");
                        Display_Student(Ptr_Stud_St, Subjects);
                    }
                    /*editing a specific data field in current student*/
                    else if (2 == Choice[2])
                    {
                        printf("Please Choose The Field You Want To Edit \n");
                        printf("1)Edit Student ID\n");
                        printf("2)Edit Student Name\n");
                        printf("3)Edit Student Date Of Birth\n");
                        printf("4)Edit Student Gender\n");
                        printf("5)Edit Student Grades\n");
                        printf("Your Choice Is : ");
                        scanf("%d", &Choice[3]);
                        if (1 == Choice[3])
                        {
                            /*sending the user input to edit function with will edit the field selected by the user*/
                            EditStudent(Ptr_List_ID, Ptr_Node_ID->entry, Choice[3]);
                            /*removing the node as the id is changed and reinserting it again in the correct place*/
                            RemoveNode(Ptr_List_ID, Ptr_Node_ID);
                            InsertSortedID(Ptr_List_ID, Ptr_Node_ID);
                        }
                        else if (Choice[3] > 1 && Choice[3] < 5)
                        {
                            EditStudent(Ptr_List_ID, Ptr_Node_ID->entry, Choice[3]);
                        }
                        else if (5 == Choice[3])
                        {
                            /*refilling the degrees by over writing on previous data*/
                            DegreesEntery(Ptr_Node_ID->entry->Grades, Subjects);
                        }
                        printf("*****************************************************\n***************** Successful Edit ! *****************\n*****************************************************\n");
                        Display_Student(Ptr_Stud_St, Subjects);
                    }
                    break;
                case 2:
                    /*editing a student in database*/
                    printf("Please Choose The Action You Need\n");
                    printf("1)Edit All Data\n");
                    printf("2)Edit Specific Field Student\n");
                    printf("Your Choice Is : ");
                    scanf("%d", &Choice[2]);
                    if (1 == Choice[2])
                    {
                        /*editing all data for a student from archive*/
                        /*taking id from user*/
                        printf("Enter The ID of Student To Edit : ");
                        scanf("%d", &StudentID);
                        /*searching the id entered by the user to check if the student exists if found Ptr_Node_Search will now point to the node*/
                        if (FOUND == SearchListID(Ptr_List_ID, StudentID, &Ptr_Node_Search))
                        {
                            /*filling all data by accessing the node from pointer*/
                            CreateStudent(Ptr_List_ID, Ptr_Node_Search->entry);
                            DegreesEntery(Ptr_Node_Search->entry->Grades, Subjects);
                            /*removing the node as the id is changed and reinserting it again in the correct place*/
                            RemoveNode(Ptr_List_ID, Ptr_Node_Search);
                            InsertSortedID(Ptr_List_ID, Ptr_Node_Search);
                            printf("*****************************************************\n***************** Successful Edit ! *****************\n*****************************************************\n");
                            Display_Student(Ptr_Stud_St, Subjects);
                        }
                        else
                        {
                            printf("\aSTUDENT ID NOT FOUND!\n");
                        }
                    }
                    else if (2 == Choice[2])
                    {
                        printf("Enter The ID of Student To Edit : ");
                        scanf("%d", &StudentID);
                        printf("Please Choose The Field You Want To Edit \n");
                        printf("1)Edit Student ID\n");
                        printf("2)Edit Student Name\n");
                        printf("3)Edit Student Date Of Birth\n");
                        printf("4)Edit Student Gender\n");
                        printf("5)Edit Student Grades\n");
                        printf("Your Choice Is : ");
                        scanf("%d", &Choice[3]);
                        if (FOUND == SearchListID(Ptr_List_ID, StudentID, &Ptr_Node_Search))
                        {
                            if (1 == Choice[3])
                            {
                                EditStudent(Ptr_List_ID, Ptr_Node_Search->entry, Choice[3]);
                                RemoveNode(Ptr_List_ID, Ptr_Node_Search);
                                InsertSortedID(Ptr_List_ID, Ptr_Node_Search);
                            }
                            else if (Choice[3] > 1 && Choice[3] < 5)
                            {
                                EditStudent(Ptr_List_ID, Ptr_Node_Search->entry, Choice[3]);
                            }
                            else if (5 == Choice[3])
                            {
                                DegreesEntery(Ptr_Node_Search->entry->Grades, Subjects);
                            }
                            else
                            {
                                printf("\aYour Choice Was Invalid ENTER A VALID CHOICE!\n");
                            }
                            printf("*****************************************************\n***************** Successful Edit ! *****************\n*****************************************************\n");
                            Display_Student(Ptr_Node_Search->entry, Subjects);
                        }
                        else
                        {
                            printf("\aSTUDENT ID NOT FOUND!\n");
                        }
                        break;
                    }
                default:
                    break;
                }
            }
            else
            {
                if (!ListEmpty(Ptr_List_ID))
                {
                    printf("Enter The ID of Student To Edit : ");
                    scanf("%d", &StudentID);
                    printf("Please Choose The Field You Want To Edit \n");
                    printf("1)Edit Student ID\n");
                    printf("2)Edit Student Name\n");
                    printf("3)Edit Student Date Of Birth\n");
                    printf("4)Edit Student Gender\n");
                    printf("5)Edit Student Grades\n");
                    printf("Your Choice Is : ");
                    scanf("%d", &Choice[3]);
                    if (FOUND == SearchListID(Ptr_List_ID, StudentID, &Ptr_Node_Search))
                    {
                        if (1 == Choice[3])
                        {
                            EditStudent(Ptr_List_ID, Ptr_Node_Search->entry, Choice[3]);
                            RemoveNode(Ptr_List_ID, Ptr_Node_Search);
                            InsertSortedID(Ptr_List_ID, Ptr_Node_Search);
                        }
                        else if (Choice[3] > 1 && Choice[3] < 5)
                        {
                            EditStudent(Ptr_List_ID, Ptr_Node_Search->entry, Choice[3]);
                        }
                        else if (5 == Choice[3])
                        {
                            DegreesEntery(Ptr_Node_Search->entry->Grades, Subjects);
                        }
                        printf("*****************************************************\n***************** Successful Edit ! *****************\n*****************************************************\n");
                        Display_Student(Ptr_Node_Search->entry, Subjects);
                    }
                    else
                    {
                        printf("\aSTUDENT ID NOT FOUND!\n");
                    }
                }
                else
                {
                    printf("\aLIST IS EMPTY!There is No Data to Edit\n");
                }
            }
            break;
        case 4:
            if (!ListEmpty(Ptr_List_ID))
            {
                /*creating a copy from id list NOT SORTED in alphabetically*/
                Copy_List(Ptr_List_ID, Ptr_List_Alph);
                /*sorting the list alphabetically*/
                Create_Sort_Alph(Ptr_List_Alph);
                Display_List(Ptr_List_Alph, Subjects);
            }
            else
            {
                printf("\aLIST IS EMPTY! There is No Data to Display\n");
            }
            /*removing nodes and deallocating memory*/
            ClearList(Ptr_List_Alph);
            break;
        case 5:
            if (!ListEmpty(Ptr_List_ID))
            {
                Create_Sorted_Degree(Ptr_List_ID, Ptr_List_Degree);
                Display_List(Ptr_List_Degree, Subjects);
                ClearList(Ptr_List_Degree);
            }
            else
            {
                printf("\aLIST IS EMPTY! There is No Data to Display\n");
            }
            break;
        case 6:

            Student_Score(Ptr_List_ID, Subjects);
            break;
        case 7:
            printf("Are you Sure you want to Exit?\nEnter 1 to Confirm : ");
            scanf("%d", &Choice[1]);
            if (1 == Choice[1])
            {
                printf("BYE!");
            }
            else
            {
                Choice[0] = 0;
            }
            break;
        default:
            printf("\aYour Choice Is Invalid ENTER A VALID CHOICE!\n");
            break;
        }
    } while (7 != Choice[0]);
}
/*Pre: the list exists and intialized
  post: list intialized with front and rear pointers equals to NULL and size equals 0 */
void CreateList(List* PtrList)
{
    PtrList->front = NULL;
    PtrList->rear = NULL;
    PtrList->size = 0;
}
/*Pre: the list exists and intialized and have nodes
  post: front and rear pointers equals to NULL and size equals 0 also memory occupied by the list is freed*/
void ClearList(List* PtrList)
{
    ListNode* Ptr_Node = PtrList->front;
    while (PtrList->front)
    {
        Ptr_Node = PtrList->front;
        RemoveNode(PtrList, PtrList->front);
        free(Ptr_Node);
    }
    PtrList->rear = NULL;
    PtrList->front = NULL;
    PtrList->size = 0;
}
/*Pre: the list exists and intialized
  post: returns 1 in case of list have nodes returns 0 in case of list don't have nodes*/
char ListEmpty(List* PtrList)
{
    return !PtrList->size;
}
/* Pre: the list exists and intialized
   post: returns 0 in case heap is not full returns 1 in case of heap is full*/
char ListFull(List* PtrList)
{
    ListNode* Pn = (ListNode*)malloc(sizeof(ListNode));
    if (Pn)
    {
        free(Pn);
        return 1;
    }
    else
    {
        return 0;
    }
}
/* Pre: The stack exists
   Post: returns the number of elements*/
int  Listsize(List* Pl)
{
    return Pl->size;
}
/* Pre: Grde Exists
   Post: pass the corresponding grade to each Dgre passed by address in Grde*/
void GetGrade(int Dgre, char* Grde)
{
    if (Dgre > 100)
    {
        *Grde = 'E';
    }
    else if (Dgre > 84)
    {
        *Grde = 'A';
    }
    else if (Dgre > 74)
    {
        *Grde = 'B';
    }
    else if (Dgre > 64)
    {
        *Grde = 'C';
    }
    else if (Dgre > 49)
    {
        *Grde = 'D';
    }
    else if (Dgre >= 0)
    {
        *Grde = 'F';
    }
    else if (Dgre < 0)
    {
        *Grde = 'E';
    }
}
/* Pre: the structure exists
   Post: Fill the structure with users input*/
void CreateStudent(List* PtrList, StudentSt_t* PtrSt)
{
    int Temp_ID;
    ListNode* Ptr_Node_Search;
    if (AUTO_ID_SWITCH == SWITCH_OFF)
    {
        printf("Please Enter Student's ID : ");
        scanf("%d", &Temp_ID);
        while (FOUND == SearchListID(PtrList, Temp_ID, &Ptr_Node_Search))
        {
            printf("\aID ALREADY EXISIS !\nEnter Different ID : ");
            scanf("%d", &Temp_ID);
        }
    }
    else if (AUTO_ID_SWITCH == SWITCH_ON)
    {
        Temp_ID = PtrList->size + 1001;
        while (FOUND == SearchListID(PtrList, Temp_ID, &Ptr_Node_Search))
        {
            Temp_ID++;
        }
    }
    PtrSt->ID = Temp_ID;
    printf("Please Enter Student's Name : ");
    fflush(stdin);
    fgets(PtrSt->Name, 50, stdin);
    strlwr(PtrSt->Name);
    PtrSt->Name[0] = toupper(PtrSt->Name[0]);
    fflush(stdin);
    printf("Please Enter Student's Birthday (DD/MM/YEAR) : ");
    scanf("%d", &PtrSt->Birthday.day);
    getchar();
    scanf("%d", &PtrSt->Birthday.month);
    getchar();
    scanf("%d", &PtrSt->Birthday.year);
    printf("Please Enter Student's Gender : ");
    fflush(stdin);
    scanf("%c", &PtrSt->Gender);
}
/* Pre: the structure exists
   Post: Fill the structure with users input*/
void DegreesEntery(GradesList* PtrGradLst, char* Subjects[])
{
    int i;
    printf("Please Enter Student's Grades \n");
    PtrGradLst->AccDegre = 0;
    for (i = 0; i < NUM_SUB; i++)
    {
        printf("Enter Degree of %s : ", Subjects[i]);
        scanf("%d", &PtrGradLst->ArrayDegrees[i]);
        while (PtrGradLst->ArrayDegrees[i] < 0 || PtrGradLst->ArrayDegrees[i] > 100)
        {
            printf("\aENTER A DEGREE BTWEEN 0 AND 100!\nEnter Degree of %s : ", Subjects[i]);
            fflush(stdin);
            scanf("%d", &PtrGradLst->ArrayDegrees[i]);
        }
        GetGrade(PtrGradLst->ArrayDegrees[i], &PtrGradLst->ArrayGrades[i]);
        PtrGradLst->AccDegre += PtrGradLst->ArrayDegrees[i];
    }
    GetGrade(PtrGradLst->AccDegre / NUM_SUB, &PtrGradLst->AccGrade);
}
/* Pre: the structure exists
   Post: Prints out the structure's data*/
void Display_Student(StudentSt_t* PtrSt, char* Subjects[])
{
    int i;
    char YearCount = 0;
    GradesList* PtrGrdLst = PtrSt->Grades;
    printf("Student ID : %d\n", PtrSt->ID);
    printf("Student Name : %s", PtrSt->Name);
    printf("Student Date of Birth : %d/%d/%d\n", PtrSt->Birthday.day, PtrSt->Birthday.month, PtrSt->Birthday.year);
    printf("Student Gender : %c\n", PtrSt->Gender);
    while (PtrGrdLst)
    {
        printf("Degrees of %d Year\n", CURRENT_YEAR - YearCount);
        for (i = 0; i < NUM_SUB; i++)
        {
            printf("Student Degree of %s Is : %d Grade Is : %c\n", Subjects[i], PtrGrdLst->ArrayDegrees[i], PtrGrdLst->ArrayGrades[i]);
        }
        printf("Student Accumulative Degree Is : %.2f%% Grade Is : %c\n", (float)PtrGrdLst->AccDegre / NUM_SUB, PtrGrdLst->AccGrade);
        printf("*****************************************************\n");
        PtrGrdLst = PtrGrdLst->next;
        YearCount++;
    }

}
/* Pre:
   Post: return the status 1 or 0*/
char CheckEntery(StudentSt_t* PtrSt)
{
    if (PtrSt)
    {
        return 1;
    }
    else
        return 0;
}
/* Pre: the structure exists and list exists not empty
   Post: edit the structure data with users input*/
void EditStudent(List* Ptr_List, StudentSt_t* PtrSt, int choice)
{
    int Temp_ID = 0;
    ListNode* Ptr_Node = NULL;
    switch (choice)
    {
    case 1:
        printf("Please Enter Student's ID : ");
        scanf("%d", &Temp_ID);
        while (FOUND == SearchListID(Ptr_List, Temp_ID, &Ptr_Node))
        {
            printf("\aID ALREADY EXISIS !\nEnter Different ID : ");
            scanf("%d", &Temp_ID);
        }
        PtrSt->ID = Temp_ID;
        break;
    case 2:
        printf("Please Enter Student's Name : ");
        fflush(stdin);
        fgets(PtrSt->Name, 50, stdin);
        fflush(stdin);
        break;
    case 3:
        printf("Please Enter Student's Birthday (DD/MM/YEAR) : ");
        scanf("%d", &PtrSt->Birthday.day);
        getchar();
        scanf("%d", &PtrSt->Birthday.month);
        getchar();
        scanf("%d", &PtrSt->Birthday.year);
        break;
    case 4:
        printf("Please Enter Student's Gender : ");
        fflush(stdin);
        scanf("%c", &PtrSt->Gender);
        break;
    }
}
/* Pre: the list exists and the node exist
   Post: inserts the node in a sorted manner according to degree*/
void InsertSortedDegree(List* PtrList, ListNode* PtrNode)
{
    ListNode* PtrTemp = NULL;
    if (0 == PtrList->size)
    {
        PtrList->Max = PtrNode->entry->Grades->AccDegre;
        PtrList->Min = PtrNode->entry->Grades->AccDegre;
        PtrList->front = PtrNode;
        PtrList->rear = PtrNode;
    }
    else
    {
        if (PtrNode->entry->Grades->AccDegre >= PtrList->Max)
        {
            InsertListrear(PtrList, PtrNode);
            PtrList->Max = PtrNode->entry->Grades->AccDegre;
        }
        else if (PtrNode->entry->Grades->AccDegre > PtrList->Min)
        {
            if (((PtrList->Max + PtrList->Min) / 2) - PtrNode->entry->Grades->AccDegre >= 0)
            {
                PtrTemp = PtrList->front;
                while (PtrTemp && PtrTemp->next->entry->Grades->AccDegre < PtrNode->entry->Grades->AccDegre)
                {
                    PtrTemp = PtrTemp->next;
                }
                PtrNode->next = PtrTemp->next;
                PtrNode->prev = PtrTemp;
                PtrTemp->next->prev = PtrNode;
                PtrTemp->next = PtrNode;
            }
            else
            {
                PtrTemp = PtrList->rear;
                while (PtrTemp && PtrTemp->prev->entry->Grades->AccDegre > PtrNode->entry->Grades->AccDegre)
                {
                    PtrTemp = PtrTemp->prev;
                }
                PtrNode->next = PtrTemp;
                PtrNode->prev = PtrTemp->prev;
                PtrTemp->prev->next = PtrNode;
                PtrTemp->prev = PtrNode;
            }
        }
        else
        {
            InsertListFront(PtrList, PtrNode);
            PtrList->Min = PtrNode->entry->Grades->AccDegre;
        }
    }
    PtrList->size++;
}
/* Pre: the list exists and the node exist
   Post: inserts the node in a sorted manner according to id*/
void InsertSortedID(List* PtrList, ListNode* PtrNode)
{
    ListNode* PtrTemp = NULL;
    if (0 == PtrList->size)
    {
        PtrList->Max = PtrNode->entry->ID;
        PtrList->Min = PtrNode->entry->ID;
        PtrList->front = PtrNode;
        PtrList->rear = PtrNode;
    }
    else
    {
        if (PtrNode->entry->ID >= PtrList->Max)
        {
            InsertListrear(PtrList, PtrNode);
            PtrList->Max = PtrNode->entry->ID;
        }
        else if (PtrNode->entry->ID > PtrList->Min)
        {
            if (((PtrList->Max + PtrList->Min) / 2) - PtrNode->entry->ID >= 0)
            {
                PtrTemp = PtrList->front;
                while (PtrTemp && PtrTemp->next->entry->ID < PtrNode->entry->ID)
                {
                    PtrTemp = PtrTemp->next;
                }
                PtrNode->next = PtrTemp->next;
                PtrNode->prev = PtrTemp;
                PtrTemp->next->prev = PtrNode;
                PtrTemp->next = PtrNode;
            }
            else
            {
                PtrTemp = PtrList->rear;
                while (PtrTemp && PtrTemp->prev->entry->ID > PtrNode->entry->ID)
                {
                    PtrTemp = PtrTemp->prev;
                }
                PtrNode->next = PtrTemp;
                PtrNode->prev = PtrTemp->prev;
                PtrTemp->prev->next = PtrNode;
                PtrTemp->prev = PtrNode;
            }
        }
        else
        {
            InsertListFront(PtrList, PtrNode);
            PtrList->Min = PtrNode->entry->ID;
        }
    }
    PtrList->size++;
}
/* Pre: the node exists the structure exists
   Post: fill the node with a pointer to structure and allocates memory to grades and sets pointers to NULL*/
void IntializeNode(ListNode* PtrNode, StudentSt_t* PtrSt)
{
    PtrNode->entry = PtrSt;
    GradesList* PtrGrade = (GradesList*)malloc(sizeof(GradesList));
    PtrSt->Grades = PtrGrade;
    PtrSt->Grades->next = NULL;
    PtrNode->next = NULL;
    PtrNode->prev = NULL;
}
/* Pre: the node exists and the node exist
   Post: inserts the node in front of the list*/
void InsertListFront(List* PtrList, ListNode* PtrNode)
{
    PtrNode->prev = NULL;
    PtrNode->next = PtrList->front;
    PtrList->front = PtrNode;
    PtrNode->next->prev = PtrNode;
}
/* Pre: the node exists and has valid data
   Post: prints out the data inside the list*/
void Display_List(List* PtrList, char* Subjects[])
{
    int i;
    ListNode* PtrTemp = PtrList->front;
    for (i = 0; i < PtrList->size; i++)
    {
        Display_Student(PtrTemp->entry, Subjects);
        PtrTemp = PtrTemp->next;
    }
}
/* Pre: the node exists and the node exist
   Post: inserts the node in rear of the list*/
void InsertListrear(List* PtrList, ListNode* PtrNode)
{
    PtrNode->next = NULL;
    PtrNode->prev = PtrList->rear;
    PtrList->rear = PtrNode;
    PtrNode->prev->next = PtrNode;
}
/* Pre: the node exists and the list exists
   Post: removes the node from the list*/
void RemoveNode(List* PtrList, ListNode* PtrNode)
{
    if (1 == PtrList->size)
    {
        PtrList->front = NULL;
        PtrList->rear = NULL;
    }
    else if (2 == PtrList->size)
    {
        if (PtrList->front == PtrNode)
        {
            PtrNode->next->prev = NULL;
            PtrNode->next = NULL;
            PtrList->front = PtrList->rear;
        }
        else
        {
            PtrNode->prev->next = NULL;
            PtrNode->prev = NULL;
            PtrList->rear = PtrList->front;
        }
    }
    else
    {
        if (PtrList->front == PtrNode)
        {
            PtrNode->next->prev = NULL;
            PtrList->front = PtrNode->next;
            PtrNode->next = NULL;
        }
        else if (PtrList->rear == PtrNode)
        {
            PtrNode->prev->next = NULL;
            PtrList->rear = PtrNode->prev;
            PtrNode->prev = NULL;
        }
        else
        {
            PtrNode->next->prev = PtrNode->prev;
            PtrNode->prev->next = PtrNode->next;
            PtrNode->next = NULL;
            PtrNode->prev = NULL;
        }
    }
    PtrList->size--;
}
/* Pre: the node exists and the list exists
   Post: removes the node from the list the memory occupied by the node is freed*/
void DeleteNode(List* PtrList, ListNode* PtrNode)
{
    RemoveNode(PtrList, PtrNode);
    free(PtrNode->entry->Grades);
    PtrNode->entry->Grades = NULL;
    free(PtrNode->entry);
    PtrNode->entry = NULL;
    free(PtrNode);
    PtrNode = NULL;
}
/* Pre: the node exists and the list exists
   Post: returns whither the element is found or not or if list is empty searching by ID*/
char SearchListID(List* PtrList, int ID, ListNode** PtrNode)
{
    ListNode* PtrTemp;
    if (0 == PtrList->size)
    {
        return EMPTY_LIST;
    }
    else if (ID == PtrList->Max || ID == PtrList->Min)
    {
        if (ID == PtrList->Max)
        {
            *PtrNode = PtrList->rear;
            return FOUND;
        }
        else
        {
            *PtrNode = PtrList->front;
            return FOUND;
        }
    }
    else
    {
        if (ID > PtrList->Max)
        {
            return NOT_FOUND;
        }
        else if (ID > PtrList->Min)
        {
            if (((PtrList->Max + PtrList->Min) / 2) - ID >= 0)
            {
                PtrTemp = PtrList->front;
                while (PtrTemp && PtrTemp->next->entry->ID < ID)
                {
                    PtrTemp = PtrTemp->next;
                }
                if (PtrTemp)
                {
                    *PtrNode = PtrTemp->next;
                    return FOUND;
                }
                else
                {
                    return NOT_FOUND;
                }
            }
            else
            {
                PtrTemp = PtrList->rear;
                while (PtrTemp && PtrTemp->prev->entry->ID > ID)
                {
                    PtrTemp = PtrTemp->prev;
                }
                if (PtrTemp->entry->ID == ID)
                {
                    *PtrNode = PtrTemp->prev;
                    return FOUND;
                }
                else
                {
                    return NOT_FOUND;
                }
            }
        }
        else
        {
            return NOT_FOUND;
        }
    }
}
/* Pre: the list exists and have valid nodes
   Post: creates new stack element and fills its data from users input*/
void Student_Score(List* PtrList, char* Subjects[])
{
    ListNode* PtrNode = PtrList->front;

    while (PtrNode)
    {
        GradesList* PtrGradesNew = (GradesList*)malloc(sizeof(GradesList));
        printf("Student ID : %d\n", PtrNode->entry->ID);
        printf("Student Name : %s", PtrNode->entry->Name);
        DegreesEntery(PtrGradesNew, Subjects);
        PtrGradesNew->next = PtrNode->entry->Grades;
        PtrNode->entry->Grades = PtrGradesNew;
        PtrNode = PtrNode->next;
    }
}
/* Pre: the first list exists and have valid nodes second list exists and empty
   Post: allocates space and creates new nodes and copy first list's content to the second list*/
void Copy_List(List* Ptr_Original_List, List* Ptr_Copied_List)
{
    ListNode* Ptr_Node = NULL, * Ptr_Temp = NULL, * Ptr_Pre_Temp = NULL;
    Ptr_Node = Ptr_Original_List->front;

    while (Ptr_Node)
    {
        Ptr_Temp = (ListNode*)malloc(sizeof(ListNode));
        if (0 == Ptr_Copied_List->size)
        {
            Ptr_Copied_List->front = Ptr_Temp;
            Ptr_Temp->prev = NULL;

        }
        else
        {
            Ptr_Pre_Temp->next = Ptr_Temp;
            Ptr_Temp->prev = Ptr_Pre_Temp;
        }
        Ptr_Temp->entry = Ptr_Node->entry;
        Ptr_Pre_Temp = Ptr_Temp;
        Ptr_Node = Ptr_Node->next;
        Ptr_Copied_List->size++;
    }
    Ptr_Pre_Temp->next = NULL;
    Ptr_Copied_List->rear = Ptr_Pre_Temp;
}
/* Pre: the list exists and have valid nodes
   Post: swaps nodes content to create a list is sorted manner alphabetically */
void Create_Sort_Alph(List* Ptr_Alpha_List)
{
    ListNode* Ptr_Node = NULL, * Ptr_Temp = NULL;
    ListEntry Temp_Entry = NULL;
    Ptr_Node = Ptr_Alpha_List->front;
    Ptr_Temp = Ptr_Node->next;
    while (Ptr_Temp)
    {
        while (Ptr_Temp)
        {
            if (strcmp(Ptr_Node->entry->Name, Ptr_Temp->entry->Name) < 0)
            {
                Ptr_Temp = Ptr_Temp->next;
            }
            else
            {
                Temp_Entry = Ptr_Temp->entry;
                Ptr_Temp->entry = Ptr_Node->entry;
                Ptr_Node->entry = Temp_Entry;
                Ptr_Temp = Ptr_Temp->next;
            }
        }
        Ptr_Node = Ptr_Node->next;
        Ptr_Temp = Ptr_Node->next;
    }
}
/* Pre: the first list exists and have valid nodes second list exists and empty
   Post: allocates new nodes and inserts each content in the first list in a sorted manner to the second list*/
void Create_Sorted_Degree(List* Ptr_List_Original, List* Ptr_Sorted_Degree)
{
    ListNode* Ptr_Node_Temp = Ptr_List_Original->front;
    ListNode* Ptr_Node_Degre = NULL;
    while (Ptr_Node_Temp)
    {
        Ptr_Node_Degre = (ListNode*)malloc(sizeof(ListNode));
        Ptr_Node_Degre->entry = Ptr_Node_Temp->entry;
        InsertSortedDegree(Ptr_Sorted_Degree, Ptr_Node_Degre);
        Ptr_Node_Temp = Ptr_Node_Temp->next;
    }
}
