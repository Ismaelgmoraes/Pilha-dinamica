#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef int TipoItem;

struct No
{
    TipoItem valor;
    No* proximo;
};

class Lista_encadeada
{
    public:
        Lista_encadeada();
        virtual ~Lista_encadeada();
        bool estavazio();
        bool estacheio();
        void inserir(TipoItem item);
        TipoItem remover();
        void imprimir ();

    private:
        No* NoTopo;

};

#endif // LISTA_ENCADEADA_H
