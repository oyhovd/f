#include <iostream>
#include <algorithm>
#include "treeWalk.h"

static std::string * fragments;
static int fragmentsCount;
static bool dirsOnly = false;

int main(int argc, char * argv[])
{
  std::string helpString = "\
Usage:\n\
\n\
  f [/] fragment1 fragment2 fragment3 ...\n\
\n\
If / is given, then only directories are found.\n\
";

  if(argc < 2)
  {
    std::cout << helpString;
    return 0;
  }

  if((argv[1][0] == '/') && (argv[1][1] == '\0'))
  {
    dirsOnly = true;
  }

  fragments = new std::string[argc-1];
  fragmentsCount = argc-1;

  int subtract = 1;
  if(dirsOnly)
  {
    fragmentsCount--;
    subtract = 2;
  }

  for(int i = 0; i < fragmentsCount; i++)
  {
    fragments[i] = std::string(argv[i+subtract]);
  }


  treeWalk("", ".");

  //workaround for cygwin not waiting for all output being done
  std::cin.putback('\n');
  std::cin.get();

  return 0;
}

void findFragments(std::string fullPath)
{
  std::string searchPath = fullPath;
  for(int i = 0; i < fragmentsCount; i++)
  {
    size_t position;
    if((position = searchPath.find(fragments[i])) == std::string::npos)
    {
      return;
    }
    searchPath = std::string(searchPath.substr(position + fragments[i].length()));
  }
  std::cout << fullPath << "\n";
}

void treeWalkDirCb(std::string parent, std::string dirName)
{
  findFragments(parent + "/" + dirName);
}

void treeWalkFileCb(std::string parent, std::string fileName)
{
  if(!dirsOnly)
  {
    findFragments(parent + "/" + fileName);
  }
}


