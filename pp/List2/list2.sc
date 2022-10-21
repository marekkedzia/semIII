//zad1
def findX[T](list: List[T], toFind: T, index: Int): List[Int] = {
  if (list == Nil)
    Nil
  else if (list.head == toFind)
    index :: findX(list.tail, toFind, index + 1)
  else
    findX(list.tail, toFind, index + 1)
}

def find[T](list: List[T], toFind: T) = list match {
  case List() => List()
  case List(1) => List(99)
  case List(1, 2, 3) => findX(list, toFind, 0)
  case _ => findX(list, toFind, 0)
}

find(List(), 5)
find(List(1, 2, 3, 4), 5)
find(List(1), 99)
find(List(1, 2, 3), 1)
find(List(true, false, true, false), true)