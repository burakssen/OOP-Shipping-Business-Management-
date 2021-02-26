/*
 * Name : Burak Şen
 * Id: 150170063
 */
#include <iostream>
#include "Owner.h"
#include "Courier.h"
#include "Business.h"
#include "OwnerList.h"

using namespace std;

int main()
{
    OwnerList ol1;
    Owner o1("burak", "sen");
    Owner o2("merve", "sen");
    Owner o3("ali", "sen");
    Owner o4("mahmut", "sen");

    //ol1.addOwner(o4);

    Business atlas("Atlas", "Maslak Istanbul/Turkey", ol1, ol1.getOwnerNum());
    Courier c1("mahmut", "art", "car");
    Courier c2("ali", "mat", "bicycle");
    Courier c3("faruk", "mah", "motorcycle");
    Courier c4("elif", "mad", "car");
    Courier c5("ali", "maet", "car");

    atlas.hire_courier(c1);
    atlas.hire_courier(c2);
    //atlas.hire_courier(c3);
    //atlas.hire_courier(c4);
    atlas.fire_courier(c1);
    //atlas.list_owners();

    atlas();

    cout << endl;
    Courier *cour = atlas[0];
    cour->printCourier();
    return 0;
}