#include "pch.h"
#include "../../ProyectoFinal/Lista8.h"

using namespace std;

TEST(Lista8Test, InsertarPrincipio_ListaVacia) {
    Lista8<int> lista;
    lista.insertar_Principio(10, 100);
    Tripla<int>* primer = lista.getPrimer();
    ASSERT_NE(primer, nullptr);
    EXPECT_EQ(primer->getElem(), 10);
    EXPECT_EQ(primer->getLista()[0], 100);
}

TEST(Lista8Test, InsertarPrincipio_ListaNoVacia) {
    Lista8<int> lista;
    lista.insertar_Principio(20, 200);
    lista.insertar_Principio(10, 100);
    Tripla<int>* primer = lista.getPrimer();
    ASSERT_NE(primer, nullptr);
    EXPECT_EQ(primer->getElem(), 10);
    EXPECT_EQ(primer->getSig()->getElem(), 20);
    EXPECT_EQ(primer->getLista()[0], 100);
}

TEST(Lista8Test, InsertarFinal_ListaVacia) {
    Lista8<int> lista;
    lista.insertar_Final(30, 300);
    Tripla<int>* primer = lista.getPrimer();
    ASSERT_NE(primer, nullptr);
    EXPECT_EQ(primer->getElem(), 30);
    EXPECT_EQ(primer->getLista()[0], 300);
}

TEST(Lista8Test, InsertarFinal_ListaNoVacia) {
    Lista8<int> lista;
    lista.insertar_Final(30, 300);
    lista.insertar_Final(40, 400);
    Tripla<int>* primer = lista.getPrimer();
    ASSERT_NE(primer->getSig(), nullptr);
    EXPECT_EQ(primer->getSig()->getElem(), 40);
}

TEST(Lista8Test, MostrarLista) {
    Lista8<int> lista;
    lista.insertar_Final(1, 11);
    lista.insertar_Final(2, 22);
    testing::internal::CaptureStdout();
    lista.mostrar();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("1"), string::npos);
    EXPECT_NE(output.find("11"), string::npos);
    EXPECT_NE(output.find("2"), string::npos);
    EXPECT_NE(output.find("22"), string::npos);
}

TEST(Lista8Test, EliminarPrincipio_ListaUnElemento) {
    Lista8<int> lista;
    lista.insertar_Final(50, 500);
    lista.eliminar_Principio();
    EXPECT_EQ(lista.getPrimer(), nullptr);
}

TEST(Lista8Test, EliminarPrincipio_ListaConDos) {
    Lista8<int> lista;
    lista.insertar_Final(60, 600);
    lista.insertar_Final(70, 700);
    lista.eliminar_Principio();
    Tripla<int>* primer = lista.getPrimer();
    ASSERT_NE(primer, nullptr);
    EXPECT_EQ(primer->getElem(), 70);
}

TEST(Lista8Test, EliminarFinal_ListaUnElemento) {
    Lista8<int> lista;
    lista.insertar_Final(80, 800);
    lista.eliminar_Final();
    EXPECT_EQ(lista.getPrimer(), nullptr);
}

TEST(Lista8Test, EliminarFinal_ListaConDos) {
    Lista8<int> lista;
    lista.insertar_Final(90, 900);
    lista.insertar_Final(100, 1000);
    lista.eliminar_Final();
    Tripla<int>* primer = lista.getPrimer();
    ASSERT_NE(primer, nullptr);
    EXPECT_EQ(primer->getElem(), 90);
    EXPECT_EQ(primer->getSig(), nullptr);
}

TEST(Lista8Test, BuscarElementoExistente) {
    Lista8<int> lista;
    lista.insertar_Final(110, 1110);
    lista.insertar_Final(120, 1120);
    Tripla<int>* encontrado = lista.buscar_No_Recursivo(120);
    ASSERT_NE(encontrado, nullptr);
    EXPECT_EQ(encontrado->getElem(), 120);
}

TEST(Lista8Test, BuscarElementoNoExistente) {
    Lista8<int> lista;
    lista.insertar_Final(130, 1130);
    Tripla<int>* encontrado = lista.buscar_No_Recursivo(999);
    EXPECT_EQ(encontrado, nullptr);
}

TEST(Lista8Test, EliminarElementoDado_AlInicio) {
    Lista8<int> lista;
    lista.insertar_Final(200, 2000);
    bool eliminado = lista.eliminar_elem_dado(200);
    EXPECT_TRUE(eliminado);
    EXPECT_EQ(lista.getPrimer(), nullptr);
}

TEST(Lista8Test, EliminarElementoDado_AlFinal) {
    Lista8<int> lista;
    lista.insertar_Final(210, 2100);
    lista.insertar_Final(220, 2200);
    bool eliminado = lista.eliminar_elem_dado(220);
    EXPECT_TRUE(eliminado);
    EXPECT_EQ(lista.getPrimer()->getElem(), 210);
    EXPECT_EQ(lista.getPrimer()->getSig(), nullptr);
}

TEST(Lista8Test, EliminarElementoDado_Intermedio) {
    Lista8<int> lista;
    lista.insertar_Final(300, 3000);
    lista.insertar_Final(310, 3100);
    lista.insertar_Final(320, 3200);
    bool eliminado = lista.eliminar_elem_dado(310);
    EXPECT_TRUE(eliminado);
    Tripla<int>* primero = lista.getPrimer();
    EXPECT_EQ(primero->getSig()->getElem(), 320);
    EXPECT_EQ(primero->getSig()->getAnt(), primero);
}

TEST(Lista8Test, EliminarElementoDado_NoExistente) {
    Lista8<int> lista;
    lista.insertar_Final(400, 4000);
    bool eliminado = lista.eliminar_elem_dado(999);
    EXPECT_FALSE(eliminado);
    EXPECT_NE(lista.getPrimer(), nullptr);
}

