//zad1
class Time(private var _hour: Int) {
  _hour = if _hour >= 0 && _hour < 24 then _hour else 0

  def hour_=(newHour: Int): Unit =
    if newHour < 0 || newHour > 24
    then _hour = 0
    else
      _hour = newHour
}


//zad3
