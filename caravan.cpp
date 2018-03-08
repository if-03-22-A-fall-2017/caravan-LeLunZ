
#include "pack_animal.h"
#include "general.h"


/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description: Hi this is just for fun
 * <your description here>
 *-----------------------------------------------------------------------------
*/
struct Node{
    struct Node* before;
    PackAnimal animal;
    struct Node* next;
};
struct CaravanImplementation{
    struct Node* begin;
    int length;
    struct Node* end;
    int speed;
    int load;
};
Caravan new_caravan()
{
    Caravan x = (Caravan) malloc(sizeof(CaravanImplementation));
    x->length = 0;
    x->end = 0;
    x->begin = 0;
    x->speed = 999;
    x->load = 0;
    return x;
}
int get_length(Caravan caravan)
{
    return caravan->length;
}
void delete_caravan(Caravan caravan){
    if(caravan->begin == 0){
        sfree(caravan);
        return;
    }
    Node *test = caravan->end;
    if(caravan->end->before == 0){
        caravan->end = 0;
        caravan->begin = 0;
        test->next = 0;
        test->before = 0;
        test->animal = 0;
        sfree(test);
        sfree(caravan);
        test = 0;
        return;
    }
    caravan->end = caravan->end->before;
    if(test->next == caravan->end->before)caravan->begin = caravan->end;
    test->next = 0;
    test->before = 0;
    test->animal = 0;
    sfree(test);
    test = 0;
    return delete_caravan(caravan);
}
void add_pack_animal(Caravan caravan, PackAnimal animal)
{
    if(animal == 0 || get_caravan(animal) == caravan)return;
    if(get_caravan(animal) != 0){
        Caravan ca = get_caravan(animal);
        ca->length--;
    }
    caravan->load += get_load(animal);
    caravan->speed =get_actual_speed(animal) < caravan->speed ? get_actual_speed(animal):caravan->speed;
    Node *x = (Node*) malloc(sizeof(Node));
    caravan->length++;
    x->next = 0;
    x->before = caravan->end;
    if(caravan->end != 0)
        caravan->end->next = x;
    else
        caravan->end = x;
    if(caravan->begin == 0)caravan->begin = x;
    caravan->end = x;
    x->animal = animal;
    add_to_caravan(animal, caravan);
}
void remove_pack_animal(Caravan caravan, PackAnimal animal, struct Node* test= 0)
{
    if(get_caravan(animal) != caravan || animal == 0 || caravan == 0 || caravan->begin == 0)return;
    if(caravan->begin->animal == animal || (test != 0 && test->animal == animal)) {
        Node *now = test== 0? caravan->begin: test;
        if(now->before == 0){
            caravan->begin = now->next == 0?0:now->next;
            if(caravan->begin != 0) caravan->begin->before = 0;
        }
        else {
            Node* before = now->before;
            before->next = now->next;
            if(caravan->end == now) caravan->end = before;
        }
        caravan->load -= get_load(now->animal);
        caravan->length--;
        remove_from_caravan(now->animal, caravan);
        now->animal = 0;
        now->next = 0;
        now->before = 0;
        sfree(now);
        now = 0;
        return;
    }
    if(test != 0 && test->next == 0)return;
    remove_pack_animal(caravan,animal,test==0?caravan->begin:test->next);
}
int get_caravan_load(Caravan caravan)
{
    return caravan->load;
}
void unload(Caravan caravan, struct Node* now = 0)
{
    Node* beg = now == 0?caravan->begin:now->next;
    caravan->load -= get_load(beg->animal);
    unload(beg->animal);
    return caravan->end == beg? (void)0:unload(caravan, beg);
}
int get_caravan_speed(Caravan caravan,struct Node* now = 0)
{
    Node* beg = now == 0? caravan->begin:now->next;
    if(caravan->speed> get_actual_speed(beg->animal))caravan->speed = get_actual_speed(beg->animal);
    if(now != 0 && beg->next == 0)return caravan->speed;
    return get_caravan_speed(caravan,beg);
}

void optimize_load(Caravan caravan){

    return;
}