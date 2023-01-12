type compareResult = Less | Equal | Greater;;

module type COMPARATOR =
  sig
    type comparingType
    type result = compareResult
    val compare: comparingType -> comparingType -> result
  end;;

  module IntComparator : COMPARATOR with type comparingType = int =
  struct
    type comparingType = int
    type result = compareResult
    let compare x y =
      if x < y then Less
      else if x > y then Greater
      else Equal
  end;;

  module PriorityQueueImpl (Comperator : COMPARATOR) with type t = Comperator.t =
  struct
  type 'a heap = {mutable nodes: 'a array; compereFunc: 'a -> 'a -> compareResult}
  exception EmptyQueue of string

  let create () = ref {nodes = [||]; compereFunc = c}

  let insert element heap = 
    let rec fixHeap  current =
      let parentIndex = (current + 1) / 2 - 1 in
      if ( (!heap.compereFunc !heap.nodes.(1) !heap.nodes.(0) = Greater)) then begin
        let tmp = !heap.nodes.(1) in
        !heap.nodes.(1) <- !heap.nodes.(0);
        !heap.nodes.(0) <- tmp;
        fixHeap parentIndex
      end
    in
    !heap.nodes <- Array.append !heap.nodes [|element|];
    fixHeap (Array.length !heap.nodes)

  let retrieve heap = !heap.nodes.(0)
end;;

let q = PriorityQueueImpl(IntComparator).create;;

 PriorityQueueImpl(IntComparator).insert 3 q;;
 PriorityQueueImpl(IntComparator).insert 10 q;;

 PriorityQueueImpl(IntComparator).retrieve q;;
 

  