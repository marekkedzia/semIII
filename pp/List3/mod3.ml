let reverse list = 
  List.fold_left (fun listReversed element -> element::listReversed) [] list;;

(*
  (1+(2+(3+0)))
  (1::(2::(3::[])))
*)

reverse([1;2;3]);;
reverse([]);;
reverse([1;2;3;4;4;5]);;