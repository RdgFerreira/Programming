import numpy as np
# np.set_printoptions(linewidth=1000)
to_print_veros = 0





def print_arr(arr, size):
    for i in range(size):
        arr[i] = np.round(arr[i], decimals = 7)
        if arr[i] == 0:
            if i != 0: print("", int(arr[i]), end="")
            else: print(int(arr[i]), end="")
        elif int(arr[i]) != 0:
            if((arr[i] / (int(arr[i]))) == 1):
                if i != 0: print("", int(arr[i]), end="")
                else: print(int(arr[i]), end="")
            else:
                if i != 0: print("", arr[i], end="")
                else: print(arr[i], end="")
        else:
            if i != 0: print("", arr[i], end="")
            else: print(arr[i], end="")





def pivot (line, col, A):
    if A[line][col] == 0: 
        return -1
  
    A[line] = A[line] / A[line][col]

    for i in range(line):
        A[i] = A[i] - (A[i][col] * A[line])

    if line == A.shape[0] - 1: 
        return A
    else:
        for i in range(line+1, A.shape[0]):
            A[i] = A[i] - (A[i][col] * A[line])
    return A





def to_FPI_and_canon(A, c1):
    # Empurra uma identidade positiva (<=) mais a direita e zera entradas correspondentes no vetor c
    I = np.identity(A.shape[0], dtype=np.float64)
    zeros = np.zeros(I.shape[0], dtype=np.float64)
    
    b = A[: , A.shape[1] - 1]
    A = A[: , :A.shape[1] - 1]
    
    A = np.concatenate((A, I), axis=1)
    A = np.concatenate((A, np.reshape(b, (A.shape[0], 1))), axis=1)
    
    c1 = np.concatenate((c1, zeros), axis=None)
    
    return A, c1




def is_C_non_negative(c):
    for i in range(c.size):
        if (c[i] >= 0): continue
        else: return False
    return True




def get_pivot_column_index(first_row, lower_row):
    import math
    pivot_column_index = 0;lowest_ratio = math.inf
    if ((first_row.size == lower_row.size) == False): return 99, 99
    found = 0
    
    for i in range(first_row.size):
        if (lower_row[i] >= (-1e-7)): continue
        
        ratio = first_row[i] / ((-1) * lower_row[i])
        if ratio <= 1e-7:
            found = 1
            pivot_column_index = i
            break

        if (first_row[i] == 0):
            found = 1
            pivot_column_index = i
            break

        if (ratio < lowest_ratio):
            found = 1
            lowest_ratio = ratio
            pivot_column_index = i

    return pivot_column_index, found






