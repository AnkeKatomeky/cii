struct Car
{
    char *Name;
    int Cost;
};

struct Person // struct definition. Name of struct can be omitted if after are implemented variable of that struct
{
    char *Name;
    int Age;
    struct Car *OwnedCar;
};

void DoSomethingWhitStructs(int value);
struct Person *CreatePerson(char *name, int age, struct Car *ownedCar);
void PrintPerson(struct Person *person);