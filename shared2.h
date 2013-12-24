#ifndef SHARED_H2
#define SHARED_H2

#include <sys/stat.h>

static std::string getLogDir(){
	char dir_c_str[PATH_MAX];
	std::string dir_str;

  if ( readlink( "/proc/self/exe", dir_c_str, PATH_MAX ) )
  {
  	dir_str = std::string(dir_c_str);
  	// Truncate name of binary, move up a directory, and add logs folder.
		dir_str = dir_str.substr(0, dir_str.find_last_of("/", dir_str.find_last_of("/")-1)+1 ) + "Logs/";
		std::cout << dir_str << std::endl;
  }
  else
  {
  	// Otherwise, make logs fold in the directory the binary is run from.
  	dir_str = "./Logs";
  }

  // Create directory if it doesn't exist.
  // http://ubuntuforums.org/showthread.php?t=1004557
  struct stat sb;
  if (stat(dir_str.c_str(), &sb) != 0)
  {
    mkdir(dir_str.c_str(), S_IRWXU);
  }

  return dir_str;
}

const std::string log_dir = getLogDir();

// const int image_width = 1280;
// const int image_height = 720;
const int image_width = 1024;
const int image_height = 576;

#endif

