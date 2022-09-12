% Run in SWI-Prolog: 
    % working_directory(CWD, 'C:/Users/arauj/OneDrive/Documents/UFMG/2022-1/LP/Programs/Prolog').
    % [1] (Nome do programa)

% Run in wsl:
    % swipl -f program_name.pl


% Fatos:
    parent(kim, holly).
    parent(margaret, kim).
    parent(margaret, kent).
    parent(esther, margaret).
    parent(herbert, margaret).
    parent(herbert, jean).

% Consultas: (vírgula representa conjunção e ponto e vírgula representa disjunção)

    ?- parent(kim, holly). % (* Consulta direta: True *)
    ?- parent(kim, X).     % (* Procura quaisquer instanciações de X de modo que essa consulta seja True *)
        % |-> X = holly.
    
    ?- parent(X, Y).       % (* Gera todas as instanciações possíveis de parent *)
    ?- parent(Y, esther).  % (* False: não há instanciações possíveis para Y nos fatos acima *)

    ?- parent(margaret,X), parent(X, holly). % (* X = kim *)
    ?- parent(margaret,X); parent(X, holly). % (* X = kim, X = kent *)

    ?- parent(esther, C), parent(C, GC), parent(GC, GGC). % (* Checar se esther tem um neto *)

% Regras: Definem como novos fatos podem ser obtidos a partir de condições estabelecidas

    greatGrandparent(GGP, GGC) :- parent(GGP, GP), parent(GP, P), parent(P, GGC). 
    grandparent(GP, GC) :- parent(GP, P), parent(P, GC).
    greatGrandparent(GGP, GGC) :- grandparent(GGP, P), parent(P, GGC).
    
    % (* Definição recursiva e simultânea: dois casos são considerados *)
    ancestor(X, Y) :- parent(X, Y).
    ancestor(X, Y) :- parent(Z, Y), ancestor(X, Z).

    sibling(X,Y) :- parent(P,X), parent(P, Y).
    sibling(X,Y) :- parent(P,X), parent(P, Y), not(X=Y). % (* Garantindo que X seja diferente de Y *)

% Listas:
    ?- X = [1, haniel, true]. % (* Será True quando X for instanciado com esse formato de lista *)
    ?- [1,2|X] = [1,2,3,4,5]. % (* Será True quando X for instanciado com [3, 4, 5] *): Equivalente: ?- [1|[2|x]]
    % "|": construtor de lista: [head | head or tail]

    % (* Concatenar duas listas *)
    append([], L, L).
    append([Head|TailA], B, [Head|TailC]) :- append(TailA, B, TailC). 
    % (* Casando elemento a elemento à esquerda: os "Head" tem que ser os mesmos. 
    % A lista a esquerda se esgota e cairemos no primeiro caso *)

    % (* Pertencimento a listas *)
    member(X, [X|_]).
    member(X, [_|Y]) :- member(X, Y).  