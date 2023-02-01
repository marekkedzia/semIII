def substitute[T](list: List[T])(toSwap: T)(swapper: T): List[T] = list match {
  case head :: tail if (head == toSwap) => swapper :: substitute(tail)(toSwap)(swapper)
  case head :: tail => head :: substitute(tail)(toSwap)(swapper)
  case _ => Nil
}

substitute(List(1, 2, 3, 4, 5))(4)(5)
substitute(List())(4)(5)
substitute(List(1, 2, 3, 4))(5)(1)