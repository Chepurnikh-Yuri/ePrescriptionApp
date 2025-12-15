#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WText.h>
#include <memory>

#include "welcome_page.hpp"
#include "login_page.hpp"
#include "register_page.hpp"

class EPrescriptionApp : public Wt::WApplication
{
public:	
	EPrescriptionApp(const Wt::WEnvironment& env) :
		Wt::WApplication(env) 
	{
		useStyleSheet("style.css");

		setTitle("ePrescriptionPlatform");

		root()->addWidget(std::make_unique<WelcomePage>());
	}
};

std::unique_ptr<Wt::WApplication> createApp(const Wt::WEnvironment& env)
{
	return std::make_unique<EPrescriptionApp>(env);
}

int main(int argc, char** argv)
{
	char* argv2[] = {
		argv[0], 
		(char*)"--docroot", (char*)".",
		(char*)"--http-address", (char*)"0.0.0.0",
		(char*)"--http-port", (char*)"8080",
	};
	int argc2 = 7;

	return Wt::WRun(argc2, argv2, &createApp);
}