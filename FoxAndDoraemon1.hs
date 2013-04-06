import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line <- getLine
	sC <- getLine
	let
		workCost = reverse. sort. map(\x -> read x :: Int). words $ line
		len = length workCost
		splitCost = read sC::Int
		solve curFox idx
		 | idx == len = 0
		 | curFox == 0 = 100000000
		 | curFox >= len - idx = workCost !! idx
		 | otherwise =
		 	let 
				t1 = max (workCost!!idx) (solve (curFox-1) (idx+1))
				ret = min (t1) (splitCost + solve (2*curFox) idx)
			in 
				ret
	print workCost
	print len
	print splitCost
	print $ solve 1 0
