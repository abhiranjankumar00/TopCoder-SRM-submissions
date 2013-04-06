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
		arr :: [[Int]]
		arr = [ [ solve curFox idx|curFox <- [0..(3*len)] ]| idx <- [0..len]]
		solve curFox idx
		 | idx == len = 0
		 | curFox == 0 = 100000000
		 | curFox >= len - idx = workCost !! idx
		 | otherwise =
		 	let 
--				t1 = max (workCost!!idx) (solve (curFox-1) (idx+1))
--				ret1 = min (t1) (splitCost + solve (2*curFox) idx)
				t2  = max (workCost!!idx) (arr !! (curFox-1) !! (idx+1))
				ret2 = min (t2) (splitCost + (arr!! (2*curFox) !!(idx)))
			in 
				ret2
	print workCost
	print len
	print splitCost
	print $ solve 1 0
	print arr
