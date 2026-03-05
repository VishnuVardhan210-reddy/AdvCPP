#include<iostream>
#include<tuple>

std::tuple<int, int, int> getScores()
{
    return {85, 90, 95};
}
int main()
{
    auto [xa, xb, xc] = getScores();
}