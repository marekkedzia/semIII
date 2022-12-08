def modify(rowIndex: Int): List[Int] = {
  def isEven(n: Int): Boolean = n % 2 == 0

  def add(x: Int, y: Int) = x + y

  def sub(x: Int, y: Int) = x - y

  def provideOperation(rowIndex: Int):(Int, Int)=>Int = if (isEven(rowIndex)) add else sub

  def modifyRec(currentRow: Int, list: List[Int]): List[Int] = {
    if (currentRow == rowIndex)
      list
    else
      def modifyRow(row: List[Int],  operation: (Int, Int)=>Int): List[Int] = {
        row match {
          case h1 :: (t1@h2 :: _) => operation(h1, h2) :: modifyRow(t1, operation)
          case h :: _ => h :: Nil
          case _ => Nil
        }
      }

      modifyRec(currentRow + 1, 1 :: modifyRow(list, provideOperation(currentRow + 1)))
  }

  modifyRec(-1, List())
}

modify(3)
modify(5)
modify(6)