//
// Created by Игорь on 06.04.2018.
//

#include <iostream>
#include "StudentInfo.h"
#include "main.h"

std::istream& read(std::istream& is, StudentInfo& info)
{
    std::cout << "Enter student name: \n";
    is >> info.name;

    std::cout << "Enter exam grades in the middle of the semester: \n";
    is >> info.midterm;

    std::cout << "Enter exam grades in the end of the semester: \n";
    is >> info.final;

    readHomeWork(is, info.homeworks);

    return is;
}

double grade(const StudentInfo& info)
{
    return grade(info.midterm, info.final, info.homeworks);
}

bool compare(const StudentInfo& first, const StudentInfo& second)
{
    return first.name < second.name;
}
