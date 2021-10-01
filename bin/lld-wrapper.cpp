#include <stdio.h>
#include <string>

int main(int argc, char* argv[])
{
  std::string args;
  for (int i = 0; i < argc; ++i)
  {
    printf("%d:%s\n", i, argv[i]);
    if (strstr(argv[i], "lld-wrapper"))
    {
      args += "/usr/local/opt/llvm/bin/ld.lld";
      args += " ";
      continue;
    }
    if (strcmp(argv[i], "-o") == 0)
    {
      i++;

      args += " ";
      args += "-o";
      args += " ";

      args += "\"";
      args += argv[i];
      args += "\"";
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
    if (strstr(argv[i], "-no_deduplicate"))
    {
      continue;
    }
    if (strstr(argv[i], "-no_adhoc_codesign"))
    {
      continue;
    }
    if (strstr(argv[i], "-lgcc"))
    {
      continue;
    }
    args += argv[i];
    args += " ";
  }

  printf("%s\n", args.c_str());
  int status = system(args.c_str());
  return WEXITSTATUS(status);
}