def build_VEROs(A1, c1): # PL em FPI já forma base
    I = np.identity(A1.shape[0], dtype=np.float64)
    A = np.concatenate((I, A1), axis=1)
    upper_left_zeros = np.zeros(I.shape[0], dtype=np.float64)

    _c = (-1.0) * c1
    _c = np.append(_c, 0.0)

    first_row = np.concatenate((upper_left_zeros, _c), axis=None)
    first_row = np.reshape(first_row, (1, first_row.size))

    VERO = np.concatenate((first_row, A), axis=0)
    
    b = VERO[1: , VERO.shape[1] - 1]
    # c_start_index = VERO.shape[0] - 1

    i = 0
    is_optimal = 0
    while(i < b.size):
        # VERO_c = VERO[0][c_start_index:(VERO.shape[1] - 1)]
        # b = VERO[1: , VERO.shape[1] - 1]
        # if is_C_non_negative(VERO_c):
        #     if b[i] < 0.0:
        #         pivot_row_index = i+1
        #         lower_row = VERO[i+1 , c_start_index:(VERO.shape[1] - 1)]
        #         pivot_column_index, found = get_pivot_column_index(VERO_c, lower_row)
        #         pivot_column_index += c_start_index
        #         VERO = pivot(pivot_row_index, pivot_column_index, VERO) #Simplex Dual: C todo negativo e pelo menos 1 valor em b negativo
        #         i = 0 # Procura valores negativos em b novamente
        #         continue
        #     if(i + 1) == b.size:
        #         is_optimal = 1
        #     i += 1
                
        if b[i] < 0.0:
            VERO[i+1] = (-1.0) * VERO[i+1]
            i += 1
        
        else: i += 1

    #============================================= AUX
    
    b = np.reshape(VERO[1: , VERO.shape[1] - 1], (I.shape[0], 1))
    
    VERO_aux = VERO[1: , :VERO.shape[1] - 1]
    first_row = np.zeros(VERO_aux.shape[1], dtype=np.float64)
    
    VERO_aux = np.concatenate((VERO_aux, I), axis=1)
    column_indexes_to_pivot = np.arange(VERO_aux.shape[1] - (I.shape[0]), VERO_aux.shape[1])

    for i in range(VERO_aux.shape[1] - (I.shape[0]), VERO_aux.shape[1]):
        first_row = np.append(first_row, 1.0)

    first_row = np.append(first_row, 0.0)
    first_row = np.reshape(first_row, (1, first_row.size))
    
    VERO_aux = np.concatenate((VERO_aux, b), axis=1)
    VERO_aux = np.concatenate((first_row, VERO_aux), axis=0)
    
    for i in range(I.shape[0]):
        VERO_aux = pivot((i+1), int(column_indexes_to_pivot[i]), VERO_aux)
    
    return VERO, VERO_aux, is_optimal





def get_c(VERO):
    c_start_index = VERO.shape[0] - 1
    c = VERO[0, c_start_index:VERO.shape[1] - 1]
    return c




def get_basic_solution(VERO):
    c_start_index = VERO.shape[0] - 1
    c = VERO[0, c_start_index:VERO.shape[1] - 1]
    b = VERO[: , VERO.shape[1] - 1]
    x = np.zeros(c.size, dtype=np.float64) 
    
    for i in range(c.size):
        if c[i] != 0: continue
        else:
            for line in range(1, VERO.shape[0]):
                if VERO[line][c_start_index + i] == 0: continue
                elif VERO[line][c_start_index + i] != 1:
                        x[i] = 0.0
                        break # coluna tem 0 no c, mas não é uma coluna de identidade.
                else: 
                    x[i] = b[line]
    return x




def is_row_non_negative(c):
    for i in range(c.size):
        if (c[i] < -(1e-7)): return i
    return -1




def is_optimal_or_index_of_column_to_enter_base(c):
    return is_row_non_negative(c)




def get_pivot_row_index(right_column, column_to_enter_base):
    import math
    pivot_row_index = 0;lowest_ratio = math.inf
    found = 0
    if ((right_column.size == column_to_enter_base.size) == False): return 99, 99
    
    for i in range(1, right_column.size):
        if (column_to_enter_base[i] <= 1e-7): continue
        
        ratio = right_column[i] / column_to_enter_base[i]
        if ratio <= 1e-7:
            found = 1
            pivot_row_index = i
            break

        
        if (right_column[i] == 0):
            found = 1
            pivot_row_index = i
            break

        if (ratio < lowest_ratio):
            found = 1
            lowest_ratio = ratio
            pivot_row_index = i

    return pivot_row_index, found




def get_obj_value(VERO):
    return VERO[0][VERO.shape[1] - 1]




def get_certificate(VERO, c_start_index):
    return VERO[0, :c_start_index]




def get_unlimited_certificate(VERO, index_of_unlimited_column):
    c_start_index = VERO.shape[0] - 1
    c = VERO[0, c_start_index:VERO.shape[1] - 1]
    x = np.zeros(c.size) 
    
    for i in range(c.size):
        if (i + c_start_index) == index_of_unlimited_column:
            x[i] = 1
            continue
        elif c[i] != 0: continue
        else:
            for j in range(VERO.shape[0]):
                if VERO[j][i + c_start_index] == 1:
                    x[i] = (-1.0) * VERO[j][index_of_unlimited_column]
    return x





