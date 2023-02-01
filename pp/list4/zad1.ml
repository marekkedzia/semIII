type commit = ChangeCommit of int * string | DeleteCommit of int | MoveCommit of int*int*string;;

type branch = Empty | Root of string list * branch | Node of commit * branch;;

let initRoot = fun (code, nextNode) -> Root(String.split_on_char ' ' code, nextNode);;

initRoot("Ala ma kota", Empty);;
initRoot("", Empty);;
initRoot("Ala", Empty);;

let delete = fun(list, index) ->
  let rec deleteRec = fun (list, current) ->
    match list with
    | h :: t when current = index -> t
    | h :: t -> h :: deleteRec(t, current + 1)
    | _ -> []
in deleteRec(list, 0);;

delete(["let"; "x"; "="; "$"; "5"], 3);;
delete([], 3);;

let replace = fun(list, index, value) -> 
  let rec replaceRec = fun (list, current) ->
    match list with
    | h :: t when current = index -> value :: t
    | h :: t -> h :: replaceRec(t, current+1)
    | _ -> []
  in replaceRec(list, 0);;

replace(["1";"21";"3"], 1 , "2");;
replace([], 1 , "2");;

let split = fun (list, indexFrom, indexTo) ->
  let rec splitRec = fun(list, current)->
    match list with
    | h::t when current >= indexFrom && current < indexTo -> h :: splitRec(t, current+1)
    | h ::t when current = indexTo -> h :: []
    | _ :: t -> splitRec(t, current+1)
    | _ -> []
  in splitRec(list, 0);;

  split(["1";"2";"3";"4"], 0, 2);;
  split(["1";"2";"3";"4"], 1, 2);;

  let move = fun (list, indexFrom, indexTo, element) ->
    if(indexFrom=indexTo || indexFrom>indexTo)
     then list
  else if(indexTo<0 || indexFrom > List.length(list))
    then list
else 
   split(list, 0, indexFrom-1) @ split(list, indexFrom+1, indexTo-1) @ element :: split(list, indexTo, List.length list);;

  move(["1"; "2"; "3"; "4"; "5"], 1, 3, "2");;

  let applyChanges = fun (commit, code) ->
    match commit with 
    | DeleteCommit(index) -> delete(code, index)
    | ChangeCommit(position, value) -> replace(code, position, value)
    | MoveCommit(indexFrom, indexTo, value) -> move(code, indexFrom, indexTo, value);;

    applyChanges(DeleteCommit(1), ["1";"2";"3"]);;

  let review = fun(commit, root) ->
    let rec reviewRec = fun(node, code) ->
      match node with 
      | Empty -> code
      | Node(commit, branch) -> reviewRec(branch, applyChanges(commit, code))
      | Root(source, branch) -> reviewRec(branch, source)
    in applyChanges(commit, reviewRec(root, []));;

    let branch = initRoot("let x = 21 + ; 37 ", Node(DeleteCommit(4), Node(ChangeCommit(0, "const"), Empty)));;
    review(MoveCommit(4, 5,";"),branch)
