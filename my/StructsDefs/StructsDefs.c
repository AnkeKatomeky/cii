// typedef struct // type definition same as struct usually and all definitions must be placed above using it
// {
//     char *Name;
//     int Cost:5; // here appears bit feild magic. We cam define length in bits. Here Int instead of 4 bytes have size of 5 bit
// } Car; // but name of definition at the end

// union UnionStruct //unions works in a same way as structs but it have zero shifted felids
// {
//     int digit; //it' means what digit and latter placed in same memory cells
//     char letter; // main purpose is for defining primitive type as multi type
// }; // example have several primitive types at once without extra casting

void DoSomethingWhitStructs(int value)
{
    struct Car Lada = {"Lada Kalina", 10000}; // typedef variable can omit struct keyword
    struct Car Honda = {"Honda Civic", 2000520};

    struct Person Dummy = {"Dummy", 2}; // variable of struct and initialisation of that struct
    struct Person Ward = {"Ward", 1};   // variable of struct and initialisation of that struct
    Dummy.Age = 100;                    // applying to struct feild
    Dummy.Name = "Dummy Dummy";

    struct Person *Mike = CreatePerson("Mike Pondsmit", 21, &Lada);
    struct Person *Rob = CreatePerson("Rob Zombe", 21, &Honda);
    struct Person *Carl = CreatePerson("Carl The Invoker", 21, NULL);

    struct Person Dummys[] = {Dummy, Ward, "Flask", 18}; // array of stuct. Magic in this what we can add extra as plain data
    struct Person *AllPersons[] = {Mike, Rob, Carl};

    printf("\nRob Person\n");
    // to remind how to acces plane struct
    // printf("Name: %s \tAge %d\t", Rob.Name, Rob.Age);
    // printf("And Owns Car\tName: %s\t Age %d\n", Rob.OwnedCar->Name, Rob.OwnedCar->Cost); // here how acces to pointer inside struct
    PrintPerson(Rob);

    printf("\nExisted Persons\n");
    for (int i = 0; i < sizeof(AllPersons) / sizeof(struct Person *); i++)
    {
        PrintPerson(AllPersons[i]);
        // to remind hot to acces struct in arrays
        // printf("Name: %s\tAge %d\t", AllPeople[i].Name, AllPeople[i].Age);
        // printf("And Owns Car\tName: %s\t Age %d\n", AllPeople[i].OwnedCar->Name, AllPeople[i].OwnedCar->Cost);
    }
    printf("\nForeach sample\n");
    // it's for cycle works in same way as foreach in other languages
    for (struct Person **item = AllPersons; item < AllPersons + sizeof(AllPersons) / sizeof(struct Person *); item++)
    {
        PrintPerson(*item);
        // to remind how to acces struct in pointer
        // printf("Name: %s\tAge %d\t", item->Name, item->Age);
        // printf("And Owns Car\tName: %s\t Age %d\n", item->OwnedCar->Name, item->OwnedCar->Cost);
    }

    printf("\nSelected Person\n");
    // pointer and struct shenanigans
    struct Person *SelectedPerson = Mike; // same as primitive variable
    PrintPerson(SelectedPerson);          // pass struct pointer as param
    // to remind how to acces struct in plane pointer
    // printf("Name: %s \tAge %d\t", (*SelectedPerson).Name, (*SelectedPerson).Age);                                // to acces the struct we must unpack pointer
    // printf("And Owns Car\tName: %s\t Age %d\n", SelectedPerson->OwnedCar->Name, SelectedPerson->OwnedCar->Cost); // or use specific operator ->
    free(Mike);
    free(Rob);
    free(Carl);
}

struct Person *CreatePerson(char *name, int age, struct Car *ownedCar) // returning a struct(currently pointer in heap to struct aka object)
{
    struct Person *createdPerson = calloc(1, sizeof(struct Person)); // allocating heap in size of person struct
    createdPerson->Age = age;                                        // pulling data into struct pointer
    createdPerson->Name = name;
    createdPerson->OwnedCar = ownedCar;
    return createdPerson;
}

void PrintPerson(struct Person *person) // putting struct as param (if it is not pointer it passed as copy)
{
    printf("Name: %s\tAge %d\t", person->Name, person->Age); // accessing data in pointer struct
    if (person->OwnedCar == NULL)
    {
        printf("And don't owns Car\n");
        return;
    }

    printf("And Owns Car\tName: %s\t Age %d\n", person->OwnedCar->Name, person->OwnedCar->Cost);
}