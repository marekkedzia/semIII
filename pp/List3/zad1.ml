let rec ( >=< ) list func = 
  match list with
  | h :: [] -> []
  | h :: t -> func(h, List.hd t) :: ((List.tl t)>=<func)
  | _ -> [];; 

let fun1(x, y) = x;;
let list = [1;2;3;4;5;6];;
list >=< fun1;;
let list2 = [1;2;3];;
list2 >=< fun1;;

let rec collapse = fun(list, func) ->
  match list with
  | h :: [] -> list
  | h :: t -> collapse(list >=< func, func)
  | _ -> [];;


collapse([1;2;3;4], fun1);;
collapse([53], fun1);;
collapse([], fun1);;