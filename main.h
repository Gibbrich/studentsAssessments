//
// Created by Игорь on 06.04.2018.
//

#ifndef STUDENTSASSESSMENTS_MAIN_H
#define STUDENTSASSESSMENTS_MAIN_H

double median(std::vector<double> vec);
double grade(const double midterm, const double final, const std::vector<double> &homeworks);
std::istream& readHomeWork(std::istream& in, std::vector<double>& homeworks);

#endif //STUDENTSASSESSMENTS_MAIN_H
