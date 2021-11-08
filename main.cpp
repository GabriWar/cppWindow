#include "source.h"
#include <iostream>
#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
using std::thread;



int main()
{
	//############## loop de detectar teclas assincrono
	thread asynckeyth(asynckey);
	//##################################################
	//################# codigo de renderizacao da janela
	renderwindow();
	//##################################################
	//############## fechando o loop pra nn crashar nada
	asynckeyth.join();
	//##################################################
	std::cin;
	return 0;
}
