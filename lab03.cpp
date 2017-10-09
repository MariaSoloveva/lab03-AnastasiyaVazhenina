#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <vector>

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);
    auto lambda = [&e2, &dist] () -> T { return dist(e2); };
    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main()
{
    // 1
    std::vector<double> v = generate_random_vector<double>(10, -10, 10);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        v[i] = v[i] * 2;
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Enter the number a" << std::endl;
    int a = 0;
    std::cin >> a;
    for (int i = 0; i < 10; ++i)
    {
        v[i] = v[i] - a;
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    double x = v[0];
    for (int i = 0; i < 10; ++i)
    {
        v[i] = (v[i] / x);
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    // 2
    std::vector<int> t = generate_random_vector<int>(10, 0, 10);
    for (int i =0; i < 10; ++i)
    {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
    int sum = 0;
    for (int i =0; i < 10; ++i)
    {
        sum += t[i];;
    }
    std::cout << sum << std::endl;
    int sum2 = 0;
    for (int i =0; i < 10; ++i)
    {
        sum2 += (t[i] * t[i]);
    }
    std::cout << sum2 << std::endl;
    int sum6 = 0;
    for (int i = 0; i < 6; ++i)
    {
        sum6 += t[i];
    }
    std::cout << sum6 << std::endl;
    int k1 = 0;
    int k2 = 0;
    std::cout << "Enter k1 and k2, k1 < k2" << std::endl;
    std::cin >> k1;
    std::cin >> k2;
    int amount = 0;
    for (int i = k1; i <= k2; ++i)
    {
        amount += t[i];
    }
    std::cout << amount << std::endl;
    int j = 0;
    int amout1 = 0;
    for (int i = 0; i < 10; ++i)
    {
        j += 1;
        amout1 += t[i];
    }
    std::cout << static_cast<double>(amout1) / j << std::endl;
    int s1 = 0;
    int s2 = 0;
    std::cout << "Enter s1 and s2, s1 < s2" << std::endl;
    std::cin >> s1;
    std::cin >> s2;
    int sumS = 0;
    int k = 0;
    for (int i = s1; i <= s2; ++i)
    {
        k += 1;
        sumS += t[i];
    }
    std::cout << static_cast<double>(sumS) / k << std::endl;
    // 3
    std::vector<int> g = generate_random_vector<int>(20, 0, 10);
    for (int i =0; i < 20; ++i)
    {
        std::cout << g[i] << " ";
    }
    std::cout << std::endl;
    int r = 0;
    r = g[0];
    g[0] = g[17];
    g[17] = r;
    r = g[1];
    g[1] = g[18];
    g[18] = r;
    r = g[2];
    g[2] = g[19];
    g[19] = r;
    for (int i = 0; i < 20; ++i)
    {
        std::cout << g[i] << " ";
    }
    std::cout << std::endl;
    // 4
    std::vector<int> w = generate_random_vector<int>(10, -10, 10);
    for (int i =0; i < w.size(); ++i)
    {
        std::cout << w[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < w.size(); ++i)
    {
        if (w[i] < 0)
        {
            w.erase(w.begin() + i);
            break;
        }
    }
    for (int i = 0; i < w.size(); ++i)
    {
        std::cout << w[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 9; i >= 0; --i)
    {
        if (w[i] % 2 == 0)
        {
            w.erase(w.begin() + i);
            break;
        }
    }
    for (int i = 0; i < w.size(); ++i)
    {
        std::cout << w[i] << " ";
    }
    std::cout << std::endl;
    // 5
    std::string str;
    std::cout << "Enter the name of the city" << std::endl;
    std::cin >> str;
    std::size_t length = str.size();
    if (length % 2 == 0)
    {
        std::cout << "An even number of characters" << std::endl;
    }
    else
    {
        std::cout << "Odd number of characters" << std::endl;
    }
    // 6
    std::string f1;
    std::string f2;
    std::cout << "Enter last names" << std::endl;
    std::cin >> f1;
    std::cin >> f2;
    std::size_t l1 = f1.size();
    std::size_t l2 = f2.size();
    if (l1 > l2)
    {
        std::cout << "First name is longer" << std::endl;
    }
    else if (l1 < l2)
    {
        std::cout << "Second name is longer" << std::endl;
    }
    else
    {
        std::cout << "The same" << std::endl;
    }
    // 7
    std::string g1;
    std::string g2;
    std::string g3;
    std::cout << "Enter the names of the cities" << std::endl;
    std::cin >> g1;
    std::cin >> g2;
    std::cin >> g3;
    std::size_t n1 = g1.size();
    std::size_t n2 = g2.size();
    std::size_t n3 = g3.size();
    if ((n1 > n2) && (n1 > n3))
    {
        if (n2 < n3)
        {
            std::cout << g1 << " " << g2 << std::endl;
        }
        else
        {
            std::cout << g1 << " " << g3 << std::endl;
        }
    }
    else if ((n2 > n1) && (n2 > n3))
    {
        if (n1 < n3)
        {
            std::cout << g2 << " " << g1 << std::endl;
        }
        else
        {
            std::cout << g2 << " " << g3 << std::endl;
        }
    }
    else if (n1 < n2)
    {
        std::cout << g3 << " " << g1 << std::endl;
    }
    else
    {
        std::cout << g3 << " " << g2 << std::endl;
    }
    // 8
    std::string p;
    std::cout << "Enter the word" << std::endl;
    std::cin >> p;
    int n = 0;
    int m = 0;
    std::cout << "Enter m and n, m < n" << std::endl;
    std::cin >> m;
    std::cin >> n;
    std::cout << p.substr(m, n) << std::endl;
    // 9
    std::string b;
    std::cout << "Enter the word" << std::endl;
    std::cin >> b;
    char s[b.length()];
    for (int i = 0; i < b.length(); ++i)
    {
        s[i]='*';
    }
    std::string result;
    std::string symbol;
    symbol = s;
    result = symbol + b + symbol;
    std::cout << result << std::endl;
    // 10
    std::string phrase;
    std::cout << "Enter the sentence" << std::endl;
    std::cin >> phrase;
    std::size_t l = phrase.size();
    int q = 0;
    for (int i = 0; i < phrase.length(); ++i)
    {
        if (phrase[i] == 'a')
        {
            q += 1;
        }
    }
    std::cout << (static_cast<float>(q) / l) * 100 << "%" << std::endl;
    // 11
    std::string y = "Can you can a can as a canner can can a can?";
    std::string c = " ";
    std::cout << "Enter the sentence" << std::endl;
    std::cin >> c;
    while (y.find("can") != std::string::npos)
    {
        size_t index = y.find("can");
        y.replace(index + 1, 3, c);
    }
    std::cout << y << std::endl;
    return 0;
}
