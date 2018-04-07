#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "main.h"
#include "StudentInfo.h"

int main()
{
    std::vector<StudentInfo> students;
    StudentInfo record;
    std::string::size_type longestName = 0;

    while (read(std::cin, record))
    {
        longestName = std::max(longestName, record.name.size());
        students.push_back(record);
    }

    std::sort(students.begin(), students.end(), compare);

    for (auto&& student : students)
    {
        std::cout << student.name << std::string(longestName + 1 - student.name.size(), ' ');

        try
        {
            double finalGrade = grade(student);

            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3)
                      << finalGrade << std::setprecision(prec) << std::endl;
        }
        catch (std::domain_error e)
        {
            std::cout << e.what();
        }
        std::cout << std::endl;
    }

    return 0;
}

double median(std::vector<double> vec)
{
    auto homeworkSize = vec.size();

    if (homeworkSize == 0)
    {
        throw std::domain_error("Empty vector");
    }

    std::sort(vec.begin(), vec.end());

    auto midId = homeworkSize / 2;
    double median;
    if (homeworkSize % 2 == 0)
    {
        median = vec[midId] + vec[midId - 1];
    }
    else
    {
        median = vec[midId];
    }

    return median;
}

double grade(const double midterm, const double final, const std::vector<double>& homeworks)
{
    if (homeworks.size() == 0)
    {
        throw std::domain_error("Student didn't prepare any homework!");
    }

    return 0.2 * midterm + 0.4 * final + 0.4 * median(homeworks);
}

std::istream& readHomeWork(std::istream& in, std::vector<double>& homeworks)
{
    if (in)
    {
        std::cout << "Enter all grades for homework:\n";

        double grade;
        while (in >> grade)
        {
            homeworks.push_back(grade);
        }
        in.clear();
    }
    return in;
}
