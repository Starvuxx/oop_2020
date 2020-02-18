#include <algorithm>
#include <fstream>
#include <iostream>

struct Stud
{
    int id{0};
    char name[30]{};
};

void print_stud(const Stud& student)
{
    std::cout << student.id << ": " << student.name << '\n';
}

void print_students(Stud * first, Stud * last)
{
    std::for_each(first, last,
                  [](const Stud& student){ print_stud(student); });
}

void sort_students(Stud * first, Stud * last)
{
    std::sort(first, last,
              [](const Stud& lhs, const Stud& rhs) { return lhs.id < rhs.id; });
}

int main()
{
    Stud students[]{
        { 3, "Pe6o Pe6ov" },
        { 1, "Go6o Go6ov" },
        { 0, "Spartak Spartakov" },
        { 2, "Firstname Lastname" }
    };

    print_students(std::begin(students), std::end(students));
    std::cout << '\n';

    sort_students(std::begin(students), std::end(students));
    print_students(std::begin(students), std::end(students));
    std::cout << '\n';

    return 0;
}
