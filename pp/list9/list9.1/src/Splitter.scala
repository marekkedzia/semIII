class Splitter (private val range:Int) {
private var smallFigures: List[Figure] = List[Figure]()
  private var bigFigures: List[Figure] = List[Figure]()
  require(range > 0, throw new InvalidInput("Range must be positive Integer. Found: " + range + " instead."))

    def apply (figure: Figure): Unit = {
      if (figure.area >= range)
        bigFigures :+= figure
      else
        smallFigures :+= figure
    }

    def printSmallFigures (): Unit =
      smallFigures.foreach(f => println(f.area))

    def printBigFigures (): Unit =
      bigFigures.foreach(f => println(f.area))
}