/**
 * Author: C Konstantinidis
 * Μεταπτυχιακο πληροφορικης
 * Αρ. Μητρώου: ΜΠΠΛ19029 
*/

//Βιβλιοθήκες
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

//Μέγεθος πίνακα δεδομένων
#define MDARRAY_LINES 10
#define MDARRAY_ELEMENTS_PER_LINE 5

//Γεννητρία τυχαιών αριθμών
#define UPPER_BOUND_RND 56 //Άνω όριο αρ. για την γεννητρια τυχαιών αριθμών
#define LOW_BOUND_RND -23   //Κάτω όριο αρ. για την γεννητρια τυχαιών αριθμών

//Πεδία
int data[MDARRAY_LINES][MDARRAY_ELEMENTS_PER_LINE];
int maxValue=0;
int minValue=0;
int index_line=0;
int index_of_where_in_line=0;

//Ορισμοί μεθόδων
bool isExist(int a);
void createRandomFilling();
void firstOccurence(int a);
void allTheOccurences(int a);
void getIndex(int a);
int maximumValue();
int minimumValue();
int secondMaxValue();
int getGeneSeed();
//int arrayLength(char a[]);

//Main function
int main(){
int char_to_find;
createRandomFilling();//Γεμισμα του πίνακα
maxValue=maximumValue();
minValue=minimumValue();
bool exit=true;

while(exit){
    printf("Options:\n");
    printf("1 - Find a given number if exists.\n");
    printf("2 - Find the first occurance of a given number.\n");
    printf("3 - Find all the occurance of a given number.\n");
    printf("4 - Find the the maximum number in the data set.\n");
    printf("5 - Find the minimum number in the data set.\n");
    printf("6 - Find the second biggest number in the data set.\n");
    printf("7 - return 0.;\n");
    printf("Please, enter your choice:");

    switch (getchar())
    {
    case '1':
        while ((getchar()) != '\n');  
        printf("\nPlease enter a number:");
        scanf("%d",&char_to_find);
        isExist(char_to_find);
        /* code */
        break;
    case '2':
        while ((getchar()) != '\n');
        printf("\nPlease enter a number:");
        scanf("%d",&char_to_find);
        firstOccurence(char_to_find);
        break;
    case '3':
        while ((getchar()) != '\n');
        printf("\nPlease enter a number:");
        scanf("%d",&char_to_find);
        allTheOccurences(char_to_find);
        break;
    case '4':
        while ((getchar()) != '\n');
        printf("Maximum value of the data set:%d\n",maxValue);
        break;
    case '5':
        printf("Minimum value of the data set:%d\n",minValue);
        break;
    case '6':
        printf("Second max value of the data set:%d\n",secondMaxValue());
        break;
    case '7':
        exit=false;
        break;
    default:
        printf("Please enter a number between 1 to 7\n");
        while ((getchar()) != '\n');
        break;
    }
    while ((getchar()) != '\n');
}
printf("r e t u r n  0\n");
return 0;
}

//Ερώτημα 1.Α
bool isExist(int a){
    bool output=false;
    printf("We search for %d\n",a);
    for (int i = 0; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
    {
        if(a==**(data+i)){
            printf("The given number exists.\n");
            output=true;
            break;
        }
    }
    if (!output){printf("The given number doesn\'t exist.\n");}
    return output;
}

//Ερώτημα 1.Β
void firstOccurence(int a){
    bool output=false;
    printf("We search for %d\n",a);
    for (int i = 0; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
    {
        if(a==**(data+i)){
            getIndex(i);
            printf("The input data occured in the %d itteration,in array index position [%d][%d]\n",i,index_line,index_of_where_in_line);
            output=true;
            break;
        }
    }
    if (!output){printf("The input number never occured\n");}
    return ;
}

//Ερώτημα 1.Γ & 1.Δ
void allTheOccurences(int a){
    bool output=false;
    int i=0;
    int count=1;
    printf("We search for %d\n",a);
    for (i = 0; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
    {
        /* code */
        if(a==**(data+i)){
            getIndex(i);
            printf("The input data occured %d time in the array index position [%d][%d]\n",count,index_line,index_of_where_in_line);
            count=++count;
            output=true;
        }
    }
    if(!output){printf("Given number doesn't exist.\n");}
}

//Ερώτημα 2.Α
int maximumValue(){
    int i;
    int a=**data;
    for (i = 1; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
    {
        /* code */
        if(a<**(data+i)){
            a=**(data+i);
        }
    }
    return a;
}
//Ερώτημα 2.Β
int minimumValue(){
    int i;
    int a=**data;
    for (i = 1; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
    {
        /* code */
        if(a>**(data+i)){
            a=**(data+i);
        }
    }
    return a;
}


//Ερώτημα 2.Γ
int secondMaxValue(){
    int i=0;
    int a=minValue;
    for (i = 0; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
    {
        //printf("Data:%d\n",**(data+i));
       /* code */
        if (**(data+i)!=maxValue){
           // printf("Data not equals to max Val\n");
            if (a<=**(data+i)){
                a=**(data+i);
             //   printf("Value is equal: %d\n",a);
            }
        }
    }
    return a;
}

//Μέθοδος δημιουργίας τυχαίων αριθμών
void createRandomFilling(){
int i;
int line=-1;
srand(getGeneSeed());
printf("Data created:\n");
for (i = 0; i < MDARRAY_LINES*MDARRAY_ELEMENTS_PER_LINE; i++)
{
    if((i%MDARRAY_ELEMENTS_PER_LINE)==0){
        ++line;
        printf("\nLine %d:",line);
    }
    /* code snippet "(rand()%(upper - lower + 1)) + lower" 
    το πήρα από το "https://www.geeksforgeeks.org/generating-random-number-range-c/" */
    **(data+i) =(char)((rand()%(UPPER_BOUND_RND - LOW_BOUND_RND + 1)) + LOW_BOUND_RND);
    printf(" %d ",**(data+i));
}
printf("\n");
}

//Δημιουργία τυχαίου gene seed για την γεννητρία
int getGeneSeed(){
     time_t result = time(NULL);
     printf("Random number seed created %jd\n",result);
     return result;
 }

//Μεθοδός υπολογισμού της γραμμής και το που στην γραμμή
 void getIndex(int a){
    index_line=a/MDARRAY_ELEMENTS_PER_LINE;
    index_of_where_in_line=a-(index_line*MDARRAY_ELEMENTS_PER_LINE);
}