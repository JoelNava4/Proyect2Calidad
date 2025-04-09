#include "pch.h"
#include "../../ProyectoFinal/Tripla.h"

TEST(TriplaTest, SetAndGetElem) {
    Tripla<int> t;
    t.setElem(42);
    EXPECT_EQ(t.getElem(), 42);
}

TEST(TriplaTest, PushGetLista) {
    Tripla<string> t;
    t.pushLista("Joel");
    t.pushLista("Nava");
    vector<string> lista = t.getLista();
    EXPECT_EQ(lista.size(), 2);
    EXPECT_EQ(lista[0], "Joel");
    EXPECT_EQ(lista[1], "Nava");
}

TEST(TriplaTest, PrimerElemListaTest) {
    Tripla<int> t;
    t.pushLista(10);
    t.pushLista(20);
    EXPECT_EQ(t.PrimerElemLista(), 10);
}

TEST(TriplaTest, EliminarUnElementoListaTest) {
    Tripla<int> t;
    t.pushLista(5);
    t.pushLista(10);
    t.pushLista(15);
    t.EliminarUnElementoLista(10);
    vector<int> lista = t.getLista();
    EXPECT_EQ(lista.size(), 2);
    EXPECT_TRUE(find(lista.begin(), lista.end(), 10) == lista.end());
}

TEST(TriplaTest, SacarUnElemListaTest) {
    Tripla<int> t;
    t.pushLista(1);
    t.pushLista(2);
    t.pushLista(3);
    int elem;
    t.SacarUnElemLista(elem);
    vector<int> lista = t.getLista();
    EXPECT_TRUE(find(lista.begin(), lista.end(), elem) != lista.end());
}
