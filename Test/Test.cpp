// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <primal-path-following.h>
#include "problems.h"

namespace InteriorPointMethod
{
    void check_problems(const char* json_file)
    {
        int count = 0;
        IPM ipm;
        POINT x;
        VECTOR_VALUE summes;

        std::ifstream f("problems_goal_01-16-2023_03-38-09.json");
        json data = json::parse(f);
        for (int i = 0; i < 250; i++)
        {
            ipm = goal_problem(data, i);
            /*std::cout << "A\n";
            Matrix(ipm.A).show();
            std::cout << "b\n";
            Matrix(ipm.b).show();
            std::cout << "c\n";
            Matrix(ipm.c).show();
            std::cout << "\n";*/
            //ipm = positive_goal_problem(ipm);
            x = PrimalPathFollowing(ipm, false).calculate(false);
            summes.resize(0);
            for (int j = 0; j < ipm.b.size() - ipm.c.size(); j++)
            {
                if (ipm.b[j] == 0) break;
                summes.push_back(0);
                for (int k = 0; k < x.size(); k++)
                {
                    summes[j] += ipm.A[j][k] * x[k];
                }
                if (abs(summes[j] - ipm.b[j]) > 0.01)
                {
                    count++;
                    std::cout << "i " << i << "\n";
                    //Matrix(m_x).show();
                    for (int k = 0; k <= j; k++)
                    {
                        std::cout << summes[k] << " ";
                    }
                    std::cout << "\n";

                    for (int k = 0; k < ipm.b.size() - ipm.c.size(); k++)
                    {
                        std::cout << ipm.b[k] << " ";
                    }
                    std::cout << "\n";
                    std::cout << "\n";
                    break;
                }
            }
        }

        std::cout << "count " << count << "\n";

        std::cout << "stop";
    }
}

int main()
{
    const char* json_file = "problems_goal_01-16-2023_03-38-09";
    InteriorPointMethod::check_problems(json_file);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
