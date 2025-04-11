#include "pch.h"
#include "../../ProyectoFinal/Grafo.h"

TEST(GrafoTest, ConstructorDestructorTest) {
    Grafo<string>* g = new Grafo<string>();
    delete g; 
    SUCCEED(); 
}

TEST(GrafoTest, FuncionHashSimpleTest) {
    Grafo<string> g;
    int h = g.funcionHash("abc");
    EXPECT_GE(h, 0);
    EXPECT_LT(h, 409);
}

TEST(GrafoTest, InsertarNuevoNodoTest) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("A", "B", ciudades);
    EXPECT_EQ(ciudades.size(), 1);
    EXPECT_EQ(ciudades[0], "A");
}

TEST(GrafoTest, InsertarAdyacenteExistenteTest) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("A", "B", ciudades);
    g.insertar("A", "C", ciudades);
    Tripla<string>* nodo = g.buscar("A");
    ASSERT_NE(nodo, nullptr);
    vector<string> lista = nodo->getLista();
    EXPECT_EQ(lista.size(), 2);
    EXPECT_EQ(lista[1], "C");
}

TEST(GrafoTest, BuscarNodoExistenteTest) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("X", "Y", ciudades);
    Tripla<string>* result = g.buscar("X");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->getElem(), "X");
}

TEST(GrafoTest, BuscarNodoInexistenteTest) {
    Grafo<string> g;
    Tripla<string>* result = g.buscar("Z");
    EXPECT_EQ(result, nullptr);
}

TEST(GrafoTest, EliminarNodoExistenteTest) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("Nodo1", "Nodo2", ciudades);
    bool eliminado = g.eliminar("Nodo1");
    EXPECT_TRUE(eliminado);
    EXPECT_EQ(g.buscar("Nodo1"), nullptr);
}

TEST(GrafoTest, EliminarNodoInexistenteTest) {
    Grafo<string> g;
    bool eliminado = g.eliminar("NoExiste");
    EXPECT_FALSE(eliminado);
}

TEST(GrafoTest, SacarAdyacenteTest) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("Origen", "Destino", ciudades);
    string adyacente;
    g.SacarAdyacente("Origen", adyacente);
    EXPECT_EQ(adyacente, "Destino");
}

TEST(GrafoTest, MostrarTest) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("A", "B", ciudades);
    g.insertar("C", "D", ciudades);
    testing::internal::CaptureStdout();
    g.Mostrar();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("A") != string::npos || output.find("C") != string::npos);
}
TEST(GrafoTest, FuncionHashCadenaVacia) {
    Grafo<string> g;
    int h = g.funcionHash("");
    EXPECT_GE(h, 0);
    EXPECT_LT(h, 409);
}
TEST(GrafoTest, InsertarNodoYaExistenteAgregaAdyacente) {
    Grafo<string> g;
    vector<string> ciudades;
    g.insertar("Ciudad1", "Ciudad2", ciudades); 
    g.insertar("Ciudad1", "Ciudad3", ciudades); 
    Tripla<string>* nodo = g.buscar("Ciudad1");
    ASSERT_NE(nodo, nullptr);
    vector<string> lista = nodo->getLista();
    EXPECT_EQ(lista.size(), 2);
    EXPECT_EQ(lista[0], "Ciudad2");
    EXPECT_EQ(lista[1], "Ciudad3");
}