def get_base_columns(VERO):
    c_start_index = VERO.shape[0] - 1
    c = VERO[0, c_start_index:VERO.shape[1] - 1]
    base_columns = np.array([])
    # print(c, "\n\n", VERO, "\n\n")
    
    for i in range(c.size):
        if c[i] != 0: continue
        else:
            for line in range(1, VERO.shape[0]):
                if VERO[line][c_start_index + i] == 0: continue
                elif VERO[line][c_start_index + i] != 1:
                        break # coluna tem 0 no c, mas não é uma coluna de identidade.
                else: 
                    base_columns = np.append(base_columns, c_start_index + i)
    return base_columns





def adjust_VERO_from_aux(VERO, VERO_aux, new_base_columns):
    b = np.reshape(VERO_aux[: , VERO_aux.shape[1] - 1], (VERO_aux.shape[0], 1))
    
    new_VERO = VERO_aux[1: , :VERO.shape[1] - 1]
    first_row = np.reshape(VERO[0, :VERO.shape[1] - 1], (1, VERO.shape[1] - 1))
    new_VERO = np.concatenate((first_row, new_VERO), axis=0)
    
    for i in range(new_base_columns.size):
        if (int(new_base_columns[i])) <= VERO.shape[1] - 2: continue # coluna básica não artificial pode ir até a penúltima coluna do VERO original
        else: # Coluna básica artificial: linha redundante?
            new_base_column = np.reshape(VERO_aux[: , int(new_base_columns[i])], (VERO_aux.shape[0], 1))
            new_VERO = np.concatenate((new_VERO, new_base_column), axis=1)
            new_base_columns[i] = new_VERO.shape[1] - 1 # índice da nova coluna básica artificial é o da coluna mais a direita
    
    new_VERO = np.concatenate((new_VERO, b), axis=1)
    # first_row = new_VERO[0, :new_VERO.shape[1] - 1]
    # print(first_row, new_base_columns, new_VERO)
    for j in(new_base_columns):
        first_row = new_VERO[0, :new_VERO.shape[1] - 1]
        if first_row[int(j)] == 0: continue
        else:
            for i in range(1, new_VERO.shape[0]):
                if new_VERO[i][int(j)] != 1: continue
                else:
                    new_VERO = pivot(i, int(j), new_VERO)
                    break
    
    return new_VERO




def SIMPLEX_AUX(VERO_aux):
    c_start_index = VERO_aux.shape[0] - 1
    
    while(1):
        if (to_print_veros == 1): print("VERO_aux:\n");print(VERO_aux)
        c = get_c(VERO_aux)
        index_of_col_to_enter_base = is_optimal_or_index_of_column_to_enter_base(c)

        if index_of_col_to_enter_base == -1:
            # print("OPTIMAL_aux:\n", get_obj_value(VERO_aux))
            return get_obj_value(VERO_aux), get_certificate(VERO_aux, c_start_index), get_basic_solution(VERO_aux), VERO_aux, get_base_columns(VERO_aux)

        index_of_col_to_enter_base += c_start_index

        column_to_enter_base = VERO_aux[: , index_of_col_to_enter_base] 

        right_column = VERO_aux[: , VERO_aux.shape[1] - 1]

        pivot_row_index, found = get_pivot_row_index(right_column, column_to_enter_base)

        VERO_aux = pivot(pivot_row_index, index_of_col_to_enter_base, VERO_aux)
        # VERO_aux = np.round(VERO_aux, decimals = 8)



