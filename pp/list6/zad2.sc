def isEven(n: Int): Boolean = n % 2 == 0

def add(x: Int, y: Int) = x + y

def sub(x: Int, y: Int) = x - y

def provideOperation(rowIndex: Int): (Int, Int) => Int = if (isEven(rowIndex)) add else sub

def modify(rowIndex: Int): Array[Int] = {
  var array = Array[Int](1,1);

  for (ri <- 2 to rowIndex) {
    array = array:+ 1
    val temp = array.clone()

    for (ci <- 1 to ri-1)
      array(ci) = provideOperation(ri)(temp(ci-1), temp(ci))
  }
  array
}

modify(3)
modify(4)
modify(5)
modify(6)