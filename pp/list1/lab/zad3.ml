let rec substitute = fun(list, toSwap, swapper) ->
  if list = [] 
    then [] 
  else if List.hd list = toSwap
    then swapper :: substitute(List.tl list, toSwap, swapper)
  else 
    List.hd list :: substitute(List.tl list, toSwap, swapper);;

  substitute([1;2;3;4;5], 4, 5);;
  substitute(["1";"2";"3";"4";"5"], "4", "5");;