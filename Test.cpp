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

//first test cases for before we make the functions' tests
TEST_CASE("init board")
{
    init();

    for (size_t i = 0; i < 48; i++)
    {
        CHECK((*board)[(City)i] == 0);
    }

    delete_init();
}
TEST_CASE("role")
{
    init();

    CHECK(operations_expert->role() == "OperationsExpert");
    CHECK(dispatcher->role() == "Dispatcher");
    CHECK(scientist->role() == "Scientist");
    CHECK(researcher->role() == "Researcher");
    CHECK(medic->role() == "Medic");
    CHECK(virologist->role() == "Virologist");
    CHECK(gene_splicer->role() == "GeneSplicer");
    CHECK(field_doctor->role() == "FieldDoctor");

    delete_init();
}
//function tests
TEST_CASE("drive throw error")
{
    init();
    // drive to non close city throw
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

    // drive to the same city throw
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


    CHECK_NOTHROW(operations_expert->drive(Algiers));
    CHECK_NOTHROW(dispatcher->drive(Algiers));
    CHECK_NOTHROW(scientist->drive(Algiers));
    CHECK_NOTHROW(researcher->drive(Algiers));
    CHECK_NOTHROW(medic->drive(Algiers));
    CHECK_NOTHROW(virologist->drive(Algiers));
    CHECK_NOTHROW(gene_splicer->drive(Algiers));
    CHECK_NOTHROW(field_doctor->drive(Algiers));

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

    // fly direct to the same city throw
    CHECK_THROWS(operations_expert->fly_direct(Algiers));
    CHECK_THROWS(dispatcher->fly_direct(Algiers));
    CHECK_THROWS(scientist->fly_direct(Algiers));
    CHECK_THROWS(researcher->fly_direct(Algiers));
    CHECK_THROWS(medic->fly_direct(Algiers));
    CHECK_THROWS(virologist->fly_direct(Algiers));
    CHECK_THROWS(gene_splicer->fly_direct(Algiers));
    CHECK_THROWS(field_doctor->fly_direct(Algiers));

    delete_init();
}
TEST_CASE("fly direct that doesn't throw error")
{
    init(Miami);
    
    operations_expert->take_card(Istanbul);
    CHECK_NOTHROW(operations_expert->fly_direct(Istanbul));
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

    dispatcher->take_card(Miami);
    dispatcher->build();
    CHECK_NOTHROW(dispatcher->fly_direct(Shanghai));
    

    delete_init();
}
TEST_CASE("fly charter throw error")
{
    init();
    
    CHECK_THROWS(operations_expert->fly_charter(Chicago));
    CHECK_THROWS(dispatcher->fly_charter(Chicago));
    CHECK_THROWS(scientist->fly_charter(Chicago));
    CHECK_THROWS(researcher->fly_charter(Chicago));
    CHECK_THROWS(medic->fly_charter(Chicago));
    CHECK_THROWS(virologist->fly_charter(Chicago));
    CHECK_THROWS(gene_splicer->fly_charter(Chicago));
    CHECK_THROWS(field_doctor->fly_charter(Chicago));

    CHECK_THROWS(operations_expert->fly_charter(HongKong));
    CHECK_THROWS(dispatcher->fly_charter(HongKong));
    CHECK_THROWS(scientist->fly_charter(HongKong));
    CHECK_THROWS(researcher->fly_charter(HongKong));
    CHECK_THROWS(medic->fly_charter(HongKong));
    CHECK_THROWS(virologist->fly_charter(HongKong));
    CHECK_THROWS(gene_splicer->fly_charter(HongKong));
    CHECK_THROWS(field_doctor->fly_charter(HongKong));

    CHECK_THROWS(operations_expert->fly_charter(NewYork));
    CHECK_THROWS(dispatcher->fly_charter(NewYork));
    CHECK_THROWS(scientist->fly_charter(NewYork));
    CHECK_THROWS(researcher->fly_charter(NewYork));
    CHECK_THROWS(medic->fly_charter(NewYork));
    CHECK_THROWS(virologist->fly_charter(NewYork));
    CHECK_THROWS(gene_splicer->fly_charter(NewYork));
    CHECK_THROWS(field_doctor->fly_charter(NewYork));

    // fly direct to the same city throw
    CHECK_THROWS(operations_expert->fly_charter(Algiers));
    CHECK_THROWS(dispatcher->fly_charter(Algiers));
    CHECK_THROWS(scientist->fly_charter(Algiers));
    CHECK_THROWS(researcher->fly_charter(Algiers));
    CHECK_THROWS(medic->fly_charter(Algiers));
    CHECK_THROWS(virologist->fly_charter(Algiers));
    CHECK_THROWS(gene_splicer->fly_charter(Algiers));
    CHECK_THROWS(field_doctor->fly_charter(Algiers));

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
//operation expert doesn't need the correct card
TEST_CASE("build throw error")
{
    init();

    CHECK_THROWS(dispatcher->build());
    CHECK_THROWS(scientist->build());
    CHECK_THROWS(researcher->build());
    CHECK_THROWS(medic->build());
    CHECK_THROWS(virologist->build());
    CHECK_THROWS(gene_splicer->build());
    CHECK_THROWS(field_doctor->build());

    delete_init();
}
TEST_CASE("build that doesn't throw error")
{
    init(Tokyo);
    
    operations_expert->take_card(Moscow);
    CHECK_NOTHROW(operations_expert->build());
    dispatcher->take_card(Tokyo);
    CHECK_NOTHROW(dispatcher->build());
    scientist->take_card(Tokyo);
    CHECK_NOTHROW(scientist->build());
    researcher->take_card(Tokyo);
    CHECK_NOTHROW(researcher->build());
    medic->take_card(Tokyo);
    CHECK_NOTHROW(medic->build());
    virologist->take_card(Tokyo);
    CHECK_NOTHROW(virologist->build());
    gene_splicer->take_card(Tokyo);
    CHECK_NOTHROW(gene_splicer->build());
    field_doctor->take_card(Tokyo);
    CHECK_NOTHROW(field_doctor->build());

    delete_init();
}
TEST_CASE("fly shuttler throw error")
{
    init();

    CHECK_THROWS(operations_expert->fly_shuttle(Paris));
    CHECK_THROWS(dispatcher->fly_shuttle(Paris));
    CHECK_THROWS(scientist->fly_shuttle(Paris));
    CHECK_THROWS(researcher->fly_shuttle(Paris));
    CHECK_THROWS(medic->fly_shuttle(Paris));
    CHECK_THROWS(virologist->fly_shuttle(Paris));
    CHECK_THROWS(gene_splicer->fly_shuttle(Paris));
    CHECK_THROWS(field_doctor->fly_shuttle(Paris));

    CHECK_THROWS(operations_expert->fly_shuttle(Madrid));
    CHECK_THROWS(dispatcher->fly_shuttle(Madrid));
    CHECK_THROWS(scientist->fly_shuttle(Madrid));
    CHECK_THROWS(researcher->fly_shuttle(Madrid));
    CHECK_THROWS(medic->fly_shuttle(Madrid));
    CHECK_THROWS(virologist->fly_shuttle(Madrid));
    CHECK_THROWS(gene_splicer->fly_shuttle(Madrid));
    CHECK_THROWS(field_doctor->fly_shuttle(Madrid));

    CHECK_THROWS(operations_expert->fly_shuttle(Istanbul));
    CHECK_THROWS(dispatcher->fly_shuttle(Istanbul));
    CHECK_THROWS(scientist->fly_shuttle(Istanbul));
    CHECK_THROWS(researcher->fly_shuttle(Istanbul));
    CHECK_THROWS(medic->fly_shuttle(Istanbul));
    CHECK_THROWS(virologist->fly_shuttle(Istanbul));
    CHECK_THROWS(gene_splicer->fly_shuttle(Istanbul));
    CHECK_THROWS(field_doctor->fly_shuttle(Istanbul));

    //fly to the same city
    CHECK_THROWS(operations_expert->fly_shuttle(Algiers));
    CHECK_THROWS(dispatcher->fly_shuttle(Algiers));
    CHECK_THROWS(scientist->fly_shuttle(Algiers));
    CHECK_THROWS(researcher->fly_shuttle(Algiers));
    CHECK_THROWS(medic->fly_shuttle(Algiers));
    CHECK_THROWS(virologist->fly_shuttle(Algiers));
    CHECK_THROWS(gene_splicer->fly_shuttle(Algiers));
    CHECK_THROWS(field_doctor->fly_shuttle(Algiers));

    //fly to the same city even if we have a research station
    operations_expert->take_card(Moscow);
    operations_expert->build();
    CHECK_THROWS(operations_expert->fly_shuttle(Algiers));
    CHECK_THROWS(dispatcher->fly_shuttle(Algiers));
    CHECK_THROWS(scientist->fly_shuttle(Algiers));
    CHECK_THROWS(researcher->fly_shuttle(Algiers));
    CHECK_THROWS(medic->fly_shuttle(Algiers));
    CHECK_THROWS(virologist->fly_shuttle(Algiers));
    CHECK_THROWS(gene_splicer->fly_shuttle(Algiers));
    CHECK_THROWS(field_doctor->fly_shuttle(Algiers));


    delete_init();
}
TEST_CASE("fly shuttle that doesn't throw error")
{
    init(Tokyo);
    
    operations_expert->take_card(Tokyo);
    operations_expert->build();
    operations_expert->drive(SanFrancisco);
    operations_expert->drive(LosAngeles);
    operations_expert->take_card(LosAngeles);
    operations_expert->build();
    CHECK_NOTHROW(dispatcher->fly_shuttle(LosAngeles));

    dispatcher->take_card(Tokyo);
    dispatcher->build();
    dispatcher->drive(SanFrancisco);
    dispatcher->drive(LosAngeles);
    dispatcher->take_card(LosAngeles);
    dispatcher->build();
    CHECK_NOTHROW(scientist->fly_shuttle(LosAngeles));

    scientist->take_card(Tokyo);
    scientist->build();
    scientist->drive(SanFrancisco);
    scientist->drive(LosAngeles);
    scientist->take_card(LosAngeles);
    scientist->build();
    CHECK_NOTHROW(researcher->fly_shuttle(LosAngeles));

    researcher->take_card(Tokyo);
    researcher->build();
    researcher->drive(SanFrancisco);
    researcher->drive(LosAngeles);
    researcher->take_card(LosAngeles);
    researcher->build();
    CHECK_NOTHROW(medic->fly_shuttle(LosAngeles));

    medic->take_card(Tokyo);
    medic->build();
    medic->drive(SanFrancisco);
    medic->drive(LosAngeles);
    medic->take_card(LosAngeles);
    medic->build();
    CHECK_NOTHROW(virologist->fly_shuttle(LosAngeles));

    virologist->take_card(Tokyo);
    virologist->build();
    virologist->drive(SanFrancisco);
    virologist->drive(LosAngeles);
    virologist->take_card(LosAngeles);
    virologist->build();
    CHECK_NOTHROW(gene_splicer->fly_shuttle(LosAngeles));

    gene_splicer->take_card(Tokyo);
    gene_splicer->build();
    gene_splicer->drive(SanFrancisco);
    gene_splicer->drive(LosAngeles);
    gene_splicer->take_card(LosAngeles);
    gene_splicer->build();
    CHECK_NOTHROW(operations_expert->fly_shuttle(LosAngeles));

    field_doctor->take_card(Tokyo);
    field_doctor->build();
    field_doctor->drive(SanFrancisco);
    field_doctor->drive(LosAngeles);
    field_doctor->take_card(LosAngeles);
    field_doctor->build();
    CHECK_NOTHROW(dispatcher->fly_shuttle(LosAngeles));

    delete_init();
}

TEST_CASE("discover cure throw error")
{
    init();

    //field_doctor
    field_doctor->take_card(MexicoCity);
    field_doctor->take_card(Miami);
    field_doctor->take_card(Santiago);
    field_doctor->take_card(SaoPaulo);
    field_doctor->take_card(Lima);
    CHECK_THROWS(field_doctor->discover_cure(Yellow));  //there is no reaserch station
    field_doctor->take_card(Algiers);
    field_doctor->build();
    CHECK_THROWS(field_doctor->discover_cure(Red));  //not the right color
    CHECK_THROWS(field_doctor->discover_cure(Blue));  //not the right color
    CHECK_THROWS(field_doctor->discover_cure(Black));  //not the right color

    //operations_expert
    operations_expert->take_card(MexicoCity);
    operations_expert->take_card(Miami);
    operations_expert->take_card(Santiago);
    operations_expert->take_card(SaoPaulo);
    operations_expert->take_card(Lima);
    CHECK_THROWS(operations_expert->discover_cure(Yellow));  //there is no reaserch station
    operations_expert->build();  //dont need to taka a card to build
    CHECK_THROWS(operations_expert->discover_cure(Red));  //not the right color
    CHECK_THROWS(operations_expert->discover_cure(Blue));  //not the right color
    CHECK_THROWS(operations_expert->discover_cure(Black));  //not the right color

    //dispatcher
    dispatcher->take_card(MexicoCity);
    dispatcher->take_card(Miami);
    dispatcher->take_card(Santiago);
    dispatcher->take_card(SaoPaulo);
    dispatcher->take_card(Lima);
    CHECK_THROWS(dispatcher->discover_cure(Yellow));  //there is no reaserch station
    dispatcher->take_card(Algiers);
    dispatcher->build();
    CHECK_THROWS(dispatcher->discover_cure(Red));  //not the right color
    CHECK_THROWS(dispatcher->discover_cure(Blue));  //not the right color
    CHECK_THROWS(dispatcher->discover_cure(Black));  //not the right color

    //medic
    medic->take_card(MexicoCity);
    medic->take_card(Miami);
    medic->take_card(Santiago);
    medic->take_card(SaoPaulo);
    medic->take_card(Lima);
    CHECK_THROWS(medic->discover_cure(Yellow));  //there is no reaserch station
    medic->take_card(Algiers);
    medic->build();
    CHECK_THROWS(medic->discover_cure(Red));  //not the right color
    CHECK_THROWS(medic->discover_cure(Blue));  //not the right color
    CHECK_THROWS(medic->discover_cure(Black));  //not the right color

    //virologist
    virologist->take_card(MexicoCity);
    virologist->take_card(Miami);
    virologist->take_card(Santiago);
    virologist->take_card(SaoPaulo);
    virologist->take_card(Lima);
    CHECK_THROWS(virologist->discover_cure(Yellow));  //there is no reaserch station
    virologist->take_card(Algiers);
    virologist->build();
    CHECK_THROWS(virologist->discover_cure(Red));  //not the right color
    CHECK_THROWS(virologist->discover_cure(Blue));  //not the right color
    CHECK_THROWS(virologist->discover_cure(Black));  //not the right color

    //gene_splicer dont need the same color
    gene_splicer->take_card(MexicoCity);
    gene_splicer->take_card(Miami);
    gene_splicer->take_card(Santiago);
    gene_splicer->take_card(SaoPaulo);
    gene_splicer->take_card(Lima);
    CHECK_THROWS(gene_splicer->discover_cure(Yellow));  //there is no reaserch station

    //scientist needs maximum only 4 cards
    scientist->take_card(MexicoCity);
    scientist->take_card(Miami);
    scientist->take_card(Santiago);
    scientist->take_card(SaoPaulo);
    CHECK_THROWS(scientist->discover_cure(Yellow));  //there is no reaserch station
    scientist->take_card(Algiers);
    scientist->build();
    CHECK_THROWS(scientist->discover_cure(Red));  //not the right color
    CHECK_THROWS(scientist->discover_cure(Blue));  //not the right color
    CHECK_THROWS(scientist->discover_cure(Black));  //not the right color

    //researcher doesn't need a research station
    researcher->take_card(MexicoCity);
    researcher->take_card(Miami);
    researcher->take_card(Santiago);
    researcher->take_card(SaoPaulo);
    researcher->take_card(Lima);
    CHECK_THROWS(researcher->discover_cure(Red));  //not the right color
    CHECK_THROWS(researcher->discover_cure(Blue));  //not the right color
    CHECK_THROWS(researcher->discover_cure(Black));  //not the right color

    delete_init();
}
TEST_CASE("discover cure that doesn't throw error")
{
    init();

    //operations_expert
    operations_expert->take_card(MexicoCity);
    operations_expert->take_card(Miami);
    operations_expert->take_card(Santiago);
    operations_expert->take_card(SaoPaulo);
    operations_expert->take_card(Lima);
    operations_expert->take_card(Algiers);
    operations_expert->build();
    CHECK_NOTHROW(operations_expert->discover_cure(Yellow));

    //dispatcher
    dispatcher->take_card(Bangkok);
    dispatcher->take_card(HongKong);
    dispatcher->take_card(Tokyo);
    dispatcher->take_card(Seoul);
    dispatcher->take_card(Osaka);
    dispatcher->take_card(Algiers);
    dispatcher->build();
    CHECK_NOTHROW(dispatcher->discover_cure(Yellow));

    //scientist  need only 4 cards
    scientist->take_card(MexicoCity);
    scientist->take_card(Miami);
    scientist->take_card(Santiago);
    scientist->take_card(SaoPaulo);
    scientist->take_card(Algiers);
    scientist->build();
    CHECK_NOTHROW(scientist->discover_cure(Yellow));

    //researcher  doesn't need a research station 
    researcher->take_card(MexicoCity);
    researcher->take_card(Miami);
    researcher->take_card(Santiago);
    researcher->take_card(SaoPaulo);
    researcher->take_card(Lima);
    CHECK_NOTHROW(researcher->discover_cure(Yellow));

    //medic
    medic->take_card(MexicoCity);
    medic->take_card(Miami);
    medic->take_card(Santiago);
    medic->take_card(SaoPaulo);
    medic->take_card(Lima);
    medic->take_card(Algiers);
    medic->build();
    CHECK_NOTHROW(medic->discover_cure(Yellow));

    //virologist
    virologist->take_card(MexicoCity);
    virologist->take_card(Miami);
    virologist->take_card(Santiago);
    virologist->take_card(SaoPaulo);
    virologist->take_card(Lima);
    virologist->take_card(Algiers);
    virologist->build();
    CHECK_NOTHROW(virologist->discover_cure(Yellow));

    //gene_splicer  doesn't need to take cards with the same color
    gene_splicer->take_card(Seoul);
    gene_splicer->take_card(Paris);
    gene_splicer->take_card(Miami);
    gene_splicer->take_card(Moscow);
    gene_splicer->take_card(SanFrancisco);
    gene_splicer->take_card(Algiers);
    gene_splicer->build();
    CHECK_NOTHROW(gene_splicer->discover_cure(Yellow));

    //field_doctor
    field_doctor->take_card(MexicoCity);
    field_doctor->take_card(Miami);
    field_doctor->take_card(Santiago);
    field_doctor->take_card(SaoPaulo);
    field_doctor->take_card(Lima);
    field_doctor->take_card(Algiers);
    field_doctor->build();
    CHECK_NOTHROW(field_doctor->discover_cure(Yellow));

    delete_init();
}
TEST_CASE("treat throw error")
{
    init();  //treat lvl is 0
    
    CHECK_THROWS(operations_expert->treat(Algiers));
    CHECK_THROWS(dispatcher->treat(Algiers));
    CHECK_THROWS(scientist->treat(Algiers));
    CHECK_THROWS(researcher->treat(Algiers));
    CHECK_THROWS(medic->treat(Algiers));
    CHECK_THROWS(virologist->treat(Algiers));
    CHECK_THROWS(gene_splicer->treat(Algiers));
    CHECK_THROWS(field_doctor->treat(Algiers));

    virologist->take_card(Milan);
    CHECK_THROWS(virologist->treat(Milan));  //treat diffrent city 
    CHECK_THROWS(field_doctor->treat(Madrid));  //treat close city

    delete_init();   
}
TEST_CASE("treat that doesn't throw error")
{
    init(Miami);

    (*board)[Miami] = 9;
    CHECK_NOTHROW(researcher->treat(Miami));
    CHECK((*board)[Miami] == 8);
    CHECK_NOTHROW(gene_splicer->treat(Miami));
    CHECK((*board)[Miami] == 7);
    CHECK_NOTHROW(operations_expert->treat(Miami));
    CHECK((*board)[Miami] == 6);

    field_doctor->drive(Washington);
    CHECK_NOTHROW(field_doctor->treat(Miami));
    CHECK((*board)[Miami] == 5);

    virologist->take_card(Moscow);
    virologist->fly_direct(Moscow);
    virologist->take_card(Miami);
    CHECK_NOTHROW(virologist->treat(Miami));
    CHECK((*board)[Miami] == 4);
    
    CHECK_NOTHROW(medic->treat(Miami));
    CHECK((*board)[Miami] == 0);

    delete_init();
}
//player's role test
TEST_CASE("treat throw error")
{
    init();  



    delete_init();   
}
