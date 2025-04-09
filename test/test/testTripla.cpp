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