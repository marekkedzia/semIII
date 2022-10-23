let rec find (list, toFind, index) =
  match list with
  | head::tail when head == toFind -> index :: find(tail, toFind, index + 1)
  | head :: tail -> find(tail, toFind, index + 1)
  | _ -> [];;

  find([1; 2; 3; 4; 5], 3, 0);;
  find([1; 2; 3; 4; 5], 5, 0);;
  find([1; 2; 3; 4; 5], 6, 0);;
  find([1; 2; 3; 4; 5], 1, 0);;
  find([], 5, 0);;
  find([0; 0; 0; 0; 0], 0, 0);;