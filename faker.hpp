#pragma once

#include <string>
#include <vector>
#include <random>

#include <string.hpp>

namespace uva
{
    namespace faker
    {
        //returns an double in the range of min (inclusive) and max (exclusive)
        double random_double(double min, double max);

        //returns an integer in the range of min (inclusive) and max (exclusive)
        int random_integer(int min, int max);

        template<typename T>
        T pick_one(const std::vector<T>& from)
        {
            int random_index = random_integer(0, from.size());
            return from[random_index];
        }

        namespace sequence
        {
            template<typename T>
            std::vector<T> from_to(const T& from, const T& to)
            {
                std::vector<T> seq;
                for(T index = from; index < to; ++index)
                {
                    seq.push_back(index);
                }
                return seq;
            }
        };

        namespace commerce
        {
            std::string product();
            double price(double min = 0.0, double max = 100.0);
        };

        namespace lorem
        {
            std::string word();
            std::string sentence_begin();
            std::string sentence_end();
            std::string sentence(int min_words = 4, int max_words = 10);
            std::string paragraph(int setences = 1);
        };
    };
};