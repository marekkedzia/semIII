def flatten[A](list: List[List[A]]): List[A] = {
  list match {
    case Nil => Nil
    case h::t => h ::: flatten(t)
  }
}
