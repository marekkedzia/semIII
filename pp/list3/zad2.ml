let area (xp, xk) func n =
  let dx = (xk -. xp) /. n
  in
  let rec createTable = fun (i, func, range) -> match i with 
    | x when x = range -> []
    | x -> func i :: createTable(i +. 1., func, range)
    in
  let table1 = createTable (1., (fun (x) -> func((xp +. x *. dx) -. dx /. 2.)), n-.1. )
  in
  let table2 = createTable (1., (fun (x) -> func(xp +. x *. dx)), n )
  in
(dx /. 6.) *. (func xp +. func xk +. 2. *.(List.fold_left(+.) 0.  table1) +. 4. *. (List.fold_left(+.) 0.  table2));;

area(2., 12.)(fun x -> x*.x+.2.*.x) (1000.);;
area(0., 10.)(fun x -> x *. x *. x)(1000.);;
area(0., 10.)(fun x -> x *. x)(1000.);;
area(0., 10.)(fun x -> x)(1000.);;
area(0., 10.)(fun x -> 1.)(1000.);;
area(-5., 5.)(fun x -> 0.)(1000.);;
area(-10., -1.)(fun _ -> 0.)(1000.);;