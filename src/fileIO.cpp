#include <cstdio>
#include <cerrno>

int main()
{
  int buf_size = 4;
  char buff[buf_size] = {0};

  fputs("Prompt: ", stdout);
  fflush(stdout);
  fgets(buff, buf_size, stdin);
  fputs(buff, stdout);

  for(int idx = 0; idx < buf_size; ++idx)
  {
    fprintf(stdout,"%d ", buff[idx]);
  }
  puts("");
  printf("%d\n", errno);
  remove("a.out");
  printf("%d\n", errno);
  perror("The error is: ");
  return 0;
}