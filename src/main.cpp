#include <iostream>
#include <algorithm>
#include "treeWalk.h"

int main(int argc, char * argv[])
{
  std::string helpString = "\
Usage:\n\
\n\
  f\n\
";

  if(argc < 2)
  {
    std::cout << helpString;
    return 0;
  }

  treeWalk("", ".");

  //workaround for cygwin not waiting for all output being done
  std::cin.putback('\n');
  std::cin.get();

  return 0;
}

void treeWalkDirCb(std::string parent, std::string dirName)
{
  //Nada, for debugging
  std::cout << dirName;
}

void treeWalkFileCb(std::string parent, std::string fileName)
{
  std::cout << fileName;
}


