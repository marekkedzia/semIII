let separate = fun list->
  if list = []
    then ([], [])
  else
    let rec separateRec = fun (startList, pair, last) ->
      if startList = []
        then pair
    else if List.hd startList >= last
      then separateRec(List.tl startList, (List.hd startList :: fst pair, snd pair), List.hd startList)
    else
      separateRec(List.tl startList, (fst pair, List.hd startList :: snd pair), last) 
    in separateRec(List.tl list, ([List.hd list], []), List.hd list);;
  
  separate([1;7;3]);;
  separate([1;3;7;5;6;9]);;
  separate([1]);;
  separate([1,1,1,1,1,1,5]);;
  separate([]);;