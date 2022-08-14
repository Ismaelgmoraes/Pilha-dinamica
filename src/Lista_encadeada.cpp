#include <iostream>
#include <cstddef>
#include "Lista_encadeada.h"

// esta lista encadeada é uma lista dinamica

using namespace std;


Lista_encadeada::Lista_encadeada()
{
    NoTopo = NULL;
}

Lista_encadeada::~Lista_encadeada()
{
    No* NoTemp;
    while (NoTopo != NULL){
        NoTemp = NoTopo;
        NoTopo = NoTopo -> proximo;
        delete NoTemp;
    }
}

bool Lista_encadeada::estavazio()  // verifica se o topo está apontando para nulo.
{
    return (NoTopo == NULL);
}
bool Lista_encadeada::estacheio()  // verifica se tem memoria no computador.
{
    No* NoNovo;
    try{
        NoNovo = new No;
        delete NoNovo;
        return false;
    }catch (bad_alloc& exception){
        return true;
    }
}
void Lista_encadeada::inserir(TipoItem item) // push
{
    if(estacheio()){
        cout <<"A pilha esta cheia.\n";
        cout <<"Nao foi possivel inserir este elemento.\n";
    } else {
        No* NoNovo = new No;
        NoNovo -> valor  = item;
        NoNovo -> proximo = NoTopo;
        NoTopo = NoNovo;
    }
}
TipoItem Lista_encadeada::remover()
{
    if (estavazio()){
        cout << "A pilha esta vazia.\n";
        cout << "Nao foi possivel remover nenhum elemento.\n";
        return 0;
    }else{
        No* NoTemp;
        NoTemp = NoTopo;
        TipoItem item = NoTopo -> valor;
        NoTopo = NoTopo -> proximo;
        delete NoTemp;
        return item;
    }
}
void Lista_encadeada::imprimir ()
{
    No* NoTemp = NoTopo;
    cout << "Pilha: [ ";
    while (NoTemp != NULL){
        cout << NoTemp -> valor << " ";
        NoTemp = NoTemp -> proximo;
    }
    cout << "]";
}
