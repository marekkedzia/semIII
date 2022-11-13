//zad1
def find[T](list: List[T])(toFind: T): List[Int] = {
  def find(list: List[T])(toFind: T)(index: Int): List[Int] = {
    list match {
      case head :: tail if head == toFind => index :: find(tail)(toFind)(index + 1)
      case head :: tail => find(tail)(toFind)(index + 1)
      case _ => Nil
    }
  }

  find(list)(toFind)
}

val find123 = find(List(1, 2, 3)) _

find(List(1, 2, 3, 4, 5))(3)
find(List(1, 2, 3, 4, 5))(5)
find(List(1, 2, 3, 4, 5))(6)
find(List(1, 2, 3, 4, 5))(1)
find(List())(5)
find(List(0, 0, 0, 0, 0))(0)

//zad2 rec
def isSquare(number: Int) = {
  number % 2 == 0
}
def split2Rec[T](list: List[T]) = {
  def split[T](list: List[T], index: Int): (List[T], List[T]) = list match {
    case head :: tail if isSquare(index) => {
      val (pre, post) = split(tail, index + 1)
      (head :: pre, post)
    }
    case head :: tail if !isSquare(index) => {
      val (pre, post) = split(tail, index + 1)
      (pre, head :: post)
    }
    case _ => (Nil, list)
  }

  split(list, 0)
}

split2Rec(List(1, 2, 3, 4))
split2Rec(List(1, 2, 3, 4, 5))
split2Rec(List(1))
split2Rec(List())

//zad2 Tail
def splitTailRecursive[T](index: Int, list: List[T]): (List[T], List[T]) = {
  def splitR(index: Int, list: List[T], pair: (List[T], List[T])): (List[T], List[T]) = (index, list) match {
    case (index, h :: tail) if isSquare(index) => splitR(index + 1, tail, (h :: pair._1, pair._2))
    case (index, h :: tail) => splitR(index + 1, tail, (pair._1, h :: pair._2))
    case (_, list) => (pair._1, pair._2)
  }

  splitR(index, list, (List(), List()))
}
def split2Tail[T](list: List[T]) = {
  splitTailRecursive(0, list)
}

split2Tail(List(1, 2, 3, 4))
split2Tail(List(1, 2, 3, 4, 5))
split2Tail(List(1))
split2Tail(List())