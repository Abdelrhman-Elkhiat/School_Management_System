/********************************************************
*School Management System
*Author : Abdelrhman Elkhiat
*Last Updated : 21-6-2023
********************************************************/
#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<string.h>
#include <ctype.h>
/*******************************************************
 ********************** Defines **************************
 *******************************************************/
#define FOUND 1
#define NOT_FOUND -1
#define EMPTY_LIST 0
#define SWITCH_ON 1
#define SWITCH_OFF 0
#define AUTO_ID_SWITCH 1
#define NUM_SUB 8
#define CURRENT_YEAR 2023
 /******************************************************
  ********************** Typedefs ***********************
  ******************************************************/
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef struct grades {
	int ArrayDegrees[NUM_SUB];
	char ArrayGrades[NUM_SUB];
	int AccDegre;
	char AccGrade;
	struct grades* next;
}GradesList;
typedef struct date {
	int day;
	int month;
	int year;
}DateSt_t;
typedef struct student {
	char Name[50];
	char Gender;
	struct grades* Grades;
	DateSt_t Birthday;
	int  ID;
}StudentSt_t;
typedef StudentSt_t* ListEntry;
typedef struct listnode {
	ListEntry entry;
	struct listnode* next;
	struct listnode* prev;
}ListNode;
typedef struct list {
	ListNode* front;
	ListNode* rear;
	int size;
	int Max;
	int Min;
}List;
/********************************************************************
 ********************** Functions Prototypes ************************
 ********************************************************************/
void CreateList(List* PtrList);
char ListEmpty(List* PtrList);
char ListFull(List* PtrList);
int  Listsize(List* PtrList);
void ClearList(List* PtrList);
char CheckEntery(StudentSt_t* PtrSt);
void GetGrade(int Dgre, char* Grde);
void Create_Sort_Alph(List* Ptr_Alpha_List);
void Student_Score(List* PtrList, char* Subjects[]);
void Display_List(List* PtrList, char* Subjects[]);
void DeleteNode(List* PtrList, ListNode* PtrNode);
void InsertSortedDegree(List* PtrList, ListNode* PtrNode);
void RemoveNode(List* PtrList, ListNode* PtrNode);
void InsertListFront(List* PtrList, ListNode* PtrNode);
void InsertListrear(List* PtrList, ListNode* PtrNode);
void InsertSortedID(List* PtrList, ListNode* PtrNode);
void CreateStudent(List* PtrList, StudentSt_t* PtrSt);
void Display_Student(StudentSt_t* PtrSt, char* Subjects[]);
void IntializeNode(ListNode* PtrNode, StudentSt_t* PtrSt);
void DegreesEntery(GradesList* PtrGradLst, char* Subjects[]);
char SearchListID(List* PtrList, int ID, ListNode** PtrNode);
void Copy_List(List* Ptr_Original_List, List* Ptr_Copied_List);
void EditStudent(List* Ptr_List, StudentSt_t* PtrSt, int choice);
void MainMenu(List* Pdeg, List* Pal, List* Pid, char* Subjects[]);
void Create_Sorted_Degree(List* Ptr_List_Original, List* Ptr_Sorted_Degree);
#endif // SCHOOL_H_INCLUDED
