(*
    *** SMT -> Satisfabilidade Módulo Teorias
        ** Satisfabilidade em lógica de predicados
    
    *** SMT Solver (cvc5) -> Programa que resolve problemas SMT

    *** Equivalência de programas como SMT

    *** Interface SMT-LIB:linguagem de s-expressions para formular problemas em SMT
        ** s-expressions: (a b c ... z), (+ 2 3) == 2 = 3
*)

(*
    # ITE(c, e1, e2) is equivalent ITE(Not(c), e2, e1)
    # BExpr --> Bool
    # Expr --> Int

    (declare-const c Bool)
    (declare-const e1 Int)
    (declare-const e2 Int)

    (define-fun p0 () Int (ite c e1 e2))                    # ITE em cvc5
    (define-fun p1 () Int (ite (not c) e2 e1))              # programas definidos
    
    # VALIDADE: sempre verdadeira; SATISFABILIDADE: pode ser verdadeira
        # P não é válida <--> not(P) é satisfatível
        # P é válida <--> not(P) é insatisfatível

    # Queremos demonstrar que a negação da equivalência de p1 e p2 (P válida) é insatisfatível

    # forall c, e1, e2. (ite c e1 e2) = (ite (not c) e2 e1) -> valid? # 1st order logic equivalence
    # exists c, e1, e2. (ite c e1 e2) != (ite (not c) e2 e1) -> unsat?

    (assert (not (= p0 p1)))
    (check-sat) 
        # Saída: unsat 
        # not (= p0 p1) é insatisfatível <--> sua negação é válida

    (get-model) # valoração para as variáveis t.q. a fórmula seja satisfatível
*)
























