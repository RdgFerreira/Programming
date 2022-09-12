import sys

""" 
 Classe que define o que deve compor o nó da árvore Trie principal:
       "char": o caracter que representa o fim de uma nova substring do texto.

       "idxOfThisSubstring": número que representa a nova substring formada pelo caracter do nó,
    ou seja, esse atributo será igual a i sse ele é o fim da i-ésima nova substring lida do texto.
       
       "idxOfLastSubstring": código correspondente ao char armazenado no nó, definido pelo
    idxOfThisSubstring do nó pai do nó em questão, configurando o código de aproveitamento de substrings de acordo com o LZ78.

       "children": nós filhos do nó em questão, definidos em função de um dicionário onde 
    chaves são os caracteres e valores são seus nós filhos.
"""
class Node:
    
    def __init__(self, char, idxOfThisSubstring, idxOfLastSubstring):
        self.char = char
        self.idxOfThisSubstring = idxOfThisSubstring
        self.idxOfLastSubstring = idxOfLastSubstring
        self.children = {}


"""
 Classe da árvore Trie principal:
       "root": nó raiz da árvore que é construído com uma string vazia, e ambos os atributos de código zerados
       
       "Insert": método de inserção de uma substring nova do texto na árvore:
               Recebe o caracter a ser inserido na Trie, que configura a nova substring a ser registrada, o contador
               dessa nova substring e o nó (node) de parada após o fim do procedimento de busca no código principal.
               Então, o novo nó é criado com esse último caracter lido, "idxOfThisSubstring" recebe o número da i-ésima
               substring nova lida do texto ("idxOfNewSubstring") e "idxOfLastSubstring" recebe o "idxOfThisSubstring" do seu nó pai (node)
               definindo o código nó filho. O valor desse último parâmetro é retornado pelo método.
"""
class Trie(object):

    def __init__(self):
        self.root = Node("", 0, 0)
    
    def Insert(self, char : str, idxOfNewSubstring : int, node : Node):
        new_node = Node(char, idxOfNewSubstring, node.idxOfThisSubstring)
        node.children[char] = new_node
        code = new_node.idxOfLastSubstring
        return code

