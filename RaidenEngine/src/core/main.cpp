#include "Application.h"

int main() {
	auto app = Raiden::createApplication();//have a implementation
	app->run();
	delete app;
	return 0;
}
