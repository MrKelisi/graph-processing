#include <catch.hpp>
#include <modeling/vertexdata.h>
#include <graph/graphe.h>
#include <modeling/edgedata.h>
#include <file/gprparser.h>
#include <algorithm/pcc.h>
#include <fstream>


TEST_CASE("testPCCParser") {

    std::cout << std::endl << "=== testPCCParser" << std::endl;

    std::ifstream fstream("data/data_VRPTW_10.gpr");
    GPRParser gprp(fstream);
    gprp.load();

    PCC *pcc = new PCC(&gprp.graphe(), gprp.source(), cout);
    pcc->search();
    pcc->pluscourtchemin(gprp.puits());

    REQUIRE(pcc->explored(gprp.puits()));
}