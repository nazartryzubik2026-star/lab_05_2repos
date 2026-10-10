// Unit test for Lab 5.2
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.2/Source.cpp" // Переконайтеся, що назва папки відповідає вашій (наприклад, Lab_5_2 чи Project5_2)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
    TEST_CLASS(UnitTest52)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double x = 2.0;
            double eps = 0.00001;
            int n = 0;
            double s = 0.0;

            // Виклик функції обчислення суми ряду Тейлора
            S(x, eps, n, s);

            // Очікуване значення точного логарифма ln(2) ≈ 0.693147
            double expected = log(x);

            // Перевірка відповідності суми ряду та точного значення з точністю 0.0001
            Assert::AreEqual(expected, s, 0.0001);
        }
    };
}