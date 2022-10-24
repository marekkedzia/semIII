//zad1
def find[T](list: List[T], toFind: T, index: Int): List[Int] =
  list match {
    case head :: tail if head == toFind => index :: find(tail, toFind, index + 1)
    case head :: tail => find(tail, toFind, index + 1)
    case _ => Nil
  }

find(List(1, 2, 3, 4, 5), 3, 0)
find(List(1, 2, 3, 4, 5), 5, 0)
find(List(1, 2, 3, 4, 5), 6, 0)
find(List(1, 2, 3, 4, 5), 1, 0)
find(List(), 5, 0)
find(List(0, 0, 0, 0, 0), 0, 0)

//zad2 rec
def isSquare(number: Int) = {
  number % 2 == 0
}
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

//def addToFirst[T](head: T, tail: List[T], index: Int) = {
//  val (pre, post) = split(tail, index + 1)
//  (head :: pre, post)
//}
//
//def addToSecond[T](head: T, tail: List[T], index: Int) = {
//  val (pre, post) = split(tail, index + 1)
//  (pre, head :: post)
//}

def split2Rec[T](list: List[T]) = {
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