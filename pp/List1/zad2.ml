let roots = fun (a, b, c) ->
  let delta = (b *. b) -. 4. *. (a *. c)
in
if delta > 0. 
  then 2 
else if delta = 0. 
  then 1
 else 
  0;;

  roots(0.0,0.0,0.0);;
  roots(0.0, 1.0 ,1.0);;
  roots(1.0, 0.0 ,1.0);;