def SIMPLEX_V4(VERO, VERO_aux, c_original_size, original_A):
    c_start_index = VERO.shape[0] - 1
    
    obj_aux, impossible_certificate, sol_aux, VERO_aux, new_base_columns = SIMPLEX_AUX(VERO_aux)
    if obj_aux < -(1e-7):
        print("inviavel")
        print_arr(impossible_certificate, impossible_certificate.size)
        return 
    
    VERO = adjust_VERO_from_aux(VERO, VERO_aux, new_base_columns)
    
    while(1):
        if (to_print_veros == 1): print("VERO:\n");print(VERO)
        c = get_c(VERO)
        index_of_col_to_enter_base = is_optimal_or_index_of_column_to_enter_base(c)

        if index_of_col_to_enter_base == -1:
            print("otima")
            print_arr(np.array([get_obj_value(VERO)]), 1)
            print("")
            print_arr(get_basic_solution(VERO), c_original_size)
            print("")
            optimal_certificate = get_certificate(VERO, c_start_index)
            print_arr(optimal_certificate, optimal_certificate.size)
            break 

        index_of_col_to_enter_base += c_start_index

        column_to_enter_base = VERO[: , index_of_col_to_enter_base] 

        right_column = VERO[: , VERO.shape[1] - 1]

        pivot_row_index, found = get_pivot_row_index(right_column, column_to_enter_base)
        if (found == 0):
            print("ilimitada")
            print_arr(get_basic_solution(VERO), c_original_size)
            print("")
            print_arr(get_unlimited_certificate(VERO, index_of_col_to_enter_base), c_original_size)
            # print("")
            # print("A x d:")
            # print(np.round(original_A[:, :original_A.shape[1] - 1] @ get_unlimited_certificate(VERO, index_of_col_to_enter_base), decimals = 3))
            # print("Ax")
            # print(original_A[:, :original_A.shape[1] - 1] @ get_basic_solution(VERO)[:c_original_size])
            # print("b")
            # print(original_A[:, original_A.shape[1] - 1])
            # print(original_A[:, :original_A.shape[1] - 1] @ np.array([1, 0.3300493, 1.37931, 0, 0, 0, 0]))
            break

        VERO = pivot(pivot_row_index, index_of_col_to_enter_base, VERO)
        # VERO = np.round(VERO, decimals = 8)

def SIMPLEX_V5(c1, A):
    A = A.astype(np.float64)
    c1 = c1.astype(np.float64)
    c_original_size = c1.size
    # original_A = A
    
    A, c1 = to_FPI_and_canon(A, c1)
    original_A = A
    if to_print_veros == 1: print("Matriz original: \n", A)
    VERO, VERO_aux, is_optimal = build_VEROs(A, c1)
    if (to_print_veros == 1): print("VERO_inicial: \n", VERO, "\nVERO_aux_inicial: \n", VERO_aux, "\n")

    # if(is_optimal == 1):
    #     print("otima")
    #     print_arr(np.array([get_obj_value(VERO)]), 1)
    #     print("")
    #     print_arr(get_basic_solution(VERO), c_original_size)
    #     print("")
    #     c_start_index = VERO.shape[0] - 1 
    #     optimal_certificate = get_certificate(VERO, c_start_index)
    #     print_arr(optimal_certificate, optimal_certificate.size)
    #     return
    
    SIMPLEX_V4(VERO, VERO_aux, c_original_size, original_A)



def SIMPLEX():
    shape = np.array([])
    shape_input = input()
    shape_arr = shape_input.split()
    for i in range(len(shape_arr)):
        shape = np.append(shape, int(shape_arr[i]))
    shape = np.array(shape)
    shape = shape.astype(int)
#     print(shape)

    c = np.array([])
    c_input = input()
    c_arr = c_input.split()
    for i in range(len(c_arr)):
        c = np.append(c, int(c_arr[i]))
    c1 = np.array(c, dtype=np.float64)
#     print(c1)

    shape[1] += 1 # coluna b à esquerda
    A = np.zeros(shape.astype(int), dtype=np.float64)
    for i in range(shape[0]):
        line_input = input()
        line_arr = line_input.split() 
        for j in range(shape[1]):
            A[i][j] = int(line_arr[j])
#     print(A)

    SIMPLEX_V5(c1, A)



SIMPLEX()