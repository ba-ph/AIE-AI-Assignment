#include "Application2D.h"
#include "Matrix2.h"

int main() {
	
	BaseApplication* app = new Application2D();
	if (app->startup())
		app->run();
	app->shutdown();

	return 0;
}