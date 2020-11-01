#include <iostream>
#include <vector>

using vector;
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops, int n) {


    int current_pos = 0;
    int refill_cnt = 0;
    size_t i = 0;
    size_t next_stop_i = 0;

    while (1)
    {
        if (dist - current_pos <= tank)
        {
            current_pos = dist;
            break;
        }

        for (; i < stops.size(); i++)
        {
            if (stops.at(i) - current_pos <= tank)
            {
                next_stop_i = i;
            }

            else 
                break;
            
        }
        
        current_pos = stops.at(next_stop_i);
        refill_cnt++;

        if (next_stop_i == stops.size() - 1) 
        {

            if ((dist - current_pos) > tank)
                break;
            
        }

        else 
        {
            
                if (stops.at(next_stop_i + 1) - current_pos > tank) 
                    break;
            
        }
    }

   
    if (current_pos == dist) 
    
        return refill_cnt;
    
    else 
        return -1;
    
}

  



int main() {
    int d = 0, m = 0, n = 0;
    cin >> d >> m >> n;

    vector<int> stops(n);

    for (size_t i = 0; i < n; ++i)
    {
        cin >> stops.at(i);
    }

    cout << compute_min_refills(d, m, stops,n) << "\n";

    system("pause");
 
}
