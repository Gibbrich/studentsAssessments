//
// Created by Игорь on 06.04.2018.
//

#ifndef STUDENTSASSESSMENTS_STUDENTINFO_H
#define STUDENTSASSESSMENTS_STUDENTINFO_H

#include <string>
#include <vector>

struct StudentInfo
{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homeworks;
};

double grade(const StudentInfo& info);
std::istream& read(std::istream& is, StudentInfo& info);
bool compare(const StudentInfo& first, const StudentInfo& second);


#endif //STUDENTSASSESSMENTS_STUDENTINFO_H
