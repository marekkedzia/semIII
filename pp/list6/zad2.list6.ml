let isEven n = n mod 2 == 0;;

let add x y = x+y;;
let sub x y = x-y;;

let provideOperation rowIndex = if isEven rowIndex then add else sub;;

let modify rowIndex = 
  let array = ref (Array.make (rowIndex+1) 1) in
  let i = ref 2 in
  while !i<= rowIndex do
  let temp = Array.copy !array in
  let j = ref 1 in
    while !j<= !i-1 do
    !array.(!j) <- provideOperation !i temp.(!j-1) temp.(!j);
    j:=!j+1;
    done;
  i:=!i+1; 

  done;
!array;;

modify 4;;modify 5;;modify 6;;modify 7;;