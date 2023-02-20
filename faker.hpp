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

        namespace number
        {
            /// @brief Generates an random integer
            /// @return An integer between std::numeric_limits<int>::min() and std::numeric_limits<int>::max ();
            int integer();
            /// @brief Generates an random real
            /// @return An double between std::numeric_limits<double>::min() and std::numeric_limits<double>::max ();
            double real();
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

        namespace array
        {
            /// @brief Generates an array with random values
            /// @tparam T value type
            /// @param n number of elements
            /// @return A std::vector<T> with n elements
            template<typename T>
            std::vector<T> random(int n)
            {
                std::vector<T> array;
                array.reserve(n);

                for(size_t i = 0; i < n; ++i)
                {
                    if constexpr(std::is_same<T,int>::value)
                    {
                        array.push_back(number::integer());
                    } else if (std::is_same<T,double>::value || std::is_same<T,float>::value) {
                        array.push_back(number::real());
                    } else {
                        throw std::exception(std::format("random is not implemented for {}", typeid(T).name()));
                    }
                }

                return array;
            }
            /// @brief Generates an array with ascending values
            /// @tparam T value type
            /// @param from The first value
            /// @param to The last value
            /// @return A std::vector<T> with from, ..., to
            template<typename T>
            std::vector<T> ascending(const T& from, const T& to)
            {
                std::vector<T> seq;
                for(T index = from; index != to; ++index)
                {
                    seq.push_back(index);
                }
                return seq;
            }
        };
    };
};