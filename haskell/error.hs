import Data.Char 
main=do
putStrLn"Enter your Percentage"
a <- readLn 
if a > 40
then putStrLn "You are Pass " 
else putStrLn "You are Fail"