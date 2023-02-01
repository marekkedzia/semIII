
class Rectangle(private var _widthInMilimeter: Int, private var _heightInMilimeter: Int) extends Figure {
  validateWidth(_widthInMilimeter)
  validateHeight(_heightInMilimeter)

  private def validateHeight(height: Int): Unit = {
    require(height > 0, throw new InvalidInput("Height must be positive Integer. Found: " + height + " instead."))
  }

  private def validateWidth(width: Int): Unit = {
    require(width > 0, throw new InvalidInput("Width must be positive Integer. Found: " + width + " instead."))
  }

  def this(_widthInMilimeter: Int) = this(_widthInMilimeter, _widthInMilimeter)

  override def area: Int = _widthInMilimeter * _heightInMilimeter

  def widthInMilimeter: Int = _widthInMilimeter

  def heightInMilimeter: Int = _heightInMilimeter

  def widthInMilimeter_=(widthInMilimeter: Int): Unit = {
    validateWidth(widthInMilimeter)
    _widthInMilimeter = widthInMilimeter
  }

  def heightInMilimeter_=(heightInMilimeter: Int): Unit = {
    validateHeight(heightInMilimeter)
    _heightInMilimeter = heightInMilimeter
  }
}
