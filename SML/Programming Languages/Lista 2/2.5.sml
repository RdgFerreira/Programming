fun count_main( x : int ) =
    let fun count( a : int ) = if a = x then x::[] else a::count(a + 1) 
    in count(1)
    end;