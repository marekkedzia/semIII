def MAX_INT_FIB_ELEMENT = 81
//zad2a
def fibRec(range: Int) = {
  def fib(range: Int): Int = {
    if (range == 0)
      0
    else if (range == 1)
      1
    else
      fib(range - 1) + fib(range - 2)
  }

  if (range >= MAX_INT_FIB_ELEMENT)
    -1
  else
    fib(range)
}

fibRec(15)
fibRec(1333)
fibRec(0)
fibRec(42)

//zad2b
def fib(range: Int): Int = {
  def calculateFibElement(prev: Int, current: Int, currentIndex: Int): Int = {
    if (range == currentIndex)
      current
    else
      calculateFibElement(current, current + prev, currentIndex + 1)
  }

  if (range >= MAX_INT_FIB_ELEMENT)
    -1
  else if (range == 0)
    0
  else
    calculateFibElement(0, 1, 1)
}

fib(15)
fib(1333)
fib(0)
fib(42)

//zad3 method
val epsilon = 1.0e-15

def calculateRoot3(x: Double, y: Double): Double = {
  if (math.abs((math.pow(x, 3) - y)) <= epsilon * math.abs(y))
    x
  else
    calculateRoot3(x +((y / math.pow(x, 2)) - x) / 3, y)
}

def root3(x: Double): Double = calculateRoot3(
  if (x > 1) x / 3 else x, x)

root3(27)
//zad3func
val root3F = (x:Double)=>calculateRoot3(if (x > 1) x / 3 else x, x)

//zad4


//zad5
def initSegment[T](prefix: List[T], list: List[T]): Boolean = {
  if (prefix == list || prefix == List())
    true
  else {
    def compareLists(list1: List[T], list2: List[T]): Boolean = {
      if (list1 == Nil)
        true
      else if (list1.head != list2.head)
        false
      else
        compareLists(list1.tail, list2.tail)
    }

    compareLists(prefix, list)
  }
}

initSegment(List(1, 2, 3, 4), List(1, 2, 3, 4, 5, 6))
initSegment(List(1, 2, 3, 4), List(1, 2, 3, 4))
initSegment(List(), List(1, 2, 3, 4))
initSegment(List(1, 1), List(1, 2, 3, 4))

//zad6

def replace[T](list: List[T], index: Int, element: T): List[T] = {
  if (index == 0)
    element :: list.tail
  else if (list == Nil)
    list
   else {
    def replaceRec(list: List[T], current: Int): List[T] = {
      if (list == Nil)
        Nil
      else if (current == index)
        element :: list.tail
      else
        list.head :: replaceRec(list.tail, current + 1)
    }

    replaceRec(list, 0)
  }
}

replace(List(1,2,3),2,4)
replace(List(),2,4)
replace(List(1,2,3),12,4)


