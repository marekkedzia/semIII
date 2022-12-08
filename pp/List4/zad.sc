sealed trait Commit[+A]
case class ChangeCommit[+A](position: Int, value: String) extends Commit[A]
case class DeleteCommit[+A](index: Int) extends Commit[A]
case class MoveCommit[+A](indexStart: Int, indexEnd: Int) extends Commit[A]


sealed trait Branch[+A]
case object Empty extends Branch[Nothing]
case class Root[+A](source: List[String], nextNode: Branch[A]) extends Branch[A]
case class Node[+A](commit: Commit[A], nextNode: Branch[A]) extends Branch[A]

def initRoot[A](code: String, nextNode: Node[A]): Root[A] =
  Root(code.split(" ").toList, nextNode)

def delete(list: List[String], index: Int): List[String] = {
  def deleteRec(list: List[String], current: Int): List[String] = list match {
    case h :: t if current == index => t
    case h :: t => h :: deleteRec(t, current + 1)
    case _ => Nil
  }

  deleteRec(list, 0)
}

def replace(list: List[String], index: Int, value: String): List[String] = {
  def replaceRec(list: List[String], current: Int): List[String] = list match {
    case h :: t if current == index => value :: t
    case h :: t => h :: replaceRec(t, current + 1)
    case _ => Nil
  }

  replaceRec(list, 0)
}

def move(list: List[String], indexFrom: Int, indexTo: Int): List[String] = {
  if (indexTo == indexFrom || indexFrom > indexTo)
    list
  else if (indexTo < 0 || indexTo > list.size)
    list
  else {
    val (leftFrom, rightFrom) = list.splitAt(indexFrom)
    val (middle, end) = rightFrom.tail.splitAt(indexTo - 1)
    leftFrom ::: middle ::: rightFrom.head :: end
  }
}

def applyChanges[A](commit: Commit[A], code: List[String]): List[String] = commit match {
  case cm: DeleteCommit[A] => delete(code, cm.index)
  case cm: ChangeCommit[A] => replace(code, cm.position, cm.value)
  case cm: MoveCommit[A] => move(code, cm.indexStart, cm.indexEnd)
}

//delete
applyChanges(DeleteCommit(1), List("0", "1", "2", "3"))
applyChanges(DeleteCommit(1), List("0"))
applyChanges(DeleteCommit(1), List())
//replace
applyChanges(ChangeCommit(1, "1"), List("0", "5", "2", "3"))
applyChanges(ChangeCommit(8, "1"), List("0", "1", "2", "3"))
applyChanges(ChangeCommit(8, "1"), List())
//move
applyChanges(MoveCommit(0, 1), List("2", "1"))
applyChanges(MoveCommit(2, 4), List("0", "1", "4", "2", "3"))
applyChanges(MoveCommit(2, 4), List("0", "1", "5", "2", "3", "4"))
applyChanges(MoveCommit(2, 4), List("0", "1", "5", "2", "3", "4", "6", "7"))


def review[A](commit: Commit[A], root: Root[A]): List[String] = {
  def reviewRec(node: Branch[A], code: List[String]): List[String] = node match {
    case Empty => code
    case nd: Node[A] => reviewRec(nd.nextNode, applyChanges(nd.commit, code))
  }

  applyChanges(commit, reviewRec(root.nextNode, root.source))
}

//review
review(ChangeCommit(1, "y"),
  initRoot("let x : number = 37 21 +",
    Node(MoveCommit(5, 7),
      Node(ChangeCommit(0, "const"),
        Node(DeleteCommit(2),
          Node(DeleteCommit(2), Empty
          ))))))