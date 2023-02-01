let isSquare = fun number -> number mod 2 == 0

let addToFirst = fun(head, tail, index, splitFunc) ->
   let (frst, scnd) = splitFunc(tail, index + 1)
  in (head :: frst, scnd);;

let addToScnd = fun(head, tail, index, splitFunc) ->
  let (frst, scnd) = splitFunc(tail, index + 1)
in(frst, head :: scnd);;

let rec split (list, index) =
  match list with
  | head :: tail when isSquare index -> addToFirst(head, tail, index, split)
  | head :: tail -> addToScnd(head, tail, index, split)
  | _ -> ([], []);;

  let split2Rec = fun(listToSplit) ->
    split(listToSplit, 0);;


split2Rec([1; 2; 3; 4]);;
split2Rec([1; 2; 3; 4; 5]);;
split2Rec([1]);;
split2Rec([]);;