type Change = (Int, String)
type Commit = List[Change]

sealed trait TreeElement[+A]

case object Empty extends TreeElement[Nothing]

case class Root[+A](source: List[Change], node: Node[A]) extends TreeElement[A]

case class Node[+A](commit: Commit, nextNode: TreeElement[A]) extends TreeElement[A]

def initSource(splitedCode: List[String], index: Int): Commit = splitedCode match {
  case Nil => Nil
  case _ => (index, splitedCode.head) :: initSource(splitedCode.tail, index + 1)
}

def init[A](code: String): Root[A] =
  Root(initSource(code.split(" ").toList, 0), Node(List((1, "y")), Node(List((3, "6")), Empty)))

def applyChanges(commit: Commit, source: List[Change]): Commit = (commit, source) match {
  case (_, Nil) => commit
  case (Nil, _) => source
  case (ch :: ct, sh :: st) if ch._1 > sh._1 => sh :: applyChanges(commit, st)
  case (ch :: ct, sh :: st) if ch._1 == sh._1 => ch :: applyChanges(ct, st)
  case (ch :: ct, source) => ch :: applyChanges(ct, source)
}

def review[A](lastCommit: Commit, root: Root[A]): List[String] = {
  def reviewRec(node: Node[A], acc: Commit): List[String] = node match {
    case Node(_, Empty) => applyChanges(lastCommit, acc).map(e=>e._2)
    case Node(commit: Commit, nextNode: Node[A]) => reviewRec(nextNode, applyChanges(commit, acc))
  }

  reviewRec(root.node: Node[A], root.source)
}

applyChanges(List((1, "1"), (2, "2"), (3, "3")), List((1, "C"), (2, "P"), (3, "W")))
applyChanges(List((1, "1"), (2, "2")), List((1, "C"), (2, "P"), (3, "3")))
applyChanges(List((1, "1"), (2, "2"), (3, "3")), List((1, "C"), (2, "P")))

review(List((0, "let")), init("const x = 1"))
