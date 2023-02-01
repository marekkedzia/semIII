let flip5 = fun (a, b, c, d, e) ->
    (d, e, c, b, a);;

flip5("A", 13, 54.54, true, "c");;
flip5("A", "A", "A", "A", "A");;
flip5(1, 0, 5, 3, 4);;