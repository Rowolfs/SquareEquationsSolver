#pragma once
#include <vector>
#include <cmath>
#include <string>
#include "..\ErrorHandler\exceptions.hpp"
#include "..\ErrorHandler\LogController.h"


namespace solverMethods
{
    bool isInt(float num);

    class SolverMethod
    {
    public:
        explicit SolverMethod() = default;
        virtual ~SolverMethod() = default;
        std::string title;
        virtual std::vector<float> execute(const std::vector<float>& value) = 0;
    };

    class Discriminant : public SolverMethod
    {
    public:
        Discriminant(): SolverMethod() { title = "Discremenant"; }

        std::vector<float> execute(const std::vector<float>& value) override;
    };

    class Vieta : public SolverMethod
    {
    public:
        Vieta() : SolverMethod() { title = "Vieta only int"; }

        std::vector<float> execute(const std::vector<float>& value) override;
    };

    class Gorner : public SolverMethod
    {
    public:
        Gorner() : SolverMethod() { title = "Gorner only int"; }

        std::vector<float> execute(const std::vector<float>& value) override;
    };

    class Exit : public SolverMethod
    {
    public:
        Exit() : SolverMethod() { title = "Exit program"; }

        std::vector<float> execute(const std::vector<float>& value) override
        {
            LogController::end();
            exit(0);
        }
    };
}
