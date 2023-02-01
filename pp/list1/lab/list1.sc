
//zad1
def flip5[A, B, C, D, E](crotch: (A, B, C, D, E)): (D, E, C, B, A) = {
  (crotch._4, crotch._5, crotch._3, crotch._2, crotch._1)
}

flip5(("3", "a", 4, 5, 5.4))
flip5("5", 1333333333, "im teapot", 0, -4)

//zad2
def calculateRoots(a: Double, b: Double, c: Double) = {
  val delta = b * b - 4 * (a * c)
  if (delta > 0)
    2
  else if (delta == 0)
    1
  else
    0
}

calculateRoots(1, 10, 2)
calculateRoots(0, 0, 0)
calculateRoots(-15.34, 0, -3)
calculateRoots(-3.15, -15.3, -14)

//zad3
def substitute[T](list: List[T], toSwap: T, swapper: T): List[T] = {
  if (list.equals(Nil))
    Nil
  else if (list.head == toSwap)
    swapper :: substitute(list.tail, toSwap, swapper)
  else
    list.head :: substitute(list.tail, toSwap, swapper)
}


substitute(List(1, 2, 3, 4, 5), 4, 15)
substitute(List("A", "5", "true"), "im teapot", "false")
substitute(List(true, false, true), true, false)
substitute(List(1.1, 3.1415, 5.5), 3.1415, 3.0)

//zad4
def swap2[T](list: List[T]): List[T] = {
  if (list.equals(Nil))
    Nil
  else if (list.tail.equals(Nil))
    list.head :: Nil
  else
    list.tail.head :: list.head :: swap2(list.tail.tail)
}

swap2(List(1, 2, 3, 4, 5, 6))
swap2(List("im teapot", "true", "3.14"))
swap2(List(1, 1, 1, 1, 1))