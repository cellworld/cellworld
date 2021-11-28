#include <random>
#include<catch.h>
#include<cell_world.h>
#include<sstream>

using namespace cell_world;
using namespace std;

TEST_CASE("polygon")
{
    Polygon p (Location (0,0), 4, 1 , 45);
    CHECK (p.to_json() == "{\"vertices\":[{\"x\":0.707107,\"y\":0.707107},{\"x\":0.707107,\"y\":-0.707107},{\"x\":-0.707107,\"y\":-0.707107},{\"x\":-0.707107,\"y\":0.707107}],\"center\":{\"x\":0,\"y\":0},\"radius\":1}" );
    CHECK( p.move(0,1).to_json() == "{\"vertices\":[{\"x\":0.707107,\"y\":1.70711},{\"x\":0.707107,\"y\":0.292893},{\"x\":-0.707107,\"y\":0.292893},{\"x\":-0.707107,\"y\":1.70711}],\"center\":{\"x\":0,\"y\":1},\"radius\":1}");
    CHECK (p.move({1,1}).to_json() == "{\"vertices\":[{\"x\":1.70711,\"y\":1.70711},{\"x\":1.70711,\"y\":0.292893},{\"x\":0.292893,\"y\":0.292893},{\"x\":0.292893,\"y\":1.70711}],\"center\":{\"x\":1,\"y\":1},\"radius\":1}");
    CHECK (p.to_json() == "{\"vertices\":[{\"x\":0.707107,\"y\":0.707107},{\"x\":0.707107,\"y\":-0.707107},{\"x\":-0.707107,\"y\":-0.707107},{\"x\":-0.707107,\"y\":0.707107}],\"center\":{\"x\":0,\"y\":0},\"radius\":1}" );
    CHECK ((p += Location{1,1}).to_json() == "{\"vertices\":[{\"x\":1.70711,\"y\":1.70711},{\"x\":1.70711,\"y\":0.292893},{\"x\":0.292893,\"y\":0.292893},{\"x\":0.292893,\"y\":1.70711}],\"center\":{\"x\":1,\"y\":1},\"radius\":1}");
    CHECK (p.to_json() == "{\"vertices\":[{\"x\":1.70711,\"y\":1.70711},{\"x\":1.70711,\"y\":0.292893},{\"x\":0.292893,\"y\":0.292893},{\"x\":0.292893,\"y\":1.70711}],\"center\":{\"x\":1,\"y\":1},\"radius\":1}");
    //cout << Polygon({0,0},6,1,0).vertices.get_x()  << "," << Polygon({0,0},6,1,0).vertices.get_y() << endl;
}

TEST_CASE("polygon_ contains")
{
    Polygon p (Location (0,0), 6, 1 , 30);
    for (int i=0; i<1000; i++) {
        auto r = ((double) rand() / (RAND_MAX)) + 1;
    }
}