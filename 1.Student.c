/*
Consider a structure named Student with attributes as SID, NAME,
BRANCH, SEMESTER, ADDRESS.
Write a program in C/C++/ and perform the following operations using
the concept of files.
a. Insert a new student
b. Modify the address of the student based on SID
c. Delete a student
d. List all the students
e. List all the students of CSE branch.
f. List all the students of CSE branch and reside in Kuvempunagar.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student {
    char SID[13];
    char NAME[25];
    char BRANCH[5];
    int SEMESTER;
    char ADDRESS[15];
};

FILE *fp;

void insertstd() {
    fp = fopen("studentrec.txt","a");
    if (fp == NULL)
    {
        printf("Error....!");
        return;
    }
    struct Student std;
    printf("\nEnter details of student\n");
    printf("Name: ");     scanf("%s",std.NAME);
    printf("Student-ID: ");     scanf("%s",std.SID);
    printf("Branch: ");     scanf("%s",std.BRANCH);
    printf("Semester: ");   scanf("%d",&std.SEMESTER);
    printf("Address: ");    scanf("%s",std.ADDRESS);
    fwrite(&std, sizeof(std),1,fp);
    fclose(fp);
}

void liststd() {
    struct Student std;
    fp = fopen("studentrec.txt","r");
    if (fp == NULL)
    {
        printf("Error....!");
        return;
    }
    fseek(fp,0,SEEK_END);
    printf("Number of records found: %ld\n",(ftell(fp)/sizeof(struct Student)));
    rewind(fp);
    while(fread(&std,sizeof(std),1,fp)) 
    {
        printf("Name: %s",std.NAME);
        printf("\tStudent ID: %s",std.SID);
        printf("\tBranch: %s",std.BRANCH);
        printf("\tSemester: %d",std.SEMESTER);
        printf("\tAddress: %s\n",std.ADDRESS);
    }    
    fclose(fp);
}

void liststdcse()
{
    struct Student std;
    int found = 0;
    fp = fopen("studentrec.txt","r");
    if (fp == NULL)
    {
        printf("Error....!");
        return;
    }
    while(fread(&std,sizeof(std),1,fp)) 
        if(strcmp(std.BRANCH,"CSE") == 0) 
        {
            printf("Name: %s",std.NAME);
            printf("\tStudent ID: %s",std.SID);
            printf("\tBranch: %s",std.BRANCH);
            printf("\tSemester: %d",std.SEMESTER);
            printf("\tAddress: %s\n",std.ADDRESS);
            found = 1;
        }    
    if (!found)
        printf("No records of CSE students found.....!\n");
    fclose(fp);
}

void liststdcsekuv()
{
    struct Student std;
    int found = 0;
    fp = fopen("studentrec.txt","r");
    if (fp == NULL)
    {
        printf("Error....!");
        return;
    }
    while(fread(&std,sizeof(std),1,fp)) 
        if((strcmp(std.BRANCH,"CSE") == 0) && (strcmp(std.ADDRESS,"KUVEMPUNAGAR") == 0)) 
        {
            printf("Name: %s",std.NAME);
            printf("\tStudent ID: %s",std.SID);
            printf("\tBranch: %s",std.BRANCH);
            printf("\tSemester: %d",std.SEMESTER);
            printf("\tAddress: %s\n",std.ADDRESS);
            found = 1;
        }    
    if (!found)
        printf("No records of CSE students residing in Kuvempunagar found.....!\n");
    fclose(fp);
}

void modifyadd() 
{
    struct Student std, modifystd;
    int found = 0;
    char ID[13], newadd[25];
    fp = fopen("studentrec.txt","r");
    FILE *temp = fopen("temp.txt","a");
    if (fp == NULL || temp == NULL)
    {
        printf("Error....!");
        return;
    }
    printf("Enter student-ID: ");   scanf("%s",ID);
    while(fread(&std,sizeof(std),1,fp))
    {
        if(strcmp(std.SID,ID) == 0)
        {
            found = 1;
            printf("Enter new address: ");  scanf("%s",newadd);
            strcpy(modifystd.SID,std.SID);
            strcpy(modifystd.NAME,std.NAME);
            strcpy(modifystd.BRANCH,std.BRANCH);
            modifystd.SEMESTER = std.SEMESTER;
            strcpy(modifystd.ADDRESS,newadd);
        }
        else
            fwrite(&std, sizeof(std),1,temp);
    }
    fclose(fp);
    fclose(temp);
    if (!found)
        printf("No records found with Student-ID: %s\n",ID);
    else
    {
        fp = fopen("studentrec.txt","w");
        temp = fopen("temp.txt","r");
        printf("Record updated successfully\n");
        fwrite(&modifystd, sizeof(modifystd),1,fp);  
        while(fread(&std,sizeof(std),1,temp))
            fwrite(&std, sizeof(std),1,fp);
        fclose(fp);
    } 
    remove("temp.txt");
}

void deletestd() 
{
    struct Student std;
    int found = 0;
    char ID[13];
    fp = fopen("studentrec.txt","r");
    FILE *temp = fopen("temp.txt","w");
    if (fp == NULL || temp == NULL)
    {
        printf("Error....!");
        return;
    }
    printf("Enter student-ID: ");   scanf("%s",ID);
    while(fread(&std,sizeof(std),1,fp)) 
    {
        if(strcmp(std.SID,ID) == 0) 
            found = 1;
        else
            fwrite(&std, sizeof(std),1,temp);
    }
    if (!found)
        printf("No records found with Student-ID: %s\n",ID);
    else
    {
        printf("Record deleted successfully\n");
        remove("studentrec.txt");
        rename("temp.txt","studentrec.txt");
    }    
    fclose(temp);  
}

void main() {
    fp = fopen("studentrec.txt","w");
    printf("\nEnter\n1. To insert a new student\n2. To modify the address of the student based on SID\n3. To delete a student\n4. To list all the students\n5. To list all the students of CSE branch\n6. To list all the students of CSE branch and reside in Kuvempunagar\n0. To exit");
    int ch;
    while (1)
    {
        printf("\nEnter your choice: ");  scanf("%d",&ch);
        switch (ch)
        {
            case 1: insertstd();    break;
            case 2: modifyadd();    break;
            case 3: deletestd();    break;
            case 4: liststd();     break;
            case 5: liststdcse();  break;
            case 6: liststdcsekuv();  break;
            case 0: exit(0);    
            default: printf("Invalid choice.....!"); break;
        }
    }
    fclose(fp);
}
