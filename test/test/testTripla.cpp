#include "pch.h"
#include "../../ProyectoFinal/Tripla.h"

TEST(TriplaTest, SetAndGetElem) {
    Tripla<int> t;
    t.setElem(42);
    EXPECT_EQ(t.getElem(), 42);
}