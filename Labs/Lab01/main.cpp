
// TCLAP includes
#include <tclap/CmdLine.h>

//STD includes
#include <cstdlib>
#include <string>

int main(int argc, char *argv[]) {

  bool console = false;

  try {

    TCLAP::CmdLine cmd("Hello OpenGL");
    TCLAP::SwitchArg consoleSwitch("c", "console", "Console mode", false);
    cmd.add(consoleSwitch);
    cmd.parse(argc, argv);

    console = consoleSwitch.getValue();

  } catch (TCLAP::ArgException &e) {
    std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    return EXIT_FAILURE;
  }


  if(console)
  {
    std::cout << "Hello OpenGL: Console" << std::endl;
  }
  else
  {
    std::cout << "Hello OpenGL" << std::endl;
  }

  return EXIT_SUCCESS;
}
