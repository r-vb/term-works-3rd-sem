#include<stdio.h>

//structure
struct STUDENT{
    int rollno, marks1, marks2, marks3, cta, cie;
    char name[30];
};

struct STUDENT s;

//driver code
int main(){
        int small;
    printf("Enter the name of student: ");
    scanf("%s",s.name);
    printf("Enter the following data-");
    printf("Marks-1: ");  
    scanf("%d",&s.marks1);
    printf("Marks-2: ");  
    scanf("%d",&s.marks2);
    printf("Marks-3: ");  
    scanf("%d",&s.marks3);
    printf("CTA marks: ");
    scanf("%d",&s.cta);
    
    
    small = s.marks1;
    if(small > s.marks2)
        small = s.marks2;
    if(small > s.marks3)
        small = s.marks3;
    s.cie = s.cta+s.marks1+s.marks2+s.marks3-small;
    printf("\nCIE is: %d",s.cie);
return 0;
}
