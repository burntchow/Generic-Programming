/**
* Using the C qsort()
* https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/qsort?view=msvc-170
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Person struct
 * Holds name and age
 * Id: person 
 */
typedef struct Person{
  char name[10];
  int age;
}person;

/* Comparisons */

/* Comparing during sort. 
 * IN: 2 pointers to 2 elements to compare 
 * OUT: int <0, 0, >0 depending on comparison
 */
int compareNum(const void *a, const void *b) {
   return *(float*)a - *(float*)b;
}

/* Sorting numbers 
 * IN: float pointer, int length  
 * OUT: None, sorted in place 
 */
void sortNums(float* arr, int length){
  qsort(arr, length, sizeof(float), compareNum);
}

/* Comparing during sort. 
 * IN: 2 pointers to 2 elements to compare 
 * OUT: int <0, 0, >0 depending on comparison
 * using strcmp for comparing names of people
 */
int compareName(const void *a, const void *b){
  const person *p1 = a;
  const person *p2 = b;
  return strcmp(p1->name, p2->name);
}

/* Sorting names of people  
 * IN: person pointer, int number of people 
 * OUT: None, sorted in place 
 */
void sortNames(person* ppl, int pplNum){
  qsort(ppl, pplNum, sizeof(person), compareName);
}

/* Comparing during sort. 
 * IN: 2 pointers to 2 elements to compare 
 * OUT: int <0, 0, >0 depending on comparison
 * If ages equal then comparing names with strcmp
 */
int compareAge(const void *a, const void *b){
  const person *p1 = a;
  const person *p2 = b;
  if(p2->age == p1->age){
    return strcmp(p1->name, p2->name);
  }
  return p2->age - p1->age;
}

/* Sorting ages of people  
 * IN: person pointer, int number of people 
 * OUT: None, sorted in place 
 */
void sortAges(person* ppl, int pplNum){
  qsort(ppl, pplNum, sizeof(person), compareAge);
}

/* Print functions */

void print(float arr[], int n){
  for(int i = 0; i < n; i++){
    printf("%.2f ", arr[i]);
  }
}

void printppl(struct Person *person, int n){
  for(int i = 0; i < n; i++){
    printf("%s",person[i].name);
    printf(" ");
    printf("%d",person[i].age);  
    printf("\n");
  }
}

int main(void) {
  // Variables numbers and people defined 
  float numbers[12] = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
  
  struct Person people[17] = {{"Hal", 20},{"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};

  int numsLen = sizeof(numbers)/sizeof(float); 
  int population = sizeof(people)/sizeof(people[0]);

  // Sort numbers ascending by numerical value
  printf("==== Sort numbers ascending ====\n");
  printf("BEFORE: \n");
  print(numbers, numsLen);
  printf("\n\nAFTER: ");
  sortNums(numbers, numsLen);
  printf("\n");
  print(numbers, numsLen);

  // Sort people alphabetically (lexicograhically) by name 
  printf("\n\n==== Sort people alphabetically ====\n");
  printf("BEFORE: \n");
  printppl(people, population);
  sortNames(people, population);
  printf("\nAFTER: \n");
  printppl(people, population);

  // Sort people descending by age, where people of the same age should be sorted alphabetically 
  printf("\n==== Sort people descending by age ====\n");
  printf("BEFORE: \n");
  printppl(people, population);
  sortAges(people, population);
  printf("\n\nAFTER: \n");
  printppl(people, population);
  
  return 0;
}