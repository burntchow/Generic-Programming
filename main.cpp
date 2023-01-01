/**
 * Using the C++ sort() 
 * https://cplusplus.com/reference/algorithm/sort/
 */

#include <iostream>
#include <algorithm>
using namespace std; 

/* Person class 
 * Defined by name and age 
 */
class Person{
  string name;
  int age; 
  public:
  Person(string n, int a){
    name = n;
    age = a; 
  }
  string getName(){
    return name;
  }
  int getAge(){
    return age;
  }
  void display(){
    cout << name << ", " << age << endl;
  }
};

/* Comparisons */

/* Sorting numbers 
 * IN: float array, int length of array 
 * OUT: None, array is sorted in place 
 */
void sortNums(float* arr, int length){
  sort(arr, arr+length);
}

/* Used for sorting by name
 * IN: Two Person objects
 * OUT: Boolean
 */
bool byname(Person p1, Person p2){
  return p1.getName() < p2.getName();
}

/* Sorting names of people  
 * IN: Person array, int number of people 
 * OUT: None, array is sorted in place 
 */
void sortNames(Person* ppl, int pplNum){
  sort(ppl, ppl+pplNum, byname);
}

/* Used for sort descending by age (where people with the same name are sorted alphabetically)
 * IN: Two Person objects
 * OUT: Boolean 
 */
bool byage(Person p1, Person p2){
  if(p1.getAge() == p2.getAge()){
    return p1.getName() < p2.getName();
  }
  return p1.getAge() > p2.getAge();
}

/* Sorting ages of people 
 * IN: Person array, int number of people 
 * OUT: None, array is sorted in place 
 */
void sortAges(Person* ppl, int pplNum){
  sort(ppl, ppl+pplNum, byage);
}

/* Print functions */

template <typename T>
void print(T arr[], int n){
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

void printppl(Person arr[], int n){
  for(int i = 0; i < n; i++)
    arr[i].display();
}

int main() {
  /* Variables numbers and people defined */
  float numbers[] = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
  Person people[] = {Person("Hal", 20), Person("Susann", 31), Person("Dwight", 19), Person("Kassandra", 21), Person("Lawrence", 25), Person("Cindy", 22), Person("Cory", 27), Person("Mac", 19), Person("Romana", 27), Person("Doretha", 32), Person("Danna", 20), Person("Zara", 23), Person("Rosalyn", 26), Person("Risa", 24), Person("Benny", 28), Person("Juan", 33), Person("Natalie", 25)};

  int numsLen = sizeof(numbers) / sizeof(float);
; 
  int population = sizeof(people) / sizeof(Person);
  
  // Sort numbers ascending by numerical value
  cout << "==== Sort numbers ascending ====" << endl;
  cout << "BEFORE: " << endl;
  print(numbers, numsLen);
  sortNums(numbers, numsLen);
  cout << endl << "AFTER: " << endl;
  print(numbers, numsLen);

  cout << endl;
  // Sort people alphabetically (lexicograhically) by name 
  cout << endl << "==== Sort people alphabetically ====" << endl; 
  cout << "BEFORE: " << endl; 
  printppl(people, population);
  sortNames(people, population);
  cout << endl << "AFTER: " << endl;
  printppl(people, population);
  
  // Sort people descending by age, where people of the same age should be sorted alphabetically 
  cout << endl << "==== Sort people descending by age ====" << endl; 
  cout << "BEFORE: " << endl; 
  printppl(people, population);
  sortAges(people, population);
  cout << endl << "AFTER: " << endl;
  printppl(people, population);
}