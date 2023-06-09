// Assignment solution


#include<bits/stdc++.h>

using namespace std;

vector<int> findMaxNetworkQuality(vector<vector<int>>& towers, int radius) {
    int maxQuality;
    vector<int> maxCoord;
    vector<int> maxLexicoCoord;

    for (int x = 0; x <= radius; x++) {
        for (int y = 0; y <= radius; y++) {
            int networkQuality = 0;

            for (const auto& tower : towers) {
                int xi = tower[0];
                int yi = tower[1];
                int qi = tower[2];
                double d = sqrt(pow(xi - x, 2) + pow(yi - y, 2));

                if (d <= radius) {
                    int signalQuality = floor(qi / (1 + d));
                    networkQuality += signalQuality;
                }
            }

            if (networkQuality > maxQuality) {
                maxQuality = networkQuality;
                maxCoord = {x, y};
                maxLexicoCoord.clear();
            } else if (networkQuality == maxQuality && maxLexicoCoord.empty()) {
                maxLexicoCoord = {x, y};
            }
        }
    }

    if (!maxLexicoCoord.empty()) {
        return maxLexicoCoord;
    } else {
        return maxCoord;
    }
}

int main() {
    vector<vector<int>> towers = 
    {
        {1, 2, 5},
        {2, 9, 7},
        {3, 1, 9}
    };
   
    int radius = 2;

    vector<int> maxNetworkQualityCoord = findMaxNetworkQuality(towers, radius);

    cout << "Coordinate with maximum network quality: (" << maxNetworkQualityCoord[0]
         << ", " << maxNetworkQualityCoord[1] << ")" << endl;

    return 0;
}


// INPUT
// [{1, 2, 5} , {2, 9, 7} , {3, 1, 9}]

 // OUTPUT
 // [2,1]
