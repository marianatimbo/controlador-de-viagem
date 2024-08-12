#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/controladorDeTransito.hpp"


using namespace std;

void ControladorDeTransito::carregarCidades()
{
  ifstream arquivo("data/cidade.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      if(!linha.empty())
      {
        Cidade* novaCidade = new Cidade(linha);
        listaCidades.push_back(novaCidade);
      }
    }
  }
}

void ControladorDeTransito::carregarTransportes()
{
  ifstream arquivo("data/transporte.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
        istringstream xx(linha);
        string nome, localAtualS;
        int tipo, capacidade, distanciaDescansos, tempoDescanso;
        float velocidade;
        Cidade* localAtual = nullptr;

        getline(xx, nome, ',');
        xx >> tipo;
        xx.ignore();
        xx >> capacidade;
        xx.ignore();
        xx >> velocidade;
        xx.ignore();
        xx >> distanciaDescansos;
        xx.ignore();
        xx >> tempoDescanso;
        xx.ignore();
        getline(xx, localAtualS);
        localAtual = new Cidade(localAtualS);
        
        Transporte* trajetoArquivo = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, localAtual);

        listaTransportes.push_back(trajetoArquivo);
    }
  }
}

void ControladorDeTransito::carregarPassageiro()
{
}

void ControladorDeTransito::carregarViagens()
{
}
