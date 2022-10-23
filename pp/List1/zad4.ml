let rec swap2 = fun(list) ->
  if list=[]
    then []
else if List.tl list = []
  then List.hd list :: []
else 
  List.hd (List.tl list) :: List.hd list :: swap2 (List.tl(List.tl list));;

swap2([]);;                                         
swap2([1; 1; 1; 1; 1]);;    
swap2(["A"; "B"; "A"; "B"; "A"]);;                       

