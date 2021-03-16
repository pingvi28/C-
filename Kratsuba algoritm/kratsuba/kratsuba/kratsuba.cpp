#include <iostream>
#include <vector>
using namespace std;

void intToVec(int n, vector<int>& v);
int vecToInt(const vector<int>& v);
void need_size(vector<int>& v1, vector<int>& v2);

int base = 10;

vector<int> karatsuba_algorithm(const vector<int>& fir, const vector<int>& sec) {
    /* &-ссылочная передача; Если передать вектор целиком, то его скопирует программа(каждый элемент), а ссылкой
    передается образ вектора прямо в функций, за счет чего, все происходит куда быстрее */
    int len = fir.size();  // int or long
    vector<int> v3;
    auto res = 0;

    if (len == 1) {
        res = fir[0] * sec[0];
    }
    else {
        vector<int> fir_left;
        vector<int> fir_rig;
        fir_left.insert(fir_left.begin(), fir.begin(), fir.begin() + len / 2);
        fir_rig.insert(fir_rig.begin(), fir.begin() + len / 2, fir.end());
        if (fir_left.size() > 2)
            need_size(fir_left, fir_rig);

        vector<int> sec_left;
        vector<int> sec_rig;
        sec_left.insert(sec_left.begin(), sec.begin(), sec.begin() + len / 2);
        sec_rig.insert(sec_rig.begin(), sec.begin() + len / 2, sec.end());
        if (sec_left.size() > 2)
            need_size(sec_left, sec_rig);

        //ac + ad + bc+ bd == ( ab + cd ) == (a + b)(c + d) -ac - bd;


        vector<int> AC = karatsuba_algorithm(fir_left, sec_left);
        vector<int> BD = karatsuba_algorithm(fir_rig, sec_rig);
        vector<int> AD = karatsuba_algorithm(fir_left, sec_rig);
        vector<int> BC = karatsuba_algorithm(fir_rig, sec_left);

        res = vecToInt(AC) * (long)pow(10, len) + ((long)vecToInt(AD) + (long)vecToInt(BC))
            * (long)pow(10, len / 2) + vecToInt(BD);
    }

    intToVec(res, v3);
    return v3;
}

void need_size(vector<int>& v1, vector<int>& v2) {
    int n = max(v1.size(), v2.size());

    if (n % 2 == 1)
        n++;
    v1.resize(n);
    v2.resize(n);
}

void intToVec(int n, vector<int>& v) {
    int nLess10 = 0;

    while (n > 0) {
        nLess10 = n % 10;
        v.insert(v.begin(), nLess10);
        n = n / 10;
    }
}

int vecToInt(const vector<int>& v) {
    int res = 0;

    for (int i = 0; i < (int)v.size(); i++) {
        res += v[i] * ((long)pow(10, (int)v.size() - i - 1));
    }

    return res;
}


int main()
{
    vector <int> first_num, second_num;
    int num1, num2;

    cout << "Enter 2 positive numbers" << endl;
    cin >> num1 >> num2;

    intToVec(num1, first_num);
    intToVec(num2, second_num);
    need_size(first_num, second_num);

    vector <int> final_composition = karatsuba_algorithm(first_num, second_num);

    cout << "final_composition: ";
    for (int i = 0; i < final_composition.size(); i++) {
        cout << final_composition[i] << " ";
    }

    return 0;
}
