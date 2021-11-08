#pragma once
#include <string>
#include <chrono>
#include <string>
#include <iostream>
using std::string;


//codigo de obtencao das colunas e linhas da janela #############
struct winsizestruct
{
	int Wcollumns, Wrows;
};

struct winsizestruct winsize();
//####################################################################
//codigo de renderizacao da janela
void renderwindow(int offsetup = 0, int offsetdown = 4, bool alt = false);
//################################
//codigo de receber as teclas pressionadas de modo assincrono :)
void asynckey();
//#############################################################