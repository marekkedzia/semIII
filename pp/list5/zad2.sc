def skipTakeL[A](startList: LazyList[A]): LazyList[A] = {
  def skipTakeLRec(current: Int, target: Int, list: LazyList[A]): LazyList[A] = list match {
    case h #:: t if current == target => h #:: skipTakeLRec(1, target + 2, t)
    case _ #:: t => skipTakeLRec(current + 1, target, t)
    case LazyList() => LazyList()
  }

  skipTakeLRec(-1, 2, startList)
}

skipTakeL(LazyList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22)).force
skipTakeL(LazyList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)).toList
skipTakeL(LazyList(-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)).toList
skipTakeL(LazyList()).force
skipTakeL(LazyList("a", "b", "c", "d", "e")).force

def layZip[A](list: LazyList[A]): LazyList[(A, A)] = {
  list match {
    case (h1 #:: h2 #:: t) => (h1, h2) #:: layZip(h2 #:: t)
    case _ => LazyList()
  }
}
layZip(LazyList("a", "b", "c")).force
layZip(LazyList("a", "b")).force
layZip(LazyList.range(0, 99)).force