/**
 * Author: C Konstantinidis
 * Μεταπτυχιακο πληροφορικης
 * Αρ. Μητρώου: ΜΠΠΛ19029
 * 
 *  
*/
//Βιβλιοθήκες
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

//Ορισμοί σταθερών
#define ELEMENTS 100 //Μέγεθος πίνακα δεδομένων
#define UPPER_BOUND_RND 56 //Άνω όριο αρ. για την γεννητρια τυχαιών αριθμών
#define LOW_BOUND_RND -23   //Κάτω όριο αρ. για την γεννητρια τυχαιών αριθμών

//Πεδία
int data[ELEMENTS];
int maxValue=0;
int minValue=0;

//Δηλώσεις Mέθοδων
bool isExist(int a);
void createRandomFilling();
void firstOccurence(int a);
void allTheOccurences(int a);
int getGeneSeed();
int maximumValue();
int minimumValue();
int secondMaxValue();

//Main function
int main(){
//Αλλάγη του gene seed της γεννήτριας
srand(getGeneSeed());
int char_to_find;
createRandomFilling();//Γεμισμα του πίνακα
maxValue=maximumValue();//Προ-υπολογισμός τον max kai min
minValue=minimumValue();
//Σημαφόρος για την έξοδο από το while loop
bool exit=true;
//Μενού επιλογών
while(exit){
    printf("Options:\n");
    printf("1 - Does a number exists in the data set.\n");
    printf("2 - Find the first occurance of a number in the data set.\n");
    printf("3 - Find all the occurance of a number in the data set.\n");
    printf("4 - Find the the maximum number in the data set.\n");
    printf("5 - Find the minimum number in the data set.\n");
    printf("6 - Find the second biggest number in the data set.\n");
    printf("7 - return 0.;\n");
    printf("Please, enter your choice:");
    //Έλεγχος της εισόδου του χρήστη
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
    for (int i = 0; i < ELEMENTS; i++)
    {
        if(a==*(data+i)){
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
    //Σημαφόρος για το μήνυμα μη έυρεσης του αριθμού
    bool output=false;
    printf("We search for %d\n",a);
    for (int i = 0; i < ELEMENTS; i++)
    {
        if(a==*(data+i)){
            printf("The input data occured first time in the array index position %d\n",i);
            output=true;
            break;
        }
    }
    if (!output){printf("The input number never occured\n");}
    return ;
}
//Ερώτημα 1.Γ & 1.Δ τα ενοποιήσα κατα λάθος
void allTheOccurences(int a){
    bool output=false;
    int i=0;
    int count=1;
    printf("We search for %d\n",a);
    for (i = 0; i < ELEMENTS; i++)
    {
        /* code */
        if(a==*(data+i)){
            printf("The input data occured %d time in the array index position %d\n",count,i);
            count=++count;
            output=true;
        }
    }
    if(!output){printf("Given number doesn't exist.\n");}
}

//Ερώτημα 1.Ε
int secondMaxValue(){
    int i=0;
    int a=minValue;
    for (i = 0; i < ELEMENTS; i++)
    {
        //printf("Data:%d\n",*(data+i));
       /* code */
        if (*(data+i)!=maxValue){
           // printf("Data not equals to max Val\n");
            if (a<=*(data+i)){
                a=*(data+i);
             //   printf("Value is equal: %d\n",a);
            }
        }
    }
    return a;
}

//Ερώτημα 2.A 
int maximumValue(){
    int i;
    int a=*data;
    for (i = 1; i < ELEMENTS; i++)
    {
        /* code */
        if(a<*(data+i)){
            a=*(data+i);
        }
    }
    return a;
}

//Ερώτημα 2.A
int minimumValue(){
    int i;
    int a=*data;
    for (i = 1; i < ELEMENTS; i++)
    {
        /* code */
        if(a>*(data+i)){
            a=*(data+i);
        }
    }
    return a;
}

//Μέθοδος παραγωγής data set τυχαίων αριθμών
void createRandomFilling(){
//Μέθοδος δημιουργίας τυχαίων αριθμών
    int i;
    printf("Data created:");
    for (i = 0; i < ELEMENTS; i++)
    {
    /* code snippet "(rand()%(upper - lower + 1)) + lower" 
    το πήρα από το "https://www.geeksforgeeks.org/generating-random-number-range-c/" */
        *(data+i) =(char)((rand()%(UPPER_BOUND_RND - LOW_BOUND_RND + 1)) + LOW_BOUND_RND);
        printf(" %d ",*(data+i));
    }
    printf("\n");
}

//Μέθοδος αλλαγής του gene seed της γεννητρίας παραγωγής τυχαιών αριθμών
 int getGeneSeed(){
     time_t result = time(NULL);
     printf("Random number seed created %jd\n",result);
     return result;
 }
