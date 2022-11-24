let appSecretKey = 2137;;

type reward = BoolOfTruth of bool * string | Money of int * string | Item of string | NotProvidedYet of (unit->reward)  | Nothing;;
type table = Table of  reward list;;

let provideReward = function 1 -> BoolOfTruth(true, "Is winter coming?") | 2 -> Money(1500, "$") | 3 -> Item("Watch") | _ -> Nothing;;

let calculateTicketToken = function() -> (appSecretKey + Random.int 100)  mod 4;;

(*calc test*)
calculateTicketToken();;
calculateTicketToken();;
calculateTicketToken();;
calculateTicketToken();;

let findReward = function () -> provideReward (calculateTicketToken());;

let provide = function ()  -> findReward();;

  let buyTicket = function (index, table) ->  
    let rec buyTicketRec = function (current, table) -> match (current, List.hd table) with 
      | (int, NotProvidedYet(f)) when current = index -> f() :: table
      | (_, r) -> r :: buyTicketRec (current+1, List.tl table)
  in buyTicketRec(0, table);;

  let list = [NotProvidedYet(provide);NotProvidedYet(provide);NotProvidedYet(provide);NotProvidedYet(provide)];;
  let list1 = buyTicket(3,  list);;
  buyTicket(2,  list1);;
 