# ============================================================================================================================================
# Código principal do programa
if __name__=="__main__":
    
    # Argumento correspondente à compressão de um arquivo .txt para .z78    
    if sys.argv[1] == "-c":

        # Formatação dos arquivos de entrada e saída de acordo com a ação desejada: compressão
        inputFile = open(sys.argv[2], "r")
        outputFile = (str(sys.argv[2]))[:-4] + ".z78"
        outputFile = open(outputFile, "w")

        Dict = Trie()

        """ 
            Parâmetros relevantes para uma análise dos tamanhos dos arquivos e obtenção taxa de compressão:

            "newSubstringCounter": contador de novas substrings do texto, correspondente ao número total de nós na Trie
            "maxTrieCode": inteiro que guarda o código de maior valor na dicionário da Trie: será usado para calcular o tamanho do 
                arquivo comprimido
            "originalTextSize": conta os caracteres do texto original
        """
        newSubstringCounter = 0
        maxTrieCode = -1
        originalTextSize = 0

        """
            Loop principal de compressão:
                Lê o texto caracter a caracter e insere na Trie sucessivas novas substrings lidas do arquivo original.
                Simultaneamente a esse processo, os contadores de novas substrings e tamanho do texto original são atualizados
                de acordo. Isso é somado a busca do maior código (linha 91) e escrita de novos códigos e seus respectivos caracteres no arquivo
                .z78 (linha 92) no momento em que novas substrings são encontradas.
        """
        currentNode = Dict.root
        while c := inputFile.readline(1): # Leitura caracter a caracter do texto
            originalTextSize += 1
            if c in currentNode.children:
                currentNode = currentNode.children[c]
            else:
                newSubstringCounter += 1
                code = Dict.Insert(c, newSubstringCounter, currentNode)
                if code >= maxTrieCode: maxTrieCode = code
                outputFile.write(str(code) + "," + c)   # Escrita das duplas separadas por vírgula
                currentNode = Dict.root                 # Com a falha da busca e a inserção do novo nó, voltamos à raiz e recomeçamos o processo

        inputFile.close()
        outputFile.close()
        """
            Reportagem dos resultados da compressão:
                Destaque para o cálculo do arquivo comprimido:
                O arquivo .z78 é conatituído por apenas pares de códigos e caracteres, que representam os nós da Trie.
                Um caracter = 1 byte = 8 bits. Contudo, para sabermos quantos bits precisamos para guardar os inteiros (códigos), podemos assumir
                apenas o tamanho do maior código na Trie (maxCode) em bits, que é suficiente para representar todos os outros códigos.

                Portanto, o tamanho do arquivo comprimido será (o número de nós na Trie) * (8 + número de bits do maior código encontrado) bits.
                Por fim, é calculado a razão do tamanho do arquivo comprimido sobre o tamanho do arquivo original (ambos em bits).

                Nesse sentido, caso o arquivo original tenha 100 bits e o comprimido tenha 90 bits, essa razão nos indica que
                o arquivo comprimido constitui 90% do tamanho do original e, portanto, conseguimos comprimir o arquivo original 
                em 100% - 90% = 10%. Essa é a lógica para reportar a taxa de compressão: 1 - (compressedSize / originalSize).
        """
        if maxTrieCode != -1:
            print("Maior código para o dicionário codificador: ", maxTrieCode)
            print("Tamanho do arquivo original em bytes: ", originalTextSize)
            print("Tamanho do arquivo original em bits: ", originalTextSize * 8)
            print("Número de nós na Trie: ", newSubstringCounter)
            compressedFileSize = (newSubstringCounter * (8 + (len(format(maxTrieCode, 'b')))))
            print("Tamanho do arquivo comprimido em bits: ", compressedFileSize)
            compressedOverOriginal = compressedFileSize / (originalTextSize * 8)
            print("Taxa de compressão: ", 1 - compressedOverOriginal)
        else:
            print("Arquivo a ser comprimido está vazio!")
    
    # Argumento correspondente à descompressão de um arquivo .z78 para .txt
    elif sys.argv[1] == "-x":

        # Formatação dos arquivos de entrada e saída de acordo com a ação desejada: descompressão
        inputFile = open(sys.argv[2], "r")
        outputFile = (str(sys.argv[2]))[:-4] + ".txt"
        outputFile = open(outputFile, "w")

        """ 
            Lista buffer armazena os pares código,string em tuplas. Será usada para recusrsivamente recuperar,
            por meio dos códigos, a substring a ser escrita no arquivo .txt.
            "strToWrite" armazena essa substring recuperada
        """
        buffer = []
        buffer.append((-1, "")) # inicializado com a raiz
        strToWrite = ""

        while code := inputFile.readline(1):
            # Recuperação do código (inteiro): leitura char a char até achar o separador ","
            rest = inputFile.readline(1)
            if(rest != ","):
                while rest != ",":
                    code += rest
                    rest = inputFile.readline(1)
            
            # Leitura do char da dupla do dicionário e registro no buffer
            char = inputFile.readline(1)
            buffer.append((code, char))

            """ 
                Recuperação da substring a ser escrita no arquivo .txt. São feitos acessos sucessivos
                aos pares existentes por meio dos códigos associados até que a raiz seja atingida.
            """
            while True:
                if int(code) == -1 and char == "": break
                strToWrite = char + strToWrite
                (code, char) = buffer[int(code)]
            
            # Escrita da substring no texto e limpa da strToWrite para ler uma nova substring
            outputFile.write(strToWrite)
            strToWrite = ""

        inputFile.close()
        outputFile.close()

    else:
        print("Argumento Inválido!")