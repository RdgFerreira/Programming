fun isSep sep = if (sep = #",") 
                    orelse (sep = #".") 
                    orelse (sep = #"-") 
                    orelse (sep = #" ") then true else false;

fun split str = String.tokens isSep str;

split "a,b,c-d e";

