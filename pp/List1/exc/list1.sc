//zad1
def flatten1[T](list: List[List[T]]): List[T] = {
  if (list == Nil)
    Nil
  else {
    def flattenList(listToFlatten: List[T]): List[T] = {
      if (listToFlatten == Nil)
        flatten1(list.tail)
      else
        listToFlatten.head :: flattenList(listToFlatten.tail)
    }

    flattenList(list.head)
  }
}

flatten1(List(List(1, 2, 3), List(4, 5, 6)))
flatten1(List(List(), List()))
flatten1(List(List(1), List(1, 2, 3, 4, 5)))
flatten1(List(List(), List(1, 2, 3, 4, 5)))
flatten1(List(List(1, 2, 3, 4, 5), List()))

//zad2
def countRec[T](toFind: T, list: List[T], counter: Int): Int = {
  if (list == Nil)
    counter
  else if (toFind == list.head)
    countRec(toFind, list.tail, counter + 1)
  else
    countRec(toFind, list.tail, counter)
}

def count[T](toFind: T, list: List[T]) = {
  countRec(toFind, list, 0)
}

count(2, List(1, 2, 3, 4))
count(1, List(1, 2, 1, 3))
count(3, List())

//zad3
def replicate[T](expression: T, times: Int): List[T] = {
  if (times == 0)
    Nil
  else
    expression :: replicate(expression, times - 1)
}

replicate("LA", 5)
replicate("LA", 0)

//zad4
def sqrtList(list: List[Int]): List[Int] = {
  if (list == Nil)
    Nil
  else
    list.head * list.head :: sqrtList(list.tail)
}

sqrtList(List(5, -3, 0))
sqrtList(List(5, 3, 4))
sqrtList(List())

//zad5
def stackElements[T](list: List[T]): List[T] = list match {
  case h :: tail => stackElements(tail) ::: List(h)
  case Nil => Nil
}

def palindrome[T](list: List[T]) = {
  def compareLists(list1: List[T], list2: List[T]): Boolean = {
    if (list1 == Nil)
      true
    else if (list1.head != list2.head)
      false
    else
      compareLists(list1.tail, list2.tail)
  }

  compareLists(list, stackElements(list))
}

palindrome(List(1, 2, 3, 4, 5))
palindrome(List("K", "A", "J", "A", "K"))
palindrome(List("K", "A", "j", "A", "K"))
palindrome(List("K", "A", "j", "a", "K"))

//zad6
def listLength[T](list: List[T]): Int = {
  def countLength(list: List[T], counter: Int): Int = {
    if (list == Nil)
      counter
    else
      countLength(list.tail, counter + 1)
  }

  countLength(list, 0)
}

listLength(List(1, 2, 3, 4, 5))
listLength(List())
