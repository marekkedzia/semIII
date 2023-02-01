trait BasicAccess
trait ExtendedAccess extends BasicAccess
trait SuperAccess extends ExtendedAccess

trait User[Read, Write]:
  def secret: String

  def secret (secret: String): Unit

class BasicUser extends User[BasicAccess, BasicAccess]:
  override def secret: String = "FBI lies (level: basic)"

  override def secret (secret: String): Unit = println("Saving basic access secret: " + secret)

class ExtendedAccessUser extends User[ExtendedAccess, ExtendedAccess]:
  override def secret: String = "Joe Biden is an alien (level: extended)"

  override def secret (secret: String): Unit = println("Saving extended access secret: " + secret)

class SuperUser extends User[SuperAccess, SuperAccess]:
  override def secret: String = "It was planned (level: 9.11)"

  override def secret (secret: String): Unit = println("Saving super access secret: " + secret)

class MixedUser extends User[SuperAccess, BasicAccess]:
  override def secret: String = "Who let the dogs out? (level: super)"

  override def secret (s: String): Unit = println("Saving basic access secret: " + secret)


class Terminal[Read, Write <: Read] (private var _secret: String):
  def read[A <: Read] (user: User[A, _]): Unit = user.secret(_secret)

  def write[B <: Write] (user: User[_, B]): Unit = _secret = user.secret

val lowAccess = new BasicUser
val extendedAccess = new ExtendedAccessUser
val superAccess = new SuperUser
val mixedAccess = new MixedUser

val t1 = new Terminal[BasicAccess, BasicAccess]("1")
val t2 = new Terminal[ExtendedAccess, ExtendedAccess]("2")
val t3 = new Terminal[SuperAccess, SuperAccess]("3")

t1.read(lowAccess)
t1.write(superAccess)
t1.read(lowAccess)
t1.read(mixedAccess)
t2.read(extendedAccess)
t2.write(extendedAccess)
t2.read(extendedAccess)
t2.read(mixedAccess)
t3.write(superAccess)
t3.read(superAccess)
t3.read(mixedAccess)

