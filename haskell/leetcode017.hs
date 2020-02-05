import Control.Monad (liftM2)
-- liftM2 :: Monad m => (a1 -> a2 -> r) -> m a1 -> m a2 -> m r
cartProd :: [String] -> [String] -> [String]
cartProd = liftM2 (++)

-- cardProd' act the same way that cardProd do
cartProd' :: [String] -> [String] -> [String]
cartProd' xs ys = [x ++ y | x <- xs, y <- ys]

-- keyboard
mapping :: Char -> [String]
mapping '2' = ["a", "b", "c"]
mapping '3' = ["d", "e", "f"]
mapping '4' = ["g", "h", "i"]
mapping '5' = ["j", "k", "l"]
mapping '6' = ["m", "n", "o"]
mapping '7' = ["p", "q", "r", "s"]
mapping '8' = ["t", "u", "v"]
mapping '9' = ["w", "x", "y", "z"]

-- defination of solution
dfs :: String -> [String]
dfs (a:[]) = mapping a
dfs s = cartProd (mapping $ head s) (dfs $ tail s)

-- a concise way of solution
dfs' :: String -> [String]
dfs' [] = [""]
dfs' (a:b) = cartProd' (mapping a) (dfs' b)

-- input the testcase
main = putStrLn $ show $ dfs "23"
-- => ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
