#include <iostream>
using namespace std;

typedef int TipoChave;

class TipoItem 
{
    public:
        TipoItem() {
            chave = -1;
        }
        TipoItem(TipoChave c) {
            chave = c;
        }
        void SetChave(TipoChave c) {
            chave = c;
        }
        TipoChave GetChave() {
            return chave;
        }
        bool Vazio() {
            return chave == -1;
        }
        void Imprime() {
            cout << chave << " ";
        }

    private:
        TipoChave chave;
};

class Lista 
{
    public:
        Lista() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        
        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;

        virtual void InsereInicio(TipoItem item) = 0;
        virtual void InsereFinal(TipoItem item) = 0;
        virtual void InserePosicao(TipoItem item, int pos) = 0;

        virtual TipoItem RemoveInicio() = 0;
        virtual TipoItem RemoveFinal() = 0;
        virtual TipoItem RemovePosicao(int pos) = 0;
        virtual TipoItem Pesquisa(TipoChave c) = 0;

        virtual void Imprime() = 0;
        virtual void Limpa() = 0;
        //virtual ~Lista() {};

    protected:
        int tamanho;
};

class TipoCelula
{
    public:
        TipoCelula() {
            item.SetChave(-1);
            prox = NULL;
        }

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class ListaEncadeada;
};

class ListaEncadeada : public Lista 
{
    public:
        ListaEncadeada() {
            primeiro = new TipoCelula();
            ultimo = primeiro;
        }

        ~ListaEncadeada() {
            Limpa();
            delete primeiro;
        }

        TipoItem GetItem(int pos) {
            TipoCelula *p;

            p = Posiciona(pos);
            return p->item;
        }

        void SetItem(TipoItem item, int pos) {
            TipoCelula *p;

            p = Posiciona(pos);
            p->item = item;
        }

        void InsereInicio(TipoItem item) {
            TipoCelula *nova;
            nova = new TipoCelula();
            nova->item = item;

            nova->prox = primeiro->prox;
            primeiro->prox = nova;
            tamanho++;

            if(nova->prox == NULL) {
                ultimo = nova;
            }
        }

        void InsereFinal(TipoItem item) {
            TipoCelula *nova;
            nova = new TipoCelula();
            nova->item = item;
            nova->prox = NULL;
            ultimo->prox = nova;
            ultimo = nova;
            tamanho++;
        }

        void InserePosicao(TipoItem item, int pos) {
            TipoCelula *p, *nova;

            p = Posiciona(pos,true); // posiciona na célula anterior
            nova = new TipoCelula();
            nova->item = item;

            if ( (pos > (tamanho+1)) || (pos <= 0) ) {
                cout << "InserePosicao ->ERRO: Posicao Invalida!" << endl;
                throw "";
            }

            if (pos == (tamanho+1)) {
                return InsereFinal(item);
            }
            else if (pos == 1) {
                return InsereInicio(item);
            }
            else {
                nova->prox = p->prox;
                p->prox = nova;
                tamanho++;

                if(nova->prox == NULL) {
                    ultimo = nova;
                }
            }
        }

        TipoItem RemoveInicio() {
            TipoItem aux;
            TipoCelula *p;

            if (tamanho == 0) {
                cout << "ERRO: Lista Vazia!" << endl;
                throw "";
            }

            p = primeiro->prox;
            primeiro->prox = p->prox;
            tamanho--;

            if(primeiro->prox == NULL) {
                ultimo = primeiro;
            }

            aux = p->item;
            delete p;

            return aux;
        }

        TipoItem RemoveFinal() {
            TipoItem aux;
            TipoCelula *p;

            if (tamanho == 0) {
                cout << "ERRO: Lista Vazia!" << endl;
                throw "";
            }
            // posiciona p na celula anterior à última
            p = Posiciona(tamanho, true);

            p->prox = NULL;
            tamanho--;
            aux = ultimo->item;
            delete ultimo;
            ultimo = p;

            return aux;
        }

        TipoItem RemovePosicao(int pos) {
            TipoItem aux;
            TipoCelula *p, *q;

            if (tamanho == 0) {
                cout << "ERRO: Lista Vazia!" << endl;
                throw "";
            }

            // posiciona p na celula anterior à pos
            p = Posiciona(pos, true);

            q = p->prox;
            p->prox = q->prox;
            tamanho--;
            aux = q->item;
            delete q;

            if(p->prox == NULL) {
                ultimo = p;
            }

            return aux;
        }

        TipoItem RemoveItem(TipoChave c) {
            TipoItem aux; TipoCelula *p, *q;

            // Posiociona p na célula anterior ao item procurado
            p = primeiro;

            while ( (p->prox!=NULL) && (p->prox->item.GetChave() != c) ) p = p->prox;

            // remove a célula contendo o item, retornando-o
            if(p->prox == NULL) {
                cout << "Erro: item não está presente";
                throw "";
            }
            else {
                q = p->prox;
                p->prox = q->prox;
                aux = q->item;
                delete q;
                tamanho--;
                if(p->prox == NULL) ultimo = p;
            }
            return aux;
        }

        TipoItem Pesquisa(TipoChave c) {
            TipoItem aux;
            TipoCelula *p;

            p = primeiro->prox;
            aux.SetChave(-1);

            while (p!=NULL) {
                if (p->item.GetChave() == c) {
                    aux = p->item;
                    break;
                }
                p = p->prox;
            }

            return aux;
        }

        void Imprime() {
            TipoCelula *p;
            p = primeiro->prox;

            cout << "[";

            while (p != NULL) { // O(n)
                if (p->prox == NULL) {
                    cout << p->item.GetChave();
                }
                else {
                    cout << p->item.GetChave() << ", ";
                }
                p = p->prox;
            }

            cout << "]";
            cout << endl;
        }

