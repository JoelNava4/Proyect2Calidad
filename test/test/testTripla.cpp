#include "pch.h"
#include "../../ProyectoFinal/Tripla.h"

using namespace std;

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

TEST(TriplaTest, SetAndGetSigAnt) {
    Tripla<int> t1, t2, t3;
    t1.setSig(&t2);
    t1.setAnt(&t3);
    EXPECT_EQ(t1.getSig(), &t2);
    EXPECT_EQ(t1.getAnt(), &t3);
}

TEST(TriplaTest, EliminarUltimoElementoListaTest) {
    Tripla<int> t;
    t.pushLista(10);
    t.pushLista(20);
    t.EliminarUnElementoLista(20);
    vector<int> lista = t.getLista();
    EXPECT_EQ(lista.size(), 1);
    EXPECT_TRUE(find(lista.begin(), lista.end(), 20) == lista.end());
}

TEST(TriplaTest, EliminarElementoMultiplesOcurrencias) {
    Tripla<int> t;
    t.pushLista(5);
    t.pushLista(10);
    t.pushLista(10); 
    t.pushLista(15);
    t.EliminarUnElementoLista(10);
    vector<int> lista = t.getLista();
    EXPECT_EQ(lista.size(), 2);
    EXPECT_TRUE(find(lista.begin(), lista.end(), 10) == lista.end());
}

TEST(TriplaTest, EliminarCaminateTest) {
    Tripla<int> t;
    t.pushLista(1);
    t.pushLista(2);
    t.EliminarCaminate();
    vector<int> lista = t.getLista();
    EXPECT_EQ(lista.size(), 1);
    EXPECT_EQ(lista[0], 2);
}

TEST(TriplaTest, MostrarListaTest) {
    Tripla<int> t;
    t.pushLista(1);
    t.pushLista(2);
    testing::internal::CaptureStdout();
    t.mostrarLista();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_NE(output.find("2"), std::string::npos);
}

TEST(TriplaTest, SacarUnElemListaUnicaEntrada) {
    Tripla<int> t;
    t.pushLista(999);
    int elem;
    t.SacarUnElemLista(elem);
    EXPECT_EQ(elem, 999);
}

TEST(TriplaTest, SacarUnElemListaConMultiples) {
    Tripla<int> t;
    t.pushLista(10);
    t.pushLista(20);
    t.pushLista(30);
    int elem;
    t.SacarUnElemLista(elem);
    vector<int> lista = t.getLista();
    EXPECT_TRUE(find(lista.begin(), lista.end(), elem) != lista.end());
}