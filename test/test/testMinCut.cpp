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
