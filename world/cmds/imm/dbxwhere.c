// cracked by vikee 2/09/2002   vikee@263.net
#include <globals.h>

int main()
{
  mapping error;
  int i;

  if (!(error = this_player()->query_temp("error"))) return 1;
  printf("%sProgram: %s\n", error["error"], error["program"]);
  for (i=0; i<sizeof(error["trace"]); i++) {
    printf("%i: %s in %s:%i\n", i, error["trace"][i]["function"], error["trace"][i]["program"], error["trace"][i]["line"]);
  }
  return 1;
}
