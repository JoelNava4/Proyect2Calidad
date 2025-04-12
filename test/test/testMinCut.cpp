#include "pch.h"
#include "../../ProyectoFinal/MinCut.h"

TEST(MinCutTest, InsertarTest) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.insertar("A", "C");
}

TEST(MinCutTest, SacarAletoriosTest) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.insertar("A", "C");
    string V1, V2;
    minCut.SacarAletorios(V1, V2);
    EXPECT_FALSE(V1.empty());
    EXPECT_FALSE(V2.empty());
    EXPECT_NE(V1, V2);
}

TEST(MinCutTest, ContraerTest) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.insertar("B", "C");
    minCut.insertar("C", "A"); 

    string V1, V2;
    minCut.Contraer(V1, V2); 
    EXPECT_FALSE(V1.empty());
    EXPECT_FALSE(V2.empty());
}

TEST(MinCutTest, CorteMinimoTest) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.insertar("B", "C");
    minCut.insertar("C", "A"); 

    int corte = minCut.CorteMinimo();
    EXPECT_GE(corte, 1);
}

TEST(MinCutTest, ReiniciarGrafoyListaTestOnly) {
    MinCut<string> minCut;
    minCut.insertar("X", "Y");
    minCut.insertar("Y", "Z");
    minCut.ReiniciarGrafoyLista(); 
    SUCCEED(); 
}

TEST(MinCutTest, MostrarCiudadesTest) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.mostrarCiudades();
}

TEST(MinCutTest, MostrarGrafoTest) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.mostrarGrafo();
}
TEST(MinCutTest, SacarAletoriosConUnSoloNodo) {
    MinCut<string> minCut;
    minCut.insertar("X", "Y");
    string V1, V2;
    minCut.SacarAletorios(V1, V2);
    EXPECT_FALSE(V1.empty());
    EXPECT_FALSE(V2.empty());
}
TEST(MinCutTest, ContraerNodoConLoop) {
    MinCut<string> minCut;
    minCut.insertar("Loop", "Loop");
    string V1, V2;
    minCut.Contraer(V1, V2);
    EXPECT_FALSE(V1.empty());
    EXPECT_FALSE(V2.empty());
}
TEST(MinCutTest, CorteMinimoGrafoVacio) {
    MinCut<string> minCut;
    int corte = minCut.CorteMinimo(); 
    EXPECT_EQ(corte, 0); 
}
TEST(MinCutTest, CorteMinimoConDosNodos) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    int corte = minCut.CorteMinimo(); 
    EXPECT_GE(corte, 1);
}
TEST(MinCutTest, ContraerMultiplesVecesHastaDosNodos) {
    MinCut<string> minCut;
    minCut.insertar("A", "B");
    minCut.insertar("B", "C");
    minCut.insertar("C", "D");
    minCut.insertar("D", "A");
    minCut.insertar("A", "C");

    while (true) {
        try {
            string V1, V2;
            if (minCut.getCiudades().size() <= 2) break;
            minCut.Contraer(V1, V2);
        } catch (...) {
            FAIL() << "Error en contracción múltiple";
        }
    }

    SUCCEED();
}