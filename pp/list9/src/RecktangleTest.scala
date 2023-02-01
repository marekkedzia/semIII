object RectangleTests extends App {
  val rectangle = new Rectangle(3, 4)
  println(rectangle.area)
  rectangle.widthInMilimeter = 5
  println(rectangle.widthInMilimeter)
  rectangle.heightInMilimeter =   6
  println(rectangle.heightInMilimeter)
  println(rectangle.area)

  val square = new Rectangle(5)
  println(square.area)
}