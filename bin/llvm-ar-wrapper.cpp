#include <stdio.h>
#include <string>

int main(int argc, char* argv[])
{
  std::string args;
  std::string files;
  for (int i = 0; i < argc; ++i)
  {
    printf("%d:%s\n", i, argv[i]);
    if (strstr(argv[i], "llvm-ar-wrapper"))
    {
      args += "/usr/local/opt/llvm/bin/llvm-ar";
      args += " ";
      args += "r";
      args += " ";
      continue;
    }
    if (strncmp(argv[i], "-D", 2) == 0)
    {
      continue;
    }
    if (strncmp(argv[i], "-L", 2) == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "-o") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "-static") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "-arch_only") == 0)
    {
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
    if (strcmp(argv[i], "mips") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "mips64") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "riscv32") == 0)
    {
      continue;
    }
    if (strcmp(argv[i], "riscv64") == 0)
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
          files += "\"";
          files += line;
          if (files.back() == '\n')
            files.pop_back();
          files += "\"";
          files += " ";
        }
        fclose(filelist);
      }

      continue;
    }
    args += argv[i];
    args += " ";
  }
  args += files;

  printf("%s\n", args.c_str());
  int status = system(args.c_str());
  return WEXITSTATUS(status);
}