        void Limpa() {
            TipoCelula *p;

            p = primeiro->prox;

            while (p!=NULL) {
                primeiro->prox = p->prox;
                delete p;
                p = primeiro->prox;
            }

            ultimo = primeiro;
            tamanho = 0;
        }

        // Funções Teste =================================================================================================
        // void MoveItem(TipoChave c);

    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;

        TipoCelula* Posiciona(int pos, bool antes=false) {
            TipoCelula *p; 
            int i;

            if ( (pos > (tamanho+1)) || (pos <= 0) ) {
                cout << "Posiciona->ERRO: Posicao Invalida!" << endl;
                throw "";
            }
            
            // Posiciona na célula anterior a desejada
            p = primeiro;
            for(i=1; i<pos; i++){
                p = p->prox;
            }

            // vai para a próxima se antes for false
            if(!antes) {
                p = p->prox;
            }
            return p;
        }
};

class Hash_LE {
    public:
        Hash_LE() {

        }
        TipoItem Pesquisa(TipoChave chave) {
            int pos;
            TipoItem item;
            pos = Hash(chave);
            item = Tabela[pos].Pesquisa(chave);
            return item;
        }

        void Insere(TipoItem item) {
            TipoItem aux;
            int pos;
            aux = Pesquisa(item.GetChave());

            if(!aux.Vazio()) {
                cout << "Erro: Item já está presente" ;
                return;
            }
            pos = Hash(item.GetChave());
            Tabela[pos].InsereFinal(item);
        }

        void Remove(TipoChave chave) {
            int pos;
            pos = Hash(chave);
            Tabela[pos].RemoveItem(chave);
        }

        void ImprimeTabela() {
            for(int i = 0; i < M; i++) {
                cout << i << ": ";
                Tabela[i].Imprime();
                cout << "\n";
            }
        }
    private:
        static const int M = 9;

        int Hash(TipoChave Chave) {
            return Chave % M;
        }

        ListaEncadeada Tabela[M];
};

class Hash_EA
{
    public:
        Hash_EA() {

        }
        TipoItem Pesquisa(TipoChave chave) {
            TipoItem aux; // construtor seta o item para -1;
            int pos, i;
            pos = Hash(chave);
            i = 0;

            while ( (i<M) && !vazio[(pos+i)%M] && (Tabela[(pos+i)%M].GetChave() != chave) )
                i++;
            
            if ( (Tabela[(pos+i)%M].GetChave() == chave) && !retirado[(pos+i)%M] ) {
                aux = Tabela[(pos+i)%M];
            }
            return aux;
        }

        void Insere(TipoItem item) {
            TipoItem aux; // construtor seta o item para -1;
            int pos, i;
            aux = Pesquisa(item.GetChave());

            if(!aux.Vazio()) {
                cout << "Erro: Item já está presente";
                return;
            }

            pos = Hash(item.GetChave());
            i = 0;

            while ( (i<M) && !vazio[(pos+i)%M] && !retirado[(pos+i)%M] )
                i++;
            if(i==M) {
                cout << "Erro: Tabela está cheia";
            }
            else {
                Tabela[(pos+i)%M] = item;
                vazio[(pos+i)%M] = false;
                retirado[(pos+i)%M] = false;
            }
        }

        void Remove(TipoChave chave) {
            int pos, i;
            pos = Hash(chave);
            i = 0;

            while ( (i<M) && !vazio[(pos+i)%M] && (Tabela[(pos+i)%M].GetChave() != chave) )
                i++;
            
            if ( (Tabela[(pos+i)%M].GetChave() == chave) && !retirado[(pos+i)%M] )
                retirado[(pos+i)%M] = true;
            
            else
                cout << "Erro: Item não está presente";
        }

        void ImprimeTabela() {
            for(int i = 0; i < M; i++) {
                cout << i << ": ";
                if(vazio[i]) cout << "Vazio";
                else if(retirado[i]) cout << "Retirado";
                else Tabela[i].Imprime();
                cout << "\n";
            }
        }
    private:
        static const int M = 7;

        int Hash(TipoChave Chave) {
            return Chave % M;
        }

        TipoItem Tabela[M];
        bool vazio[M];
        bool retirado[M];
};


int main() {
    Hash_LE le;
    Hash_EA ea;

    // LUNES
    TipoChave letras[8] = {18, 19, 90, 40, 60, 43, 96, 58};
    TipoItem itens[8];

    for(int i = 0; i < 8; i++) {
        itens[i].SetChave(letras[i]);
        // itens[i].Imprime();
    }

    for(TipoItem item : itens) {
        le.Insere(item);
        ea.Insere(item);
    }

    le.Remove(19);
    ea.Remove(19);
    le.Remove(96);
    ea.Remove(96);
    le.Insere(28);
    ea.Insere(28);


    cout << "Tabela LE: \n";
    le.ImprimeTabela();
    cout << "\n" << "Tabela EA: \n";
    ea.ImprimeTabela();
    cout << endl;

    /*
    cout << "Tabela LE apos remocao de 19: \n";
    le.ImprimeTabela();
    cout << "\n" << "Tabela EA apos remocao de 19: \n";
    ea.ImprimeTabela();
    cout << endl;

    le.Remove(12);
    ea.Remove(12);

    cout << "Tabela LE apos remocao de 12: \n";
    le.ImprimeTabela();
    cout << "\n" << "Tabela EA apos remocao de 12: \n";
    ea.ImprimeTabela();
    cout << endl;
    */

    
    return 0;
}