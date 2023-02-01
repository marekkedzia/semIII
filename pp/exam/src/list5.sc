//zad1
def repeat[A](k: Int)(list: LazyList[A]) = {
  def repeatRec(c: Int, list: LazyList[A]): LazyList[A] = {
    (c, list) match {
      case (_, l) if l.isEmpty => LazyList.empty
      case (0, _ #:: l) => repeatRec(k, l)
      case (_, h #:: l) => h #:: repeatRec(c - 1, h #:: l)
    }
  }

  repeatRec(k, list)
}

repeat(2)(LazyList.from(0)).take(10).toList

//zad2

def generateFibonacci = {
  def generateFibonacciRec(a: Int)(b: Int): LazyList[Int] = a #:: generateFibonacciRec(b)(a + b)

  generateFibonacciRec(1)(1)
}

generateFibonacci.take(5).toList
generateFibonacci.take(45).toList
generateFibonacci.take(50).toList