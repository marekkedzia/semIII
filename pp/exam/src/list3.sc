//zad2
def curry3[A, B, C, D](func: (A, B, C) => D) =
  (x: A) => (y: B) => (z: C) => func(x, y, z)

def uncurry3[A, B, C, D](func: A => B => C => D) =
  (x: A, y: B, z: C) => func(x)(y)(z)

//zad3

def sumProd(xs: List[Int]): (Int, Int) =
  xs match
    case h :: t => {
      val (s, p) = sumProd(t)
      (h + s, h * p)
    }
    case Nil => (0, 1)

def sumProdFold(list: List[Int]): (Int, Int) =
  list.foldLeft(0, 1)((acc, x) => (acc._1 + x, acc._2 * x))

sumProd(List(1, 2, 3, 4, 5))
sumProdFold(List(1, 2, 3, 4, 5))

//zad5
def insertionSort(list: List[Int]) = {
  def insertRec(list: List[Int], element: Int): List[Int] = {
    list match {
      case h :: t if h <= element => h :: insertRec(t, element)
      case h :: t if h > element => element :: h :: t
      case _ => element :: Nil
    }
  }

  def insertionSortRec(list: List[Int], sortedList: List[Int]): List[Int] = {
    list match {
      case h :: t => insertionSortRec(t, insertRec(sortedList, h))
      case _ => sortedList
    }
  }

  insertionSortRec(list.tail, List(list.head))
}

insertionSort(List(5, 4, 3, 6, 7, 2, 1))