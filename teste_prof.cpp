#include "GabrielFigueiredoVieira.hpp" // implementações do professor.. faça seu próprio arquivo .hpp!

#define CATCH_CONFIG_MAIN // catch2 main()
#include "catch.hpp"

// ===================
// testes para exemplo
// -------------------

TEST_CASE("exemplo n=3 3 2 5")
{
  // 3 + 2 + 5 = 10
  REQUIRE(exemplo("\t3     3    2 \n\t 5") == 10);
}

// =======================
// testes para exercício 0
// -----------------------

TEST_CASE("ex0 - caso 0")
{
  REQUIRE(exercicio0("") == 0);
}

// =======================
// testes para exercício 1
// -----------------------

TEST_CASE("ex1 a=1 b=3")
{
  REQUIRE(exercicio1("1 3") == 6);
}

TEST_CASE("ex1 a=1 b=10")
{
  REQUIRE(exercicio1("1 10") == 55);
}

// =======================
// testes para exercício 2
// -----------------------

TEST_CASE("ex2 n=4 1 1 2 3")
{
  REQUIRE(exercicio2("4 1 1 2 3") == 1);
}

TEST_CASE("ex2 n=12 1 1 2 3 3 3 3 0 1 1 1 3")
{
  REQUIRE(exercicio2("12 1 1 2 3 3 3 3 0 1 1 1 3") == 0);
}

TEST_CASE("ex2 n=6 1 2 2 3 2 0")
{
  REQUIRE(exercicio2("6 1 2 2 3 2 0") == 2);
}

// =======================
// testes para exercício 3
// -----------------------

TEST_CASE("ex3 n=4 5.0 10.0 1.5 3.5")
{
  REQUIRE(exercicio3("4 5.0 10.0 1.5 3.5") == std::make_tuple(20.0, 5.0, 10.0, 1.5));
}

TEST_CASE("ex3 n=7 4.1 3.7 2.5 3.0 2.9 2.1 15.3")
{
  REQUIRE(exercicio3("7 4.1 3.7 2.5 3.0 2.9 2.1 15.3") == std::make_tuple(33.6, 4.8, 15.3, 2.1));
}

// =======================
// testes para exercício 4
// -----------------------

TEST_CASE("ex4 n=6 8.0 Carla 9.0 Marcos 1.0 José 9.9 Rita 5.0 Luiz 7.0 Maria 2")
{
  REQUIRE(exercicio4("6 8.0 Carla 9.0 Marcos 1.0 José 9.9 Rita 5.0 Luiz 7.0 Maria 2") == 1);
}

TEST_CASE("ex4 n=6 8.0 Carla 9.0 Marcos 1.0 José 9.9 Rita 5.0 Luiz 7.0 Maria 6")
{
  REQUIRE(exercicio4("6 8.0 Carla 9.0 Marcos 1.0 José 9.9 Rita 5.0 Luiz 7.0 Maria 6") == 1);
}

TEST_CASE("ex4 n=6 8.0 Carla 9.0 Marcos 1.0 José 9.9 Rita 5.0 Luiz 7.0 Maria 3")
{
  REQUIRE(exercicio4("6 8.0 Carla 9.0 Marcos 1.0 José 9.9 Rita 5.0 Luiz 7.0 Maria 3") == 0);
}

// =======================
// testes para exercício 5
// -----------------------

TEST_CASE("ex5 4")
{
  REQUIRE(exercicio5("4") == 24);
}

TEST_CASE("ex5 5")
{
  REQUIRE(exercicio5("5") == 120);
}

TEST_CASE("ex5 1")
{
  REQUIRE(exercicio5("1") == 1);
}

// =======================
// testes para exercício 6
// -----------------------

TEST_CASE("ex6 4")
{
  REQUIRE(exercicio6("4") == 3);
}

TEST_CASE("ex6 7")
{
  REQUIRE(exercicio6("7") == 13);
}

TEST_CASE("ex6 2")
{
  REQUIRE(exercicio6("2") == 1);
}

// =======================
// testes para exercício 7
// -----------------------

TEST_CASE("ex7 n=3 t p d p d t")
{
  REQUIRE(exercicio7("3 t p d p d t") == 'M');
}

TEST_CASE("ex7 n=4 t p d p d t p t")
{
  REQUIRE(exercicio7("4 t p d p d t p t") == 'X');
}

TEST_CASE("ex7 n=5 t p d p d t p t t d")
{
  REQUIRE(exercicio7("5 t p d p d t p t t d") == 'J');
}

// =======================
// testes para exercício 8
// -----------------------

TEST_CASE("ex8 10 20")
{
  REQUIRE(exercicio8("10 20") == std::make_tuple(20, 10));
}

TEST_CASE("ex8 2 7")
{
  REQUIRE(exercicio8("2 7") == std::make_tuple(7, 2));
}

TEST_CASE("ex8 73 28")
{
  REQUIRE(exercicio8("73 28") == std::make_tuple(28, 73));
}

// =======================
// testes para exercício 9
// -----------------------

TEST_CASE("ex9 n=5 8 3 6 1 4")
{
  REQUIRE(exercicio9("5 8 3 6 1 4") == 4.0);
}

TEST_CASE("ex9 n=8 1 4 4 5 6 7 7 7")
{
  REQUIRE(exercicio9("8 1 4 4 5 6 7 7 7") == (float)5.5);
}

TEST_CASE("ex9 n=4 1 3 5 0")
{
  REQUIRE(exercicio9("4 1 3 5 2") == (float)2.5);
}

// testado com Catch v2.13.1
// mais testes virão aqui no futuro...