#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "OperationsExpert.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

typedef unsigned int uint;

Board* board;
Dispatcher* dispatcher;
FieldDoctor* field_doctor;
GeneSplicer* gene_splicer;
Medic* medic;
OperationsExpert* operations_expert;
Researcher* researcher;
Scientist* scientist;
Virologist* virologist;

void init(City city = Algiers)
{
    board = new Board();
    dispatcher = new Dispatcher(*board, City::Algiers);
    field_doctor = new FieldDoctor(*board, City::Algiers);
    gene_splicer = new GeneSplicer(*board, City::Algiers);
    medic = new Medic(*board, City::Algiers);
    operations_expert = new OperationsExpert(*board, City::Algiers);
    researcher = new Researcher(*board, City::Algiers);
    scientist = new Scientist(*board, City::Algiers, 4);
    virologist = new Virologist(*board, City::Algiers);
}

void delete_init()
{
    delete board;
    delete dispatcher;
    delete field_doctor;
    delete gene_splicer;
    delete medic;
    delete operations_expert;
    delete researcher;
    delete scientist;
    delete virologist;
}

void take_cards(Player& player, uint num_of_cards)
{
    for(size_t i = 0; i < num_of_cards; i++)
    {
        player.take_card((City)i);
    }
}
TEST_CASE("init board")
{
    init();

    for (size_t i = 0; i < 48; i++)
    {
        CHECK((*board)[(City)i] == 0);
    }

    delete_init();
}
TEST_CASE("drive throw error")
{
    init();

    CHECK_THROWS(operations_expert->drive(Chicago));
    CHECK_THROWS(dispatcher->drive(Chicago));
    CHECK_THROWS(scientist->drive(Chicago));
    CHECK_THROWS(researcher->drive(Chicago));
    CHECK_THROWS(medic->drive(Chicago));
    CHECK_THROWS(virologist->drive(Chicago));
    CHECK_THROWS(gene_splicer->drive(Chicago));
    CHECK_THROWS(field_doctor->drive(Chicago));

    CHECK_THROWS(operations_expert->drive(HongKong));
    CHECK_THROWS(dispatcher->drive(HongKong));
    CHECK_THROWS(scientist->drive(HongKong));
    CHECK_THROWS(researcher->drive(HongKong));
    CHECK_THROWS(medic->drive(HongKong));
    CHECK_THROWS(virologist->drive(HongKong));
    CHECK_THROWS(gene_splicer->drive(HongKong));
    CHECK_THROWS(field_doctor->drive(HongKong));

    CHECK_THROWS(operations_expert->drive(NewYork));
    CHECK_THROWS(dispatcher->drive(NewYork));
    CHECK_THROWS(scientist->drive(NewYork));
    CHECK_THROWS(researcher->drive(NewYork));
    CHECK_THROWS(medic->drive(NewYork));
    CHECK_THROWS(virologist->drive(NewYork));
    CHECK_THROWS(gene_splicer->drive(NewYork));
    CHECK_THROWS(field_doctor->drive(NewYork));

    delete_init();
}
TEST_CASE("drive that doesn't throw error")
{
    init();


    CHECK_NOTHROW(operations_expert->drive(Paris));
    CHECK_NOTHROW(dispatcher->drive(Paris));
    CHECK_NOTHROW(scientist->drive(Paris));
    CHECK_NOTHROW(researcher->drive(Paris));
    CHECK_NOTHROW(medic->drive(Paris));
    CHECK_NOTHROW(virologist->drive(Paris));
    CHECK_NOTHROW(gene_splicer->drive(Paris));
    CHECK_NOTHROW(field_doctor->drive(Paris));

    delete_init();
}
TEST_CASE("fly direct throw error")
{
    init();
    
    CHECK_THROWS(operations_expert->fly_direct(Chicago));
    CHECK_THROWS(dispatcher->fly_direct(Chicago));
    CHECK_THROWS(scientist->fly_direct(Chicago));
    CHECK_THROWS(researcher->fly_direct(Chicago));
    CHECK_THROWS(medic->fly_direct(Chicago));
    CHECK_THROWS(virologist->fly_direct(Chicago));
    CHECK_THROWS(gene_splicer->fly_direct(Chicago));
    CHECK_THROWS(field_doctor->fly_direct(Chicago));

    CHECK_THROWS(operations_expert->fly_direct(HongKong));
    CHECK_THROWS(dispatcher->fly_direct(HongKong));
    CHECK_THROWS(scientist->fly_direct(HongKong));
    CHECK_THROWS(researcher->fly_direct(HongKong));
    CHECK_THROWS(medic->fly_direct(HongKong));
    CHECK_THROWS(virologist->fly_direct(HongKong));
    CHECK_THROWS(gene_splicer->fly_direct(HongKong));
    CHECK_THROWS(field_doctor->fly_direct(HongKong));

    CHECK_THROWS(operations_expert->fly_direct(NewYork));
    CHECK_THROWS(dispatcher->fly_direct(NewYork));
    CHECK_THROWS(scientist->fly_direct(NewYork));
    CHECK_THROWS(researcher->fly_direct(NewYork));
    CHECK_THROWS(medic->fly_direct(NewYork));
    CHECK_THROWS(virologist->fly_direct(NewYork));
    CHECK_THROWS(gene_splicer->fly_direct(NewYork));
    CHECK_THROWS(field_doctor->fly_direct(NewYork));

    delete_init();
}
TEST_CASE("fly direct that doesn't throw error")
{
    init(Miami);
    
    operations_expert->take_card(Miami);
    CHECK_NOTHROW(operations_expert->fly_direct(Miami));
    dispatcher->take_card(Shanghai);
    CHECK_NOTHROW(dispatcher->fly_direct(Shanghai));
    scientist->take_card(StPetersburg);
    CHECK_NOTHROW(scientist->fly_direct(StPetersburg));
    researcher->take_card(Sydney);
    CHECK_NOTHROW(researcher->fly_direct(Sydney));
    medic->take_card(Taipei);
    CHECK_NOTHROW(medic->fly_direct(Taipei));virologist->take_card(Tehran);
    CHECK_NOTHROW(virologist->fly_direct(Tehran));
    gene_splicer->take_card(Tokyo);
    CHECK_NOTHROW(gene_splicer->fly_direct(Tokyo));
    field_doctor->take_card(Washington);
    CHECK_NOTHROW(field_doctor->fly_direct(Washington));

    delete_init();
}
TEST_CASE("fly charter throw error")
{
    init();
    
    CHECK_THROWS(operations_expert->fly_direct(Chicago));
    CHECK_THROWS(dispatcher->fly_direct(Chicago));
    CHECK_THROWS(scientist->fly_direct(Chicago));
    CHECK_THROWS(researcher->fly_direct(Chicago));
    CHECK_THROWS(medic->fly_direct(Chicago));
    CHECK_THROWS(virologist->fly_direct(Chicago));
    CHECK_THROWS(gene_splicer->fly_direct(Chicago));
    CHECK_THROWS(field_doctor->fly_direct(Chicago));

    CHECK_THROWS(operations_expert->fly_direct(HongKong));
    CHECK_THROWS(dispatcher->fly_direct(HongKong));
    CHECK_THROWS(scientist->fly_direct(HongKong));
    CHECK_THROWS(researcher->fly_direct(HongKong));
    CHECK_THROWS(medic->fly_direct(HongKong));
    CHECK_THROWS(virologist->fly_direct(HongKong));
    CHECK_THROWS(gene_splicer->fly_direct(HongKong));
    CHECK_THROWS(field_doctor->fly_direct(HongKong));

    CHECK_THROWS(operations_expert->fly_direct(NewYork));
    CHECK_THROWS(dispatcher->fly_direct(NewYork));
    CHECK_THROWS(scientist->fly_direct(NewYork));
    CHECK_THROWS(researcher->fly_direct(NewYork));
    CHECK_THROWS(medic->fly_direct(NewYork));
    CHECK_THROWS(virologist->fly_direct(NewYork));
    CHECK_THROWS(gene_splicer->fly_direct(NewYork));
    CHECK_THROWS(field_doctor->fly_direct(NewYork));

    delete_init();
}
TEST_CASE("fly charter that doesn't throw error")
{
    init();
    
    operations_expert->take_card(Miami);
    CHECK_NOTHROW(operations_expert->fly_charter(Seoul));
    dispatcher->take_card(Miami);
    CHECK_NOTHROW(dispatcher->fly_charter(Shanghai));
    scientist->take_card(Miami);
    CHECK_NOTHROW(scientist->fly_charter(StPetersburg));
    researcher->take_card(Miami);
    CHECK_NOTHROW(researcher->fly_charter(Sydney));
    medic->take_card(Miami);
    CHECK_NOTHROW(medic->fly_charter(Taipei));
    virologist->take_card(Miami);
    CHECK_NOTHROW(virologist->fly_charter(Tehran));
    gene_splicer->take_card(Miami);
    CHECK_NOTHROW(gene_splicer->fly_charter(Tokyo));
    field_doctor->take_card(Miami);
    CHECK_NOTHROW(field_doctor->fly_charter(Washington));

    delete_init();
}
TEST_CASE("fly shuttler throw error")
{
    init();
    
    CHECK_THROWS(operations_expert->fly_direct(Chicago));
    CHECK_THROWS(dispatcher->fly_direct(Chicago));
    CHECK_THROWS(scientist->fly_direct(Chicago));
    CHECK_THROWS(researcher->fly_direct(Chicago));
    CHECK_THROWS(medic->fly_direct(Chicago));
    CHECK_THROWS(virologist->fly_direct(Chicago));
    CHECK_THROWS(gene_splicer->fly_direct(Chicago));
    CHECK_THROWS(field_doctor->fly_direct(Chicago));

    CHECK_THROWS(operations_expert->fly_direct(HongKong));
    CHECK_THROWS(dispatcher->fly_direct(HongKong));
    CHECK_THROWS(scientist->fly_direct(HongKong));
    CHECK_THROWS(researcher->fly_direct(HongKong));
    CHECK_THROWS(medic->fly_direct(HongKong));
    CHECK_THROWS(virologist->fly_direct(HongKong));
    CHECK_THROWS(gene_splicer->fly_direct(HongKong));
    CHECK_THROWS(field_doctor->fly_direct(HongKong));

    CHECK_THROWS(operations_expert->fly_direct(NewYork));
    CHECK_THROWS(dispatcher->fly_direct(NewYork));
    CHECK_THROWS(scientist->fly_direct(NewYork));
    CHECK_THROWS(researcher->fly_direct(NewYork));
    CHECK_THROWS(medic->fly_direct(NewYork));
    CHECK_THROWS(virologist->fly_direct(NewYork));
    CHECK_THROWS(gene_splicer->fly_direct(NewYork));
    CHECK_THROWS(field_doctor->fly_direct(NewYork));

    delete_init();
}
TEST_CASE("fly shuttle that doesn't throw error")
{
    init();
    
    operations_expert->take_card(Miami);
    CHECK_NOTHROW(operations_expert->fly_charter(Seoul));
    dispatcher->take_card(Miami);
    CHECK_NOTHROW(dispatcher->fly_charter(Shanghai));
    scientist->take_card(Miami);
    CHECK_NOTHROW(scientist->fly_charter(StPetersburg));
    researcher->take_card(Miami);
    CHECK_NOTHROW(researcher->fly_charter(Sydney));
    medic->take_card(Miami);
    CHECK_NOTHROW(medic->fly_charter(Taipei));
    virologist->take_card(Miami);
    CHECK_NOTHROW(virologist->fly_charter(Tehran));
    gene_splicer->take_card(Miami);
    CHECK_NOTHROW(gene_splicer->fly_charter(Tokyo));
    field_doctor->take_card(Miami);
    CHECK_NOTHROW(field_doctor->fly_charter(Washington));

    delete_init();
}