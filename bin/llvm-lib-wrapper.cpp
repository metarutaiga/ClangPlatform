#include <stdio.h>
#include <string>

int main(int argc, char* argv[])
{
  std::string args;
  for (int i = 0; i < argc; ++i)
  {
    printf("%d:%s\n", i, argv[i]);
    if (strstr(argv[i], "llvm-lib-wrapper"))
    {
      args += "/usr/local/opt/llvm/bin/llvm-lib";
      args += " ";
      continue;
    }
    if (strcmp(argv[i], "-o") == 0)
    {
      i++;

      args += "-out:";
      args += argv[i];
      args += " ";
      continue;
    }
    if (strcmp(argv[i], "-syslibroot") == 0)
    {
      i++;
      continue;
    }
    if (strcmp(argv[i], "armv7") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "arm64") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "i686") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "x86_64") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "-filelist") == 0)
    {
      i++;

      FILE* filelist = fopen(argv[i], "r");
      if (filelist)
      {
        char line[4096];
        while (fgets(line, 4096, filelist))
        {
	  args += "\"";
          args += line;
          if (args.back() == '\n')
            args.pop_back();
	  args += "\"";
          args += " ";
        }
        fclose(filelist);
      }

      continue;
    }
    args += argv[i];
    args += " ";
  }

  printf("%s\n", args.c_str());
  int status = system(args.c_str());
  return WEXITSTATUS(status);
}
