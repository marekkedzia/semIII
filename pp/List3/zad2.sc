def area(a: Double, b: Double)(func: Double => Double)(n: Int): Double = {
  val dx = (b - a) / n
  val pointsTable1 = for (x <- List.range(1, n + 1)) yield func((a + x * dx) - dx / 2)
  val pointsTable2 = for (x <- List.range(1, n)) yield func(a + x * dx)

  val sumMiddles = (pointsTable1 foldLeft 0.0) ((sum, x) => sum + x)
  val sumPoints = (pointsTable2 foldLeft 0.0) ((sum, x) => sum + x)
  (dx / 6) * (func(a) + func(b) + 2 * sumPoints + 4 * sumMiddles)
}

area(0, 10)(x => x * x * x)(1000000)
area(0, 10)(x => x * x)(1000000)
area(0, 10)(x => x)(1000000)
area(0, 10)(_ => 1)(1000000)
area(-5, 5)(_ => 0)(1000000)
area(-10, -1)(_ => 0)(1000000)
area(-10, -1)(x => x * x * x)(1000000)
