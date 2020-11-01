#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> optimal_sequence(int number) {

    vector<int32_t> min_steps(number + 1);
    vector<int32_t> predecessor(number + 1);

    for (int32_t i = 2; i <= number; i++)
    {
        min_steps[i] = min_steps[i - 1] + 1;
        predecessor[i] = i - 1;

        if (i % 3 == 0)
        {
            if (min_steps[i / 3] < min_steps[i])
            {
                min_steps[i] = min_steps[i / 3] + 1;
                predecessor[i] = i / 3;
            }
        }

        if (i % 2 == 0)
        {
            if (min_steps[i / 2] < min_steps[i])
            {
                min_steps[i] = min_steps[i / 2] + 1;
                predecessor[i] = i / 2;
            }
        }
    }

    vector<int> s;
    s.reserve(predecessor.size());

    for (int32_t i = number; i != 0; i = predecessor[i])
    {
        s.push_back(i);
    }

    reverse(s.begin(), s.end());

    return std::move(s);
       

}

int main() {
    int number;
    cin >> number;
  vector<int> sequence = optimal_sequence(number);

  cout << sequence.size() - 1 << std::endl;

  for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
  }

  system("pause");
}
