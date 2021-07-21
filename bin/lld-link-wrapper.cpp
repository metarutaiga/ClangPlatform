#include <stdio.h>
#include <string>

int main(int argc, char* argv[])
{
  std::string args;
  for (int i = 0; i < argc; ++i)
  {
    printf("%d:%s\n", i, argv[i]);
    if (strstr(argv[i], "lld-link-wrapper"))
    {
      args += "/usr/local/opt/llvm/bin/lld-link";
      args += " ";
      continue;
    }
    if (strcmp(argv[i], "-dead_strip") == 0)
    {
      args += "-opt:ref,icf";
      args += " ";
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
    if (argv[i][0] != '-' && strstr(argv[i], ".dll"))
    {
      char* tail = strstr(argv[i], ".dll");
      args += std::string(argv[i], tail);
      args += ".lib";
      args += " ";
      continue;
    }
    if (argv[i][0] == '-' && strstr(argv[i], ".dll"))
    {
      args += "\"";
      args += argv[i];
      args += "\"";
      args += " ";
      args += "-dll";
      args += " ";
      continue;
    }
    args += argv[i];
    args += " ";
  }

  printf("%s\n", args.c_str());
  int status = system(args.c_str());
  return WEXITSTATUS(status);
}
