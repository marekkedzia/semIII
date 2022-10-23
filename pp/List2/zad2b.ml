let isSquare = fun number -> number mod 2 == 0

let splitTailRecursive = fun(index, list) ->
  let rec splitR(index, list, pair) = match (index, list) with
  | (index, h :: tail) when isSquare index -> splitR(index+1, tail, (h::fst pair, snd pair))
  | (index, h :: tail) -> splitR(index + 1, tail, (fst pair, h :: snd pair))
  | (_, list) -> (fst pair, snd pair)
in splitR(index, list, ([], []))


let split2Rec = fun(list) ->
  splitTailRecursive(0, list);;

split2Rec [1;2;3;4];;
split2Rec([1; 2; 3; 4; 5]);;
split2Rec([1]);;
split2Rec([]);;

(* def splitTailRecursive[T](index: Int, list: List[T]): (List[T], List[T]) = {
  def splitR(index: Int, list: List[T], pair: (List[T], List[T])): (List[T], List[T]) = (index, list) match {
    case (index, h :: tail) if isSquare(index) => splitR(index + 1, tail, (h :: pair._1, pair._2))
    case (index, h :: tail) => splitR(index + 1, tail, (pair._1, h :: pair._2))
    case (_, list) => (pair._1, pair._2)
  }

  splitR(index, list, (List(), List()))
}
def split2Tail[T](list: List[T]) = {
  splitTailRecursive(0, list)
} *)