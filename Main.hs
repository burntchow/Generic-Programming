-- Using Haskell's sorts:
-- https://hackage.haskell.org/package/base-4.17.0.0/docs/Data-List.html#v:sort
-- https://hackage.haskell.org/package/base-4.17.0.0/docs/Data-List.html#v:sortOn
-- https://hackage.haskell.org/package/base-4.17.0.0/docs/Data-List.html#v:sortBy 

import Data.Function
import Data.List 
import Data.Ord

-- Person Product with name and age 
data Person = Person String Int deriving (Show, Eq)
name :: Person -> String
name   (Person n a) = n

age :: Person -> Int 
age   (Person n a) = a
-- Need an instance Ord 
instance Ord Person where 
  p <= q = name p <= name q 

-- Variables numbers, people 
numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]

people = [Person "Hal" 20, Person "Susan" 31, Person "Dwight" 19, Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19, Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23, Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, Person "Juan" 33, Person "Natalie" 25]

-- Sorting 
sortNums :: Ord a => [a] -> [a]
sortNums nums = sort nums -- sorting numbers 

sortNames :: [Person] -> [Person]
sortNames people = sortOn name people  -- sort by names 

sortAges :: [Person] -> [Person]
sortAges people = reverse $ sortBy byAges people
  where byAges p1 p2 
         | age p1 == age p2 = (comparing name) p2 p1 -- compare by names if ages equal 
         | otherwise        = (comparing age) p1 p2

main = do
  
  -- Sort numbers ascending by numerical value
  putStrLn "==== Sort numbers ascending ===="
  putStrLn "BEFORE: "
  print numbers
  putStrLn "AFTER: "
  print $ sortNums numbers
  putStrLn " "

  -- Sort people alphabetically (lexicographically) by name
  putStrLn "==== Sort people alphabetically ===="
  putStrLn "BEFORE: "
  print people
  putStrLn "AFTER: "
  print $ sortNames people
  putStrLn " "

  -- Sort people descending by age, where people of the same age should be sorted alphabetically 
  putStrLn "==== Sort people descending by age ===="
  putStrLn "BEFORE: "
  print people
  putStrLn "AFTER: "
  print $ sortAges people

