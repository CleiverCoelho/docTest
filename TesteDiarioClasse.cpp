#include "doctest.h"
#include "DiarioClasse.hpp"

TEST_CASE("Teste 05 - Reprovacao por Infrequencia") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(80, 0, 0.55);
    CHECK_FALSE(aprovado);
} 

TEST_CASE("Teste 06 - Excecao Nota Semestre") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(-100, 0, 0.8), ExcecaoNotaSemestreInvalida);
} 

TEST_CASE("Teste 07 - Excecao Nota Especial") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(50, 106, 0.80), ExcecaoNotaEspecialInvalida);
} 

TEST_CASE("Teste 08 - Excecao Nota Especial") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(45, -70, 0.70), ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 10 - Excecao Frequencia") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(100, 70, -1.5), ExcecaoFrequenciaInvalida);
} 

TEST_CASE("Teste 11 - Aprovacao Regular Exame Especial") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(50, 60, 0.75);
    CHECK(aprovado);
} 

TEST_CASE("Teste 12 - Excecao Nota Epspecial Nao candidato para Exame Especial Infrequencia") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(50, 50, 0.6), ExcecaoNotaEspecialInvalida);
} 

TEST_CASE("Teste 09 - Reprovacao/ Sem exame especial por Infrequencia") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(50, 0, 0.60);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 13 - Reprovacao Regular / sem exame especial por nota") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(30, 0, 0.85);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 14 - Aprovacao Regular / Sem exame especial") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(80, 0, 0.85);
    CHECK(aprovado);
}
