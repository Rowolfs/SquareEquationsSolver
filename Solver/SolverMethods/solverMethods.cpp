#include "solverMethods.h"

bool solverMethods::isInt(float num)
{
    float temp = round(num);
    return round(num) == num;
}



std::vector<float> solverMethods::Discriminant::execute(const std::vector<float>& value)
{
    LogController::LOG("Discriminant solver init");
    if (value.size() != 3)
        throw IncorrectCoefficents(
            "Number of coefficients is not supporting by this solve method (support 3 coefficients)");


    float a = value[0];
    float b = value[1];
    float c = value[2];

    const float discriminant = b * b - 4 * a * c;
    std::vector<float> answer;
    if (discriminant > 0)
    {
        answer.push_back((-b - sqrt(discriminant)) / (2 * a));
        answer.push_back((-b + sqrt(discriminant)) / (2 * a));
    }
    else if (discriminant == 0)
    {
        answer.push_back(-b / (2 * a));
    }
    else
    {
        throw IncorrectCoefficents("With this coefficients discriminant is negate");
    }


    return answer;
}

std::vector<float> solverMethods::Vieta::execute(const std::vector<float>& value)
{
    LogController::LOG("Vieta solver init");
    if (value.size() != 3)
        throw IncorrectCoefficents(
            "Number of coefficients is not supporting by this solve method (support 3 coefficients)");

    float a = value[0];
    float b = value[1];
    float c = value[2];

    if (!isInt(a) || !isInt(b) || !isInt(c))
        throw IncorrectCoefficents("Coefficients is not int");

    std::vector<float> answer;


    if (a != 1)
        throw IncorrectCoefficents("First coefficient is not 1 (not supporting by Vieta)");

    for (float x1 = -1000; x1 < 1000; ++x1)
    {
        for (float x2 = -1000; x2 < 1000; ++x2)
        {
            if ((x1 + x2) == -b && (x1 * x2) == c)
            {
                answer.push_back(x1);
                answer.push_back(x2);
                return answer;
            }
        }
    }

    if (answer.empty())
        throw IncorrectCoefficents(
            "Your answer less -1000 or more 1000 or you typed incorrect coefficients for Vieta");

    return answer;
}

std::vector<float> solverMethods::Gorner::execute(const std::vector<float>& value)
{
    LogController::LOG("Gorner solver init");
    if (value.size() <= 1)
        throw IncorrectCoefficents(
            "Number of coefficients is not supporting by this solve method (support 2 and more coefficients)");
    for (auto element : value)
    {
        if (!isInt(element))
            throw IncorrectCoefficents("Coefficients is not int");
    }
    std::vector<float> answer;
    std::vector<float> coffs(value.size());
    std::copy(value.begin(), value.end(), coffs.begin());
    for (int count = 0; count < value.size() - 1; ++count)
    {
        for (float i = -1000; i < 1000; ++i)
        {
            std::vector<float> new_coffs;
            new_coffs.push_back(coffs[0]);
            for (int j = 1; j < coffs.size(); ++j)
            {
                float coff = coffs[j] + new_coffs[j - 1] * i;
                new_coffs.push_back(coff);
            }
            if (new_coffs.back() == 0)
            {
                answer.push_back(i);
                coffs.clear();
                for (int j = 0; j < new_coffs.size() - 1; ++j)
                {
                    coffs.push_back(new_coffs[j]);
                }
                break;
            }
        }
    }

    if (answer.empty())
        throw IncorrectCoefficents(
            "Your answer less -1000 or more 1000 or you typed incorrect coefficients for Gorner");
    return answer;
}
