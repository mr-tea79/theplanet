#include "Thread"
#include "Scene1.h"

using namespace std;
using namespace brightland;


int main(int argc, char* argv[])
{
    printf("Starting Game Main Thread");
    Scene1 *s = new Scene1();
    std::thread tw1 = s->scene1();
    tw1.join();
    return 0;

}