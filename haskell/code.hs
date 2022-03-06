:- import Data.Char 
             main=do
             putStrLn"Enter Marks in I Subject "
             a <- readLn
             putStrLn "Enter Marks in II Subject "
             b <- readLn
             putStrLn "Enter Marks in III subject " 
              c <- readLn 
             print(a+b+c)