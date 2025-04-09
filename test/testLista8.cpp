#include "gtest/gtest.h"
#include "Tripla.h"
#include "Lista8.h"

// PRUEBAS PARA LISTA8
template<class T>
class Lista8 {
private:
    Tripla<T>* primer = nullptr;
    Tripla<T>* ultimo = nullptr;

public:
    void insertar_Principio(T elem, T elem2);
    void insertar_Final(T elem, T elem2);
    void eliminar_Principio();
    Tripla<T>* getPrimer() { return primer; }
    Tripla<T>* getUltimo() { return ultimo; }
};
template<class T>
void Lista8<T>::insertar_Principio(T elem, T elem2) {
    if (primer == nullptr) {
        primer = new Tripla<T>();
        primer->setElem(elem);
        primer->pushLista(elem2);
        ultimo = primer;
    } else {
        Tripla<T>* segundo = new Tripla<T>();
        segundo->setElem(elem);
        segundo->pushLista(elem2);
        segundo->setSig(primer);
        primer->setAnt(segundo);
        primer = segundo;
    }
}

template<class T>
void Lista8<T>::insertar_Final(T elem, T elem2) {
    if (primer == nullptr) {
        primer = new Tripla<T>();
        primer->setElem(elem);
        primer->pushLista(elem2);
        ultimo = primer;
    } else {
        Tripla<T>* aux = new Tripla<T>();
        aux->setElem(elem);
        aux->pushLista(elem2);
        ultimo->setSig(aux);
        aux->setAnt(ultimo);
        ultimo = aux;
    }
}

template<class T>
void Lista8<T>::eliminar_Principio() {
    if (primer != nullptr) {
        if (primer == ultimo) {
            delete primer;
            primer = nullptr;
            ultimo = nullptr;
        } else {
            Tripla<T>* aux = primer->getSig();
            aux->setAnt(nullptr);
            delete primer;
            primer = aux;
        }
    }
}

// ---- TESTS ----

TEST(Lista8Test, InsertarPrincipio) {
    Lista8<string> lista;
    lista.insertar_Principio("A", "X");

    Tripla<string>* nodo = lista.getPrimer();
    ASSERT_NE(nodo, nullptr);
    EXPECT_EQ(nodo->getElem(), "A");
    ASSERT_EQ(nodo->getLista().size(), 1);
    EXPECT_EQ(nodo->getLista()[0], "X");
}

TEST(Lista8Test, InsertarFinal) {
    Lista8<string> lista;
    lista.insertar_Final("A", "X");
    lista.insertar_Final("B", "Y");

    Tripla<string>* primer = lista.getPrimer();
    Tripla<string>* segundo = primer->getSig();

    ASSERT_NE(segundo, nullptr);
    EXPECT_EQ(segundo->getElem(), "B");
    ASSERT_EQ(segundo->getLista().size(), 1);
    EXPECT_EQ(segundo->getLista()[0], "Y");
}

