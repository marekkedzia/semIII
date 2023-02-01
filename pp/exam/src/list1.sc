import scala.annotation.tailrec

//zad1
def flatten[A](list: List[List[A]]): List[A] = {
  list match {
    case Nil => Nil
    case h :: t => h ::: flatten(t)
  }
}

flatten(List(List(1, 2), List(3, 4, 5), List(7, 8, 9)))

//zad2

def count[A](element: A, list: List[A]): Int = {
  @tailrec
  def countRec(occurrences: Int, list1: List[A]): Int = {
    list1 match {
      case Nil => occurrences
      case h :: t if h == element => countRec(occurrences + 1, t)
      case _ :: t => countRec(occurrences, t)
    }
  }

  countRec(0, list)
}

count("a", List("a", "l", "a", "m", "a", "k", "o", "t", "a"))

//zad3
def replicate[A](element: A, occurrences: Int): List[A] = {
  def replicateRec(currentIndex: Int): List[A] = {
    currentIndex match {
      case v if v == occurrences => element :: Nil
      case _ => element :: replicateRec(currentIndex + 1)
    }
  }

  if occurrences > 0
  then replicateRec(0)
  else Nil
}

replicate("Hello there", 4)

//zad4
def sqrtList(numbers: List[Int]): List[Int] = {
  def sqrtRec(list: List[Int]): List[Int] = {
    list match {
      case Nil => Nil
      case h :: t => h * h :: sqrtRec(t)
    }
  }

  sqrtRec(numbers)
}

sqrtList(List(-1, 9, 3))

//zad5
def isPalindrome[A](list: List[A]): Boolean = {
  @tailrec
  def isPalindromeRec(list: List[A], reversedList: List[A]): Boolean = {
    list match {
      case Nil => true
      case h :: t if h == reversedList.head => isPalindromeRec(t, reversedList.tail)
      case _ => false
    }
  }

  isPalindromeRec(list, list.reverse)
}

isPalindrome(List("k", "a", "j", "a", "k"))
isPalindrome(List("k", "a", "j", "k"))
isPalindrome(List())

//zad6

def length[A](list: List[A]): Int = {
  @tailrec
  def lengthRec(list: List[A], currentIndex: Int): Int = {
    list match {
      case _ :: t => lengthRec(t, currentIndex + 1)
      case Nil => currentIndex
    }
  }
  lengthRec(list, 0)
}

length(List(1,2,3,4,5))
length(List())