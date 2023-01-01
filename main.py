"""
Using python sort() from https://docs.python.org/3/howto/sorting.html
"""

import functools
import locale

'''
Person class
Records name and age 
'''
class Person:
  name = ""
  age = 0

  def __init__(self, n, a):
    self.name = n
    self.age = a

  def getName(self):
    return self.name

  def getAge(self):
    return self.age
    
  def display(self):
    print(self.name, self.age)

'''Comparisons ==================='''
# Sorting by name: 
def byname(p1, p2):
  return locale.strcoll(p1.getName(), p2.getName())

# Modifies list in place with sort() using byname as the key parameter
def sortNames(list):
  list.sort(key=functools.cmp_to_key(byname))

# Sorting by age descending: 
def byage(p1, p2):
  if(p1.getAge() == p2.getAge()):
    return locale.strcoll(p1.getName(), p2.getName())
  return p2.getAge() - p1.getAge()

# Modifies list in place with sort() using byage as the key parameter
def sortAges(list):
  list.sort(key=functools.cmp_to_key(byage))

# Sorting numbers ascending
def sortNums(list):
  list.sort()
  
'''Printing ======================'''
def printThese(list):
  for i in range(len(list)):
    print(list[i], end=" ")

def printppl(list):
  for i in range(len(list)):
    list[i].display()

if __name__ == "__main__":

  numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
  people = [Person("Hal", 20), Person("Susann", 31), Person("Dwight", 19), Person("Kassandra", 21), Person("Lawrence", 25), Person("Cindy", 22), Person("Cory", 27), Person("Mac", 19), Person("Romana", 27), Person("Doretha", 32), Person("Danna", 20), Person("Zara", 23), Person("Rosalyn", 26), Person("Risa", 24), Person("Benny", 28), Person("Juan", 33), Person("Natalie", 25)]

  # Sort numbers ascending by numerical value
  print("==== Sort numbers ascending ====")
  print("BEFORE: ")
  printThese(numbers)
  sortNums(numbers)
  print("")
  print("AFTER: ")
  printThese(numbers)
  print("")
  
  # Sort people alphabetically (lexicographically) by name
  print("==== Sort people alphabetically ====")
  print("BEFORE: ")
  printppl(people)
  sortNames(people)
  print("")
  print("AFTER: ")
  printppl(people)
  print("")
  
  # Sort people descending by age, where people of the same age should be sorted alphabetically 
  print("==== Sort people descending by age ====")
  print("BEFORE: ")
  printppl(people)
  sortAges(people)
  print("")
  print("AFTER: ")
  printppl(people)
  